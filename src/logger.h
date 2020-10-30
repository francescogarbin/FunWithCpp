#pragma once

#include <string>
#include <glibmm/ustring.h>
#include <gtkmm/textview.h>

using namespace std;

class Logger {

  public:

    enum LogLevel {
      ERROR = 0,
      INFO = 1,
      WARN = 2,
      DEBUG = 3
    };

    Logger(Gtk::TextView *out_view, LogLevel level = LogLevel::DEBUG);
    ~Logger();
    void set_log_level(LogLevel level);
    void error(const std::string& message);
    void info(const std::string& message);
    void warn(const std::string& message);
    void debug(const std::string& message);

  protected:

    LogLevel log_level;
    Gtk::TextView *textview;

    void log(const std::string& message);

};

