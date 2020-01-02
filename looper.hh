#ifndef LOOPER_H
#define LOOPER_H

#include <jack/jack.h>
#include <jack/midiport.h>


class Looper {
  
  public:
    
    Looper();
    ~Looper();
    
    void activate();
    
    static int staticProcess(jack_nframes_t nframes, void *arg);
    
    
  private:
    
    int process(jack_nframes_t nframes);
    
    jack_client_t* client;
    jack_port_t* inputPort;
    jack_port_t* outputPort;
    
};

#endif // LOOPER_H