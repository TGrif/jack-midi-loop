/**
 * (of-pop) Jack MIDI Looper
 * TGrif 2019 - GPL3 - direct-shoot.com
 *
 */
#include <iostream>

#include <gtkmm.h>

#include "looper.cc"
#include "mainwindow.cc"


int main (int argc, char *argv[]) {
  
  auto app = Gtk::Application::create(argc, argv, "org.of_pop.jack_midi_looper");

  MainWindow window(app);
  return app->run(window);
  
}
