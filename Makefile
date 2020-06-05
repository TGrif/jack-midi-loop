all: midi_looper

midi_looper: main.cc
	g++ main.cc -o build/midi_looper `pkg-config jack gtkmm-3.0 --cflags --libs`

clean:
	# TODO