#include <gtkmm/application.h>

#include "mainwindow.cc"


int main (int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  MainWindow window(app);

  return app->run(window);
}