#include "test_vector_copy.h"

using namespace std;

TestVectorCopy::TestVectorCopy()
    : TestBase()
{
}

TestVectorCopy::TestVectorCopy(const std::string& name,
                               const std::string& description,
                               Logger *logger)
                               : TestBase(name, description, logger)
{
}

TestVectorCopy::~TestVectorCopy()
{
}

bool TestVectorCopy::run()
{
  get_logger().debug("TestVectorCopy::run()...");
  try
  {
    throw std::runtime_error("test error");
  }
  catch(const runtime_error& ex)
  {
    get_logger().debug("Error catched: " + std::string(ex.what()));
  }
  return true;
}

