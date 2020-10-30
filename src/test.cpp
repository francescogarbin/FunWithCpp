#include <stdexcept>
#include "test.h"

using namespace std;

TestBase::TestBase() :
    m_ptr_name(nullptr),
    m_ptr_desc(nullptr) {
}

TestBase::TestBase(const std::string& name,
                   const std::string& description,
                   Logger *logger)
{
    m_ptr_name = new std::string(name);
    m_ptr_desc = new std::string(description);
    m_ptr_logger = logger;
}

TestBase::~TestBase() {
    if(this->m_ptr_name) {
        delete m_ptr_name;
    }
    if(this->m_ptr_desc) {
        delete m_ptr_desc;
    }
}

std::string& TestBase::get_name() {
    return *m_ptr_name;
}

std::string& TestBase::get_description() {
    return *m_ptr_desc;
}

bool TestBase::run() {
    return true;
}

Logger& TestBase::get_logger()
{
  if(nullptr == this->m_ptr_logger)
  {
    throw std::runtime_error("Member Logger::m_ptr_logger is invalid.");
  }
  return *m_ptr_logger;
}

