#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

class MainWindow: public Gtk::Window, Looper
{

  public:
    
    MainWindow(const Glib::RefPtr<Gtk::Application>& app);
    virtual ~MainWindow();


  private:
    
    const Glib::ustring app_title = "Jack MIDI Loop";
    
    Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();
    
    Gtk::Box m_VBox;
    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TextView m_TextView;
    Gtk::Button* m_button = new Gtk::Button();
    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_button_Panic;
    Gtk::Button m_Button_Quit;
    
    void init_clock();
    
    void on_button_loop();
    void on_button_panic();
    void on_button_quit();
    
};

#endif // MAIN_WINDOW_H