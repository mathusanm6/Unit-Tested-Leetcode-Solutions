#include "gas_station.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct GasStationCase {
    std::string test_name;
    std::vector<int> gas;
    std::vector<int> cost;
    int expected;
};

using GasStationTest = ::testing::TestWithParam<GasStationCase>;

TEST_P(GasStationTest, TestCases) {
    GasStationCase testCase = GetParam();
    EXPECT_EQ(canCompleteCircuit(testCase.gas, testCase.cost), testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(GasStationTestCases, GasStationTest,
                         ::testing::Values(
                             GasStationCase{
                                 .test_name = "BasicExample1",
                                 .gas = {1, 2, 3, 4, 5},
                                 .cost = {3, 4, 5, 1, 2},
                                 .expected = 3,
                             },
                             GasStationCase{
                                 .test_name = "BasicExample2",
                                 .gas = {2, 3, 4},
                                 .cost = {3, 4, 3},
                                 .expected = -1,
                             },
                             GasStationCase{
                                 .test_name = "SingleElementPossible",
                                 .gas = {2},
                                 .cost = {2},
                                 .expected = 0,
                             },
                             GasStationCase{
                                 .test_name = "SingleElementImpossible",
                                 .gas = {2},
                                 .cost = {3},
                                 .expected = -1,
                             }),
                         [](const ::testing::TestParamInfo<GasStationCase>& info) {
                             return info.param.test_name;
                         });
