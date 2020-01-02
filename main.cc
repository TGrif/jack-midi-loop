#include <gtkmm/application.h>

#include "looper.cc"
#include "mainwindow.cc"


int main (int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "org.of_pop.jack_midi_looper");

  Looper looper;
  looper.activate();
  
  MainWindow window(app);
  return app->run(window);
}