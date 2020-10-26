#include "test.h"

class TestVectorCopy : public TestBase {

public:

  TestVectorCopy();
  TestVectorCopy(const std::string& name, const std::string& description);
  ~TestVectorCopy() override;
  bool run() override;

};
