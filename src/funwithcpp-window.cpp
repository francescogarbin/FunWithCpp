/* funwithcpp-window.cpp
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

#include <string>
#include <glibmm/ustring.h>
#include "funwithcpp-window.h"
#include "logger.h"
#include "test_vector_copy.h"

using namespace Glib;
using namespace Gtk;
using namespace std;

FunwithcppWindow::FunwithcppWindow()
    : Glib::ObjectBase("FunwithcppWindow")
    , Gtk::Window()
    , headerbar(nullptr)
    , mainbox(nullptr)
    , console_view(nullptr)
    , status_label(nullptr)
    , toolbar(nullptr)
    , console_buffer(nullptr) {

    // fetch UI controls
    builder = Gtk::Builder::create_from_resource("/org/example/App/funwithcpp-window.ui");

    // setup headerbar
    builder->get_widget("headerbar", headerbar);
    headerbar->set_title("Fun with C++");
    headerbar->show();
    this->set_titlebar(*headerbar);

    // fetch the main box container
    builder->get_widget("main_box", mainbox);

    // fetch other widgets
    builder->get_widget("main_window_toolbar", toolbar);
    builder->get_widget("console_view", console_view);
    builder->get_widget("status_label", status_label);

    // set status label and force it to appear
    status_label->set_text("Idle");
    status_label->show();

    // add the box to main window
    add(*mainbox);

    // setup the textbuffer for the console textview
    console_buffer = Gtk::TextBuffer::create();
    console_view->set_buffer(console_buffer);
    console_log("Welcome to Fun with C++ :-)");

    // Run tests
    play_with_auto();
    simple_vector_test();

    Logger *logger = new Logger(console_view);

    TestVectorCopy vec_copy("namexyz", "descriptionxyz", logger);
    announce_test(vec_copy.get_name());
    console_log(std::string("description: ") + vec_copy.get_description());
    bool success = vec_copy.run();
    console_log(success ? "test succeeded": "test failed");

    delete logger;
}

void FunwithcppWindow::console_log(const std::string text) {
    console_view->set_editable(true);
    std::string existing = console_buffer->get_text();
    existing.append("\n");
    existing.append(text);
    console_buffer->set_text(existing);
    console_view->set_editable(false);
}

void FunwithcppWindow::announce_test(std::string test_name) {
    std::string console_text{"\n*** "};
    console_text.append(test_name);
    console_log(console_text);
}

void FunwithcppWindow::play_with_auto() {
    announce_test("play_with_auto...");
    auto intvar{2};
    auto doublevar{2.2};
    std::vector v{intvar, doublevar};
    std::string output = std::string();
    for(auto value : v) {
         output.append(std::to_string(value));
         output.append(" ");
    }
    console_log(output);
}

void FunwithcppWindow::test_string_from_map() {
    announce_test("string_from_map");
    std::map<std::string, std::string>* map_ptr = new std::map<std::string, std::string>();
    (*map_ptr)["one"] = "What a";
    (*map_ptr)["two"] = "lovely language!";
    std::string text = this->string_from_map(*map_ptr, "one", "three");
    text.append(" ");
    text.append(this->string_from_map(*map_ptr, "two", "three"));
    console_log(text);
    delete map_ptr;
}

std::string FunwithcppWindow::string_from_map(const std::map<std::string, std::string>& a_map,
                                              const std::string& key,
                                              const std::string& deflt) {
    announce_test("string_from_map");
    auto pos = a_map.find(key);
    if(pos == a_map.end()) {
        return deflt;
    }
    return pos->second;
}

void FunwithcppWindow::simple_vector_test() {
    announce_test("simple_vector_test");
    std::vector<std::string> vec;
    vec.push_back("abc");
    std::string text = "def";
    vec.push_back(text);
    std::vector<std::string>::size_type vec_size_t0 = vec.size();
    vec.shrink_to_fit();
    std::vector<std::string>::size_type vec_size_t1 = vec.size();
    std::string output{};
    output.append("vec t0=");
    output.append(std::to_string(vec_size_t0));
    output.append(" t1=");
    output.append(std::to_string(vec_size_t1));
    std::vector<std::string> autovec{"abc", "def"};
    auto autovec_size_t0 = autovec.capacity();
    autovec.shrink_to_fit();
    auto autovec_size_t1 = autovec.capacity();
    output.append(" autovec t0=");
    output.append(std::to_string(autovec_size_t0));
    output.append(" t1=");
    output.append(std::to_string(autovec_size_t1));
    console_log(output);
}
