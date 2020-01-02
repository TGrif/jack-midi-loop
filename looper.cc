#include <iostream>

#include "looper.hh"


Looper::Looper() {
  
  client = jack_client_open("Jack MIDI Loop", JackNullOption, NULL);
  
  inputPort = jack_port_register(client, "midi_in", JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);
  outputPort = jack_port_register(client, "midi_out", JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0);

  // jack_set_process_callback(client, jack_process, 0);
  jack_set_process_callback(client, staticProcess, static_cast<void*>(this));
  
}


void Looper::activate() {
  if (jack_activate(client) != 0) {
    std::cout<<  "cannot activate client" << std::endl;
    return;
  }
}

int Looper::staticProcess(jack_nframes_t nframes, void *arg) {
  return static_cast<Looper*>(arg)->process(nframes);
}

int Looper::process(jack_nframes_t nframes) {
}

Looper::~Looper() {
  std::cout << "~Looper()" << std::endl;
}