#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>


class MainWindow: public Gtk::Window, Looper::Looper {

  public:
    
    MainWindow(const Glib::RefPtr<Gtk::Application>&app);
    virtual ~MainWindow();


  // protected:
  private:
    
    const Glib::ustring app_title = "Jack MIDI Loop";
    
    void MIDI_buffer();
    
    void on_button_loop();
    void on_button_panic();
    void on_button_quit();
    
    
    Glib::RefPtr<Gtk::TextBuffer>m_refTextBuffer;
    
    Gtk::Box m_VBox;
    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TextView m_TextView;
    Gtk::Button m_button;
    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_button_Panic;
    Gtk::Button m_Button_Quit;
    Gtk::ProgressBar m_ProgressBar;
    
};

#endif // MAIN_WINDOW_H