#include <gtk/gtk.h>
#include <gtkmm/toolbar.h>

class MainWindowToolbar : public Gtk::Toolbar {

  public:

    MainWindowToolbar();
    Gtk::Widget* get_widget();

};

