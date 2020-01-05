#ifndef LOOPER_H
#define LOOPER_H

#include <string>

#include <jack/jack.h>
#include <jack/midiport.h>


class Looper {
  
  public:
    
    Looper();
    virtual ~Looper();
    
    void activate();
    
    std::string msg;
    
    
  protected:
    
    Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;
    Gtk::TextBuffer::iterator iter;
    
    void loop();
    void panic();
    void clear_buffer();
    
    
  private:
    
    bool islooping = false;
    
    static int staticProcess(jack_nframes_t nframes, void *arg);
    
    int process(jack_nframes_t nframes);
    
    static void jack_shutdown(void *arg);
    
    jack_client_t* client;
    jack_port_t* inputPort;
    jack_port_t* outputPort;
  
    jack_midi_event_t in_event;
    jack_position_t position;
  
};

#endif // LOOPER_H