/****************************************
 * INCLUDES
 ***************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

/****************************************
 * GLOBALS
 ***************************************/

namespace unit_test
{
    std::map<std::string, std::vector<std::string>> failedTests;
}

/****************************************
 * MACROS
 ***************************************/

// Continues testing regardless of the assertion
#define ASSERT_CONT(EXPRESSION)\
try {\
    if (false == ((EXPRESSION))) {\
        unit_test::failedTests[__FUNCTION__].push_back(std::string(__FUNCTION__) + ":" + std::to_string(__LINE__) + ": ASSERT(" #EXPRESSION ") failed!!! Continuing...");\
    }\
} catch(std::exception& e) {\
    unit_test::failedTests[__FUNCTION__].push_back(std::string(__FUNCTION__) + ":" + std::to_string(__LINE__) + ": ASSERT(" #EXPRESSION ") failed with exception: [" + e.what() + "] Continuing...");\
}

// Exits the test method immediately upon failure
#define ASSERT(EXPRESSION)\
try {\
    if (false == ((EXPRESSION))) {\
        unit_test::failedTests[__FUNCTION__].push_back(std::string(__FUNCTION__) + ":" + std::to_string(__LINE__) + ": " + "ASSERT(" #EXPRESSION ") failed!!!");\
        return;\
    }\
} catch(std::exception& e) {\
    unit_test::failedTests[__FUNCTION__].push_back(std::string(__FUNCTION__) + ":" + std::to_string(__LINE__) + ": ASSERT(" #EXPRESSION ") failed with exception: " + e.what());\
    return;\
}

// Defines the beginning of the test list
#define TESTS_BEGIN \
namespace unit_test{\
std::vector<void(*)()> tests = {

// Defines the test function references
#define TEST(t) \
&t,

// Defines the end of the test list and adds the main test function
#define TESTS_END \
};\
}\
int main(int argc, char *argv[])\
{\
    int result = 0;\
    for (auto test : unit_test::tests)\
    {\
        test();\
    }\
    std::cout << "==============================================\n"\
              << "Test Cases: " << unit_test::tests.size() << " total | " << unit_test::tests.size() - unit_test::failedTests.size() << " passed | " << unit_test::failedTests.size() << " failed\n"\
              << "==============================================\n";\
    for (const auto& test : unit_test::failedTests)\
    {\
        for (const auto& failedAssertion : test.second)\
        {\
            std::cout << failedAssertion << "\n";\
        }\
        result = -1;\
    }\
    return result;\
}
