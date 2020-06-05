#include "mainwindow.hh"

MainWindow::MainWindow(const Glib::RefPtr<Gtk::Application>& app):
  m_VBox(Gtk::ORIENTATION_VERTICAL) {

  set_title(app_title);
  set_icon_from_file("icon/midi.png");
  set_default_size(400, 600);
  set_border_width(5);

  init_clock();

  add(m_VBox);

  m_TextView.set_editable(false);
  m_refTextBuffer = Gtk::TextBuffer::create();
  m_TextView.set_buffer(m_refTextBuffer);

  m_VBox.pack_start(m_ScrolledWindow);
  m_ScrolledWindow.add(m_TextView);
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  m_VBox.pack_start(*m_button, Gtk::PACK_SHRINK);
  m_button->add_pixlabel("icon/loop.xpm", "loop");
  m_button->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_loop));

  m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);
  m_ButtonBox.set_border_width(5);
  m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
  m_ButtonBox.set_spacing(18);

  m_ButtonBox.pack_start(m_ProgressBar, Gtk::PACK_SHRINK, 10);
  m_ProgressBar.set_halign(Gtk::ALIGN_CENTER);
  m_ProgressBar.set_valign(Gtk::ALIGN_CENTER);
  m_ProgressBar.set_show_text(true);

  m_ButtonBox.pack_start(m_button_Panic, Gtk::PACK_SHRINK);
  m_button_Panic.add_pixlabel("icon/panic.xpm", "Panic");
  m_button_Panic.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_panic));

  m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
  m_Button_Quit.add_pixlabel("icon/quit.xpm", "Quit");
  m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_quit));

  show_all_children();

}

MainWindow::~MainWindow() {
  std::cout << "Ciao." << std::endl;
}

void MainWindow::on_button_loop() {
  Looper::loop();

  if (islooping) {
    css_provider->load_from_data("button { color: white; background-image: image(red); }");
    m_button->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
  } else {
    m_button->get_style_context()->remove_provider(css_provider);
  }
}

void MainWindow::init_clock() {
  m_ProgressBar.set_text("00:00");
}

void MainWindow::on_button_panic() {
  Looper::panic();
}

void MainWindow::on_button_quit() {
  hide();
}
