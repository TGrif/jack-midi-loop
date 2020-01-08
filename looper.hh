#ifndef LOOPER_H
#define LOOPER_H

#include <vector>
#include <string>

#include <jack/jack.h>
#include <jack/midiport.h>

// #include "midievent.hh"

using std::string;


class Looper
{
  
  public:
    
    Looper();
    virtual ~Looper();
    
    void activate();
    
    string msg;
    
    
  protected:
    
    Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;
    Gtk::TextBuffer::iterator iter;
    
    Gtk::ProgressBar m_ProgressBar;
    
    void loop();
    void panic();
    void clear_buffer();
    void update_progress_bar();
    
    bool islooping = false;
    
    float progress;
    
    
  private:
    
    int playbackIndex;
    
    // std::vector<MidiEvent> eventVector;
    
    int refTime;
    int loopTime;
    int loopStartTime;
    int loopEndTime;
    
    const char* MIDI_TYPE = JACK_DEFAULT_MIDI_TYPE; // 8 bit raw midi
    
    static int staticProcess(jack_nframes_t nframes, void *arg);
    
    int process(jack_nframes_t nframes);
    
    static void jack_shutdown(void *arg);
    
    jack_client_t* client;
    jack_port_t* inputPort;
    jack_port_t* inputTriggerPort;
    jack_port_t* outputPort;
  
    jack_midi_event_t in_event;
    jack_midi_event_t in_trigger_event;
    jack_position_t position;
    jack_transport_state_t transport;
  
};

#endif // LOOPER_H