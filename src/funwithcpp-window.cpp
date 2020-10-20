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

#include <string>
#include <glibmm/ustring.h>
#include "funwithcpp-window.h"

using namespace Glib;
using namespace Gtk;

FunwithcppWindow::FunwithcppWindow()
	: Glib::ObjectBase("FunwithcppWindow")
	, Gtk::Window()
	, headerbar(nullptr)
	, mainbox(nullptr)
    , console_view(nullptr)
	, status_label(nullptr)
	, toolbar(nullptr)
{
	builder = Gtk::Builder::create_from_resource("/org/example/App/funwithcpp-window.ui");

	builder->get_widget("headerbar", headerbar);
	headerbar->set_title("Fun with C++");
	headerbar->show();
	this->set_titlebar(*headerbar);

    builder->get_widget("main_box", mainbox);
    builder->get_widget("main_window_toolbar", toolbar);
    builder->get_widget("console_view", console_view);
	builder->get_widget("status_label", status_label);
	status_label->show();
    add(*mainbox);

	play_with_auto();
	//test_string_from_map();

	simple_vector_test();
}

void FunwithcppWindow::console_log(std::string& text) {
    console_view->set_editable(true);
    console_view->set_editable(false);
}

void FunwithcppWindow::play_with_auto() {
    auto intvar{2};
    auto doublevar{2.2};
    std::vector v{intvar, doublevar};
    std::string output = std::string();
    for(auto value : v) {
         output.append(std::to_string(value));
         output.append(" ");
    }
    this->status_label->set_text(output);
}

void FunwithcppWindow::test_string_from_map() {
    std::map<std::string, std::string>* map_ptr = new std::map<std::string, std::string>();
    (*map_ptr)["one"] = "What a";
    (*map_ptr)["two"] = "lovely language!";
    std::string text = this->string_from_map(*map_ptr, "one", "three");
    text.append(" ");
    text.append(this->string_from_map(*map_ptr, "two", "three"));
    this->status_label->set_text(text);
    delete map_ptr;
}

std::string FunwithcppWindow::string_from_map(const std::map<std::string, std::string>& a_map,
                                              const std::string& key,
                                              const std::string& deflt) {
    //const std::map<std::string, std::string>::iterator pos;
    //pos = a_map.find(key);
    auto pos = a_map.find(key);
    if(pos == a_map.end()) {
        return deflt;
    }
    return pos->second;
}

void FunwithcppWindow::simple_vector_test() {
    std::vector<std::string> vec;

    vec.push_back("abc");
    std::string text = "def";
    vec.push_back(text);
    std::vector<std::string>::size_type vec_size_t0 = vec.size();
    vec.shrink_to_fit();
    std::vector<std::string>::size_type vec_size_t1 = vec.size();

    std::string status_text{};
    status_text.append("vec t0=");
    status_text.append(std::to_string(vec_size_t0));
    status_text.append(" t1=");
    status_text.append(std::to_string(vec_size_t1));

    std::vector<std::string> autovec{"abc", "def"};
    auto autovec_size_t0 = autovec.capacity();
    autovec.shrink_to_fit();
    auto autovec_size_t1 = autovec.capacity();

    status_text.append(" autovec t0=");
    status_text.append(std::to_string(autovec_size_t0));
    status_text.append(" t1=");
    status_text.append(std::to_string(autovec_size_t1));

    status_label->set_text(status_text);
}
