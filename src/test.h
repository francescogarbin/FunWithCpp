#include <string>

using namespace std;

class TestBase {

public:

  TestBase();
  TestBase(const std::string& name, const std::string& description);
  virtual ~TestBase();
  std::string& get_name();
  std::string& get_description();
  virtual bool run();

protected:

  std::string* m_ptr_name;
  std::string* m_ptr_desc;

};
