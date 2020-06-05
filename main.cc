/**
 * Jack MIDI Looper
 * TGrif (of-pop) 2019 - direct-shoot.com
 * License GPL3
 *
 */
#include <iostream>

#include <gtkmm.h>

#include "looper.cc"
#include "mainwindow.cc"

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "org.of_pop.jack_midi_looper");

  MainWindow window(app);
  return app->run(window);
}



/*
     _            _      __  __ ___ ____ ___   _
    | | __ _  ___| | __ |  \/  |_ _|  _ \_ _| | |    ___   ___  _ __  
 _  | |/ _` |/ __| |/ / | |\/| || || | | | |  | |   / _ \ / _ \| '_ \ 
| |_| | (_| | (__|   <  | |  | || || |_| | |  | |__| (_) | (_) | |_) |
 \___/ \__,_|\___|_|\_\ |_|  |_|___|____/___| |_____\___/ \___/| .__/ 
                                                               |_|
*/