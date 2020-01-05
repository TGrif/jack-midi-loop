
#include "looper.hh"


Looper::Looper() {
  
  client = jack_client_open("Jack MIDI Loop", JackNullOption, NULL);
  
  inputPort = jack_port_register(client, "midi_in", JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);
  outputPort = jack_port_register(client, "midi_out", JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0);

  jack_set_process_callback(client, staticProcess, static_cast<void*>(this));
  
  jack_on_shutdown(client, jack_shutdown, 0);
  

  this->activate();
  
}


void Looper::activate() {
  if (jack_activate(client) != 0) {
    std::cout << "Jack client activation failed." << std::endl;
    return;
  }
}

void Looper::jack_shutdown(void *arg) {
  std::cout << "Jack exit." << std::endl;
  exit(1);
}

int Looper::staticProcess(jack_nframes_t nframes, void *arg) {
  return static_cast<Looper*>(arg)->process(nframes);
}

int Looper::process(jack_nframes_t nframes) {
  
  // jack_midi_event_t in_event;
  jack_nframes_t event_index = 0;
  // jack_position_t position;
  // jack_transport_state_t transport;
  
  void* port_buffer = jack_port_get_buffer(inputPort, nframes);
  
  // transport = jack_transport_query(client, &position);
  // std::cout << transport << std::endl;
  
  jack_nframes_t event_count = jack_midi_get_event_count(port_buffer);
  
  
  if (event_count > 0) {
    for (int i = 0; i < event_count; i++) {
      jack_midi_event_get(&in_event, port_buffer, i);
      
      // Using "cout" in the JACK process() callback is NOT realtime, this is
      // used here for simplicity.
      std::cout << "Frame " << position.frame << "  Event: " << i << " SubFrame#: " << in_event.time << " \tMessage:\t"
                << (long)in_event.buffer[0] << "\t" << (long)in_event.buffer[1]
                << "\t" << (long)in_event.buffer[2] << std::endl;
                
      msg = std::to_string((long)in_event.buffer[0]) + "\t" + std::to_string((long)in_event.buffer[1]) + "\t" + std::to_string((long)in_event.buffer[2]) + "\n";
      
      iter = m_refTextBuffer->get_iter_at_offset(m_refTextBuffer->get_char_count());
      m_refTextBuffer->insert(iter, msg);
      
    }
  }
  
  return 0;
  
}

Looper::~Looper() {
  // std::cout << "~Looper()" << std::endl;
}

void Looper::clear_buffer() {
  m_refTextBuffer->set_text("");
}

void Looper::loop() {
  if (!islooping) {
    std::cout << "Starting loop" << std::endl;
    Looper::islooping = true;
  } else {
    std::cout << "Stopping loop" << std::endl;
    Looper::islooping = false;
  }
  clear_buffer();
}

void Looper::panic() {
  std::cout << "Panic" << std::endl;
}
