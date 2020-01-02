#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>


class MainWindow: public Gtk::Window {

  public:
    
    MainWindow(const Glib::RefPtr<Gtk::Application>& app);
    virtual ~MainWindow();


  protected:
    
    // void build_main_menu(const Glib::RefPtr<Gtk::Application>& app);
    void MIDI_buffer();

    //Signal handlers:
    void on_button_loop();
    void on_button_panic();
    void on_button_quit();
    
    Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;
    
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