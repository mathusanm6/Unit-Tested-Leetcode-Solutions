#include "minimum_flips_in_binary_tree_to_get_result.h"

#include <gtest/gtest.h>
#include <string>
#include "../../common/trees/treenode.h"

struct MinimumFlipsCase {
    std::string test_name;
    TreeNode *root;
    bool result;
    int expected;
};

using MinimumFlipsTest = ::testing::TestWithParam<MinimumFlipsCase>;

TEST_P(MinimumFlipsTest, TestCases) {
    const MinimumFlipsCase &testCase = GetParam();
    const int result = minimumFlips(testCase.root, testCase.result);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumFlipsTestCases, MinimumFlipsTest,
    ::testing::Values(
        MinimumFlipsCase{
            .test_name = "Leaf0ToTrue", .root = new TreeNode(0), .result = true, .expected = 1},
        MinimumFlipsCase{.test_name = "Leaf1AlreadyTrue",
                         .root = new TreeNode(1),
                         .result = true,
                         .expected = 0},
        MinimumFlipsCase{.test_name = "OrGateFlipChild",
                         .root = new TreeNode(2, new TreeNode(0), new TreeNode(0)),
                         .result = true,
                         .expected = 1},
        MinimumFlipsCase{.test_name = "OrGateToFalse",
                         .root = new TreeNode(2, new TreeNode(1), new TreeNode(1)),
                         .result = false,
                         .expected = 2},
        MinimumFlipsCase{.test_name = "AndGateAlreadyTrue",
                         .root = new TreeNode(3, new TreeNode(1), new TreeNode(1)),
                         .result = true,
                         .expected = 0},
        MinimumFlipsCase{.test_name = "AndGateFlipChild",
                         .root = new TreeNode(3, new TreeNode(1), new TreeNode(0)),
                         .result = true,
                         .expected = 1},
        MinimumFlipsCase{.test_name = "XorGateAlreadyTrue",
                         .root = new TreeNode(4, new TreeNode(1), new TreeNode(0)),
                         .result = true,
                         .expected = 0},
        MinimumFlipsCase{.test_name = "XorGateAlreadyFalse",
                         .root = new TreeNode(4, new TreeNode(1), new TreeNode(1)),
                         .result = false,
                         .expected = 0},
        MinimumFlipsCase{.test_name = "NotGateAlreadyTrue",
                         .root = new TreeNode(5, new TreeNode(0), nullptr),
                         .result = true,
                         .expected = 0},
        MinimumFlipsCase{.test_name = "NotGateAlreadyFalse",
                         .root = new TreeNode(5, new TreeNode(1), nullptr),
                         .result = false,
                         .expected = 0},
        MinimumFlipsCase{.test_name = "ComplexTreeOrAlreadyTrue",
                         .root = new TreeNode(2, new TreeNode(3, new TreeNode(1), new TreeNode(0)),
                                              new TreeNode(5, new TreeNode(0), nullptr)),
                         .result = true,
                         .expected = 0},
        MinimumFlipsCase{.test_name = "ComplexTreeAndAlreadyFalse",
                         .root = new TreeNode(3, new TreeNode(2, new TreeNode(0), new TreeNode(0)),
                                              new TreeNode(5, new TreeNode(1), nullptr)),
                         .result = false,
                         .expected = 0},
        MinimumFlipsCase{.test_name = "ComplexTreeXorNeedFlip",
                         .root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(0)),
                                              new TreeNode(3, new TreeNode(1), new TreeNode(1))),
                         .result = true,
                         .expected = 1},
        MinimumFlipsCase{.test_name = "ComplexTreeXorToFalse",
                         .root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(1)),
                                              new TreeNode(3, new TreeNode(1), new TreeNode(0))),
                         .result = false,
                         .expected = 1},
        MinimumFlipsCase{
            .test_name = "Leaf0ToFalse", .root = new TreeNode(0), .result = false, .expected = 0},
        MinimumFlipsCase{
            .test_name = "Leaf1ToFalse", .root = new TreeNode(1), .result = false, .expected = 1},
        MinimumFlipsCase{.test_name = "AndGateToFalse",
                         .root = new TreeNode(3, new TreeNode(0), new TreeNode(1)),
                         .result = false,
                         .expected = 0},
        MinimumFlipsCase{.test_name = "NotGateFlipToTrue",
                         .root = new TreeNode(5, new TreeNode(1), nullptr),
                         .result = true,
                         .expected = 1},
        MinimumFlipsCase{.test_name = "NotGateFlipToFalse",
                         .root = new TreeNode(5, new TreeNode(0), nullptr),
                         .result = false,
                         .expected = 1},
        MinimumFlipsCase{
            .test_name = "ComplexXorTreeWithNotRightChild",
            .root = new TreeNode(
                4, new TreeNode(0),
                new TreeNode(2, new TreeNode(0),
                             new TreeNode(5, nullptr, new TreeNode(5, nullptr, new TreeNode(1))))),
            .result = true,
            .expected = 0}),
    [](const ::testing::TestParamInfo<MinimumFlipsCase> &info) { return info.param.test_name; });