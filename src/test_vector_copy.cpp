#include "test_vector_copy.h"

TestVectorCopy::TestVectorCopy()
    : TestBase()
{
}

TestVectorCopy::TestVectorCopy(const std::string& name,
                               const std::string& description)
                               : TestBase(name, description)
{
    // empty constructor
}

TestVectorCopy::~TestVectorCopy()
{
    // empty destructor
    // and another line created on Macbook.
}

bool TestVectorCopy::run()
{
    return true;
} 
