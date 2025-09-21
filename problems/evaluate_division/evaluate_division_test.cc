#include "evaluate_division.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct EvaluateDivisionCase {
    std::string test_name;
    std::vector<std::vector<std::string>> equations;
    std::vector<double> values;
    std::vector<std::vector<std::string>> queries;
    std::vector<double> expected;
};

using EvaluateDivisionTest = ::testing::TestWithParam<EvaluateDivisionCase>;

TEST_P(EvaluateDivisionTest, TestCases) {
    const EvaluateDivisionCase &testCase = GetParam();
    const auto result = evaluateDivision(testCase.equations, testCase.values, testCase.queries);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    EvaluateDivisionTestCases, EvaluateDivisionTest,
    ::testing::Values(
        EvaluateDivisionCase{
            .test_name = "example1",
            .equations = {{"a", "b"}, {"b", "c"}},
            .values = {2.0, 3.0},
            .queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
            .expected = {6.00000, 0.50000, -1.00000, 1.00000, -1.00000}},
        EvaluateDivisionCase{.test_name = "example2",
                             .equations = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}},
                             .values = {1.5, 2.5, 5.0},
                             .queries = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}},
                             .expected = {3.75000, 0.40000, 5.00000, 0.20000}},
        EvaluateDivisionCase{.test_name = "example3",
                             .equations = {{"a", "b"}},
                             .values = {0.5},
                             .queries = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}},
                             .expected = {0.50000, 2.00000, -1.00000, -1.00000}}),
    [](const testing::TestParamInfo<EvaluateDivisionCase> &info) { return info.param.test_name; });
