#include "logger.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Logger::Logger(Gtk::TextView *out_view, LogLevel level)
{
  this->textview = out_view;
  this->log_level = level;
}

Logger::~Logger()
{
}

void Logger::set_log_level(LogLevel level)
{
  this->log_level = level;
}

void Logger::error(const std::string& message)
{
  if(LogLevel::DEBUG == this->log_level ||
     LogLevel::WARN == this->log_level ||
     LogLevel::INFO == this->log_level)
  {
    return;
  }
  this->log(message);
}

void Logger::info(const std::string& message)
{
  if(LogLevel::DEBUG == this->log_level ||
     LogLevel::WARN == this->log_level)
  {
    return;
  }
  this->log(message);
}

void Logger::warn(const std::string& message)
{
  if(LogLevel::DEBUG == this->log_level ||
     LogLevel::WARN == this->log_level)
  {
    this->log(message);
  }
}

void Logger::debug(const std::string& message)
{
  if(LogLevel::DEBUG == this->log_level)
  {
    this->log(message);
  }
}

void Logger::log(const std::string& message)
{
    this->textview->set_editable(true);
    Glib::RefPtr<Gtk::TextBuffer> buffer = this->textview->get_buffer();
    std::stringstream formatted;
    formatted << std::endl << message << std::endl;
    buffer->insert(buffer->end(), formatted.str());
    this->textview->set_editable(false);
}

