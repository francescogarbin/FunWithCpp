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
    // empty constructor
}

TestVectorCopy::~TestVectorCopy()
{
    // empty destructor
    // and another line created on Macbook.
    // and a THIRD line added on Nixbox.
    // Nixbox did this line!
}

bool TestVectorCopy::run()
{
    get_logger().debug("wtf!");
    return true;
} 
