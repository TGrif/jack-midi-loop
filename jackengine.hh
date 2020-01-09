#ifndef JACK_ENGINE_H
#define JACK_ENGINE_H

#include <jack/jack.h>
#include <jack/midiport.h>

class JackEngine
{
  
  protected:
    
    const char* MIDI_TYPE = JACK_DEFAULT_MIDI_TYPE;  // 8 bit raw midi
    
    jack_client_t* client;
    jack_port_t* inputPort;
    jack_port_t* inputTriggerPort;
    jack_port_t* outputPort;
    
    jack_midi_event_t in_event;
    jack_midi_event_t in_trigger_event;
    jack_position_t position;
    jack_transport_state_t transport;
    
};

#endif // JACK_ENGINE_H