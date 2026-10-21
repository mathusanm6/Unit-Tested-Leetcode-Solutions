#include "text_justification.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct TextJustificationCase {
    std::string test_name;
    std::vector<std::string> words;
    int max_width;
    std::vector<std::string> expected;
};

using TextJustificationTest = ::testing::TestWithParam<TextJustificationCase>;

TEST_P(TextJustificationTest, TestCases) {
    const TextJustificationCase& test_case = GetParam();
    const auto result = fullJustify(test_case.words, test_case.max_width);
    EXPECT_EQ(result, test_case.expected);
}

INSTANTIATE_TEST_SUITE_P(
    TextJustificationTestCases, TextJustificationTest,
    ::testing::Values(
        TextJustificationCase{
            .test_name = "BasicExample1",
            .words = {"This", "is", "an", "example", "of", "text", "justification."},
            .max_width = 16,
            .expected = {"This    is    an", "example  of text", "justification.  "}},
        TextJustificationCase{
            .test_name = "SingleWordOnLine",
            .words = {"What", "must", "be", "acknowledgment", "shall", "be"},
            .max_width = 16,
            .expected = {"What   must   be", "acknowledgment  ", "shall be        "}},
        TextJustificationCase{
            .test_name = "LongerText",
            .words = {"Science", "is", "what", "we", "understand", "well", "enough", "to",
                      "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we",
                      "do"},
            .max_width = 20,
            .expected = {"Science  is  what we", "understand      well", "enough to explain to",
                         "a  computer.  Art is", "everything  else  we", "do                  "}}),
    [](const ::testing::TestParamInfo<TextJustificationCase>& info) {
        return info.param.test_name;
    });
