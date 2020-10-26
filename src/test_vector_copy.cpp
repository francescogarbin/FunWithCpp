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
    // and a THIRD line added on Nixbox.
    // Macbook did this line!
}

bool TestVectorCopy::run()
{
    return true;
} 
