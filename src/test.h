#include <string>
#include "logger.h"

using namespace std;

class TestBase {

public:

  TestBase();
  TestBase(const std::string& name, const std::string& description, Logger *logger);
  virtual ~TestBase();
  std::string& get_name();
  std::string& get_description();
  virtual bool run();

protected:

  std::string* m_ptr_name;
  std::string* m_ptr_desc;
  Logger *m_ptr_logger;

  Logger& get_logger();

};
