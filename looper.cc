#include "looper.hh"

Looper::Looper()
{
  
  playbackIndex = 0;
  
  client = jack_client_open("Jack MIDI Loop", JackNullOption, NULL);
  
  inputPort = jack_port_register(client, "midi_in", MIDI_TYPE, JackPortIsInput, 0);
  inputTriggerPort = jack_port_register(client, "midi_trigger_in", MIDI_TYPE, JackPortIsInput, 0);
  outputPort = jack_port_register(client, "midi_out", MIDI_TYPE, JackPortIsOutput, 0);

  jack_set_process_callback(client, staticProcess, static_cast<void*>(this));
  
  jack_on_shutdown(client, Looper::jack_shutdown, 0);
  

  this->activate();
  
}

void Looper::activate()
{
  if (jack_activate(client) != 0) {
    throw std::runtime_error("Jack client activation failed.");
    return;
  }
}

void Looper::jack_shutdown(void *arg)
{
  std::cout << "Jack exit." << std::endl;
  exit(1);
}

int Looper::staticProcess(jack_nframes_t nframes, void *arg)
{
  return static_cast<Looper*>(arg)->process(nframes);
}

int Looper::process(jack_nframes_t nframes)
{
  
  // jack_nframes_t event_index = 0;

  void* port_buffer = jack_port_get_buffer(inputPort, nframes);
  void* port_trigger_buffer = jack_port_get_buffer(inputTriggerPort, nframes);
  void* outputPortBuf = jack_port_get_buffer(outputPort, nframes);
  
  jack_midi_clear_buffer(outputPortBuf);
  
  transport = jack_transport_query(client, &position);
  // std::cout << transport << std::endl;
  
  jack_nframes_t event_count = jack_midi_get_event_count(port_buffer);
  jack_nframes_t event_trigger_count = jack_midi_get_event_count(port_trigger_buffer);
  
  
  if (event_count > 0) {
    for (int i = 0; i < event_count; i++) {
      jack_midi_event_get(&in_event, port_buffer, i);
      
      std::cout << "Frame " << position.frame << "  Event: " << i << " SubFrame#: " << in_event.time << " \tMessage:\t"
                << (long)in_event.buffer[0] << "\t" << (long)in_event.buffer[1]
                << "\t" << (long)in_event.buffer[2] << std::endl;  // NOT realtime...
                
      msg = std::to_string((long)in_event.buffer[0]) + "\t" + std::to_string((long)in_event.buffer[1]) + "\t" + std::to_string((long)in_event.buffer[2]) + "\n";
      
      iter = m_refTextBuffer->get_iter_at_offset(m_refTextBuffer->get_char_count());
      m_refTextBuffer->insert(iter, msg);
    }
  }
  
  if (event_trigger_count) {
    jack_midi_event_get(&in_trigger_event, port_trigger_buffer, 0);
    
    std::cout << "Frame " << position.frame << "  Event: "  << " SubFrame#: " << in_trigger_event.time << " \tMessage:\t"
              << (long)in_trigger_event.buffer[0] << "\t" << (long)in_trigger_event.buffer[1]
              << "\t" << (long)in_trigger_event.buffer[2] << std::endl;

    loop();
  }
  
  
  if (islooping) {
    update_progress_bar();
  }
  

  return 0;
  
}

Looper::~Looper()
{
  // noop
}

void Looper::clear_buffer()
{
  m_refTextBuffer->set_text("");
}

void Looper::update_progress_bar()
{
  milli_to_sec(jack_get_time());
  m_ProgressBar.set_text(std::to_string(jack_get_time()));
  m_ProgressBar.set_fraction(progress);
}

void Looper::loop()
{
  // jack_time = jack_get_time(); 
  // std::cout << jack_get_time() << std::endl;
  
  Looper::refTime = 0;
  
  if (!islooping) {
    std::cout << "Starting loop" << std::endl;
    Looper::islooping = true;
    loopStartTime = jack_get_time();
    // main_loop();
    progress = 0.8;
  } else {
    std::cout << "Stopping loop" << std::endl;
    Looper::islooping = false;
    loopEndTime = jack_get_time();
    loopTime = loopEndTime - loopStartTime;
    std::cout << loopTime << std::endl;
  }
  clear_buffer();
}

void Looper::panic()
{
  std::cout << "Panic" << std::endl;
}

int Looper::milli_to_sec(int milli) {  // FIXME
  std::cout << milli / 10000 << std::endl;
  return milli / 10000;
}
