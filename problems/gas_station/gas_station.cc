#include "gas_station.h"

#include <cstddef>
#include <numeric>
#include <vector>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    if (std::accumulate(gas.begin(), gas.end(), 0) < std::accumulate(cost.begin(), cost.end(), 0)) {
        return -1;
    }

    int startIdx = 0;
    int total = 0;

    for (std::size_t idx = 0; idx < gas.size(); ++idx) {
        total += gas[idx] - cost[idx];
        if (total < 0) {
            startIdx = static_cast<int>(idx + 1);
            total = 0;
        }
    }

    return startIdx;
}
