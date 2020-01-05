
## Jack MIDI Looper


### compile:
g++ main.cc -o build/midi_looper `pkg-config jack sndfile gtkmm-3.0 --cflags --libs`


### based on:
https://github.com/harryhaaren/JACK-MIDI-Examples/


### icons from:
https://github.com/wxWidgets/wxWidgets/blob/master/art/



     _            _      __  __ ___ ____ ___   _
    | | __ _  ___| | __ |  \/  |_ _|  _ \_ _| | |    ___   ___  _ __  
 _  | |/ _` |/ __| |/ / | |\/| || || | | | |  | |   / _ \ / _ \| '_ \ 
| |_| | (_| | (__|   <  | |  | || || |_| | |  | |__| (_) | (_) | |_) |
 \___/ \__,_|\___|_|\_\ |_|  |_|___|____/___| |_____\___/ \___/| .__/ 
                                                               |_|


Notes:
https://github.com/jackaudio/example-clients/blob/master/midisine.c