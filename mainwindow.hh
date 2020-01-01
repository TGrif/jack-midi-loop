#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>

// #include <gtkmm/button.h>
// #include <gtkmm/window.h>

class MainWindow: public Gtk::Window {

  public:
    MainWindow(const Glib::RefPtr<Gtk::Application>& app);
    virtual ~MainWindow();

  protected:
    
    void build_main_menu(const Glib::RefPtr<Gtk::Application>& app);

    //Signal handlers:
    void on_button_clicked();
    void on_button_quit();
    
    Gtk::Box m_VBox;
    //Member widgets:
    Gtk::Button m_button;
    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_Button_Quit;
};

#endif // MAIN_WINDOW_H