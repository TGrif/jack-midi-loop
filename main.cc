/**
 * Jack MIDI Looper
 * TGrif 2019 (of-pop records) - direct-shoot.com
 * License GPL3
 *
 */
#include <iostream>

#include <gtkmm.h>

#include "looper.cc"
#include "mainwindow.cc"

int main(int argc, char *argv[])
{
  
  auto app = Gtk::Application::create(argc, argv, "org.of_pop.jack_midi_looper");

  MainWindow window(app);
  return app->run(window);
  
}
