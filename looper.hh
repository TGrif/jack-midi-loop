#ifndef LOOPER_H
#define LOOPER_H

#include <vector>
#include <string>

#include "jackengine.hh"

using std::string;

class Looper: JackEngine {

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

    // int test_time = 0;

    int milli_to_sec(int milli);

    int playbackIndex;

    int refTime;
    int loopTime;
    int loopStartTime;
    int loopEndTime;

    static int staticProcess(jack_nframes_t nframes, void *arg);

    int process(jack_nframes_t nframes);

    static void jack_shutdown(void *arg);

};

#endif // LOOPER_H