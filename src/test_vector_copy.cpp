#include "test_vector_copy.h"

TestVectorCopy::TestVectorCopy() :
    TestBase() {
}

TestVectorCopy::TestVectorCopy(const std::string& name, const std::string& description) :
    TestBase(name, description) {
}

TestVectorCopy::~TestVectorCopy() {
}

bool TestVectorCopy::run() {
    return true;
} 
