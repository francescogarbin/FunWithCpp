/* funwithcpp-window.h
 *
 * Copyright 2020 Francesco Garbin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <gtkmm/builder.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>
#include <gtkmm/toolbar.h>
#include <gtkmm/box.h>
#include <gtkmm/textview.h>
#include <map>
#include <string>
#include <vector>

class FunwithcppWindow : public Gtk::Window {

  public:

  FunwithcppWindow();

  protected:

    Gtk::Box *mainbox;
    Gtk::HeaderBar *headerbar;
    Gtk::Toolbar *toolbar;
    Gtk::TextView *console_view;
    Gtk::Label *status_label;
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gtk::TextBuffer> console_buffer;

    void announce_test(std::string test_name);
    void console_log(const std::string text);
    void play_with_auto();
    void test_string_from_map();
    void simple_vector_test();
    std::string string_from_map(const std::map<std::string, std::string>& map,
                                const std::string& key,
                                const std::string& deflt);

};
