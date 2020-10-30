#include "test_vector_copy.h"

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
    return true;
}

