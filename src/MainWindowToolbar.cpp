#include <gtk/gtk.h>
#include "MainWindowToolbar.h"

using namespace Glib;
using namespace Gtk;

MainWindowToolbar::MainWindowToolbar()
: Gtk::Toolbar() {
}

Gtk::Widget* MainWindowToolbar::get_widget() {
    return this;
}
