#include "zigzag_conversion.h"

#include <gtest/gtest.h>
#include <string>

struct ZigzagConversionCase {
    std::string test_name;
    std::string s;
    int numRows;
    std::string expected;
};

using ZigzagConversionTest = ::testing::TestWithParam<ZigzagConversionCase>;

TEST_P(ZigzagConversionTest, TestCases) {
    const ZigzagConversionCase &testCase = GetParam();
    const std::string result = convert(testCase.s, testCase.numRows);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(ZigzagConversionTestCases, ZigzagConversionTest,
                         ::testing::Values(ZigzagConversionCase{.test_name = "BasicExample1",
                                                                .s = "PAYPALISHIRING",
                                                                .numRows = 3,
                                                                .expected = "PAHNAPLSIIGYIR"},
                                           ZigzagConversionCase{.test_name = "BasicExample2",
                                                                .s = "PAYPALISHIRING",
                                                                .numRows = 4,
                                                                .expected = "PINALSIGYAHRPI"},
                                           ZigzagConversionCase{.test_name = "SingleCharSingleRow",
                                                                .s = "A",
                                                                .numRows = 1,
                                                                .expected = "A"}),
                         [](const ::testing::TestParamInfo<ZigzagConversionCase> &info) {
                             return info.param.test_name;
                         });
