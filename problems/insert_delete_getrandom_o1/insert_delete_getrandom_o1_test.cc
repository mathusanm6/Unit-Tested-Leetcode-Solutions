#include "insert_delete_getrandom_o1.h"

#include <gtest/gtest.h>
#include <cstddef>
#include <memory>
#include <string>
#include <unordered_set>
#include <variant>
#include <vector>

using ExpectedValue = std::variant<std::monostate, bool, int>;
constexpr ExpectedValue NullVal = std::monostate{};

struct InsertDeleteGetRandomO1Case {
    std::string test_name;
    std::vector<std::string> operations;
    std::vector<std::vector<int>> inputs;
    std::vector<ExpectedValue> expected;
};

using InsertDeleteGetRandomO1Test = ::testing::TestWithParam<InsertDeleteGetRandomO1Case>;

TEST_P(InsertDeleteGetRandomO1Test, TestCases) {
    InsertDeleteGetRandomO1Case testCase = GetParam();
    ASSERT_EQ(testCase.operations.size(), testCase.inputs.size());
    ASSERT_EQ(testCase.operations.size(), testCase.expected.size());

    std::unique_ptr<RandomizedSet> randomizedSet;
    std::unordered_set<int> present;

    for (size_t i = 0; i < testCase.operations.size(); ++i) {
        const std::string &op = testCase.operations[i];
        const std::vector<int> &args = testCase.inputs[i];
        const ExpectedValue &exp = testCase.expected[i];

        if (op == "RandomizedSet") {
            randomizedSet = std::make_unique<RandomizedSet>();
            present.clear();
            EXPECT_TRUE(std::holds_alternative<std::monostate>(exp));
        } else if (op == "insert") {
            ASSERT_NE(randomizedSet, nullptr);
            int val = args[0];
            present.insert(val);
            EXPECT_EQ(randomizedSet->insert(val), std::get<bool>(exp));
        } else if (op == "remove") {
            ASSERT_NE(randomizedSet, nullptr);
            int val = args[0];
            present.erase(val);
            EXPECT_EQ(randomizedSet->remove(val), std::get<bool>(exp));
        } else if (op == "getRandom") {
            ASSERT_NE(randomizedSet, nullptr);
            int result = randomizedSet->getRandom();
            EXPECT_GT(present.count(result), 0U);
            if (present.size() == 1U) {
                EXPECT_EQ(result, std::get<int>(exp));
            }
        }
    }
}

INSTANTIATE_TEST_SUITE_P(
    InsertDeleteGetRandomO1TestCases, InsertDeleteGetRandomO1Test,
    ::testing::Values(
        InsertDeleteGetRandomO1Case{.test_name = "BasicExample",
                                    .operations = {"RandomizedSet", "insert", "remove", "insert",
                                                   "getRandom", "remove", "insert", "getRandom"},
                                    .inputs = {{}, {1}, {2}, {2}, {}, {1}, {2}, {}},
                                    .expected = {NullVal, true, false, true, 1, true, false, 2}},
        InsertDeleteGetRandomO1Case{.test_name = "SingleElementOperations",
                                    .operations = {"RandomizedSet", "insert", "getRandom", "remove",
                                                   "remove", "insert", "getRandom"},
                                    .inputs = {{}, {42}, {}, {42}, {42}, {42}, {}},
                                    .expected = {NullVal, true, 42, true, false, true, 42}},
        InsertDeleteGetRandomO1Case{
            .test_name = "DuplicateInsertsAndRemoves",
            .operations = {"RandomizedSet", "insert", "insert", "remove", "remove"},
            .inputs = {{}, {5}, {5}, {5}, {5}},
            .expected = {NullVal, true, false, true, false}},
        InsertDeleteGetRandomO1Case{.test_name = "RemoveFirstElementSwap",
                                    .operations = {"RandomizedSet", "insert", "insert", "insert",
                                                   "remove", "remove", "getRandom"},
                                    .inputs = {{}, {10}, {20}, {30}, {10}, {30}, {}},
                                    .expected = {NullVal, true, true, true, true, true, 20}},
        InsertDeleteGetRandomO1Case{
            .test_name = "NegativeAndZeroValues",
            .operations = {"RandomizedSet", "insert", "insert", "remove", "getRandom"},
            .inputs = {{}, {0}, {-1}, {0}, {}},
            .expected = {NullVal, true, true, true, -1}}),
    [](const ::testing::TestParamInfo<InsertDeleteGetRandomO1Case> &info) {
        return info.param.test_name;
    });
