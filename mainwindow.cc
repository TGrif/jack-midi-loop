#include <iostream>

#include "mainwindow.hh"


const Glib::ustring app_title = "Jack MIDI Loop";

bool islooping = false;


MainWindow::MainWindow(const Glib::RefPtr<Gtk::Application>& app):
m_VBox(Gtk::ORIENTATION_VERTICAL),
// : m_button("Hello World")
m_Button_Quit("_Quit", true) {
  
  set_title(app_title);
  set_default_size(400, 300);

  add(m_VBox);

  // build_main_menu(app);
  
  // Sets the border width of the window.
  set_border_width(5);
  
  m_VBox.pack_start(m_button, Gtk::PACK_SHRINK);
  m_button.add_pixlabel("loop.xpm", "loop");
  m_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_clicked));

  
  m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

  m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
  m_ButtonBox.set_border_width(5);
  m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
  m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_quit));
              
  show_all_children();
}

MainWindow::~MainWindow() {
  std::cout << "Ciao" << std::endl;
}

void MainWindow::on_button_clicked() {
  if (!islooping) {
    std::cout << "Starting loop" << std::endl;
    islooping = true;
  } else {
    std::cout << "Stopping loop" << std::endl;
    islooping = false;
  }
}

void MainWindow::on_button_quit() {
  hide();
}

