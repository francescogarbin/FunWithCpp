#include "test.h"

class TestVectorCopy : public TestBase {

  public:

    TestVectorCopy();
    TestVectorCopy(const std::string& name,
                   const std::string& description,
                   Logger *logger);
    ~TestVectorCopy() override;
    bool run() override;

};
