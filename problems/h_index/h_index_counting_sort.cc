#include "h_index.h"

#include <algorithm>
#include <vector>

// NOLINTNEXTLINE(misc-const-correctness)
int hIndex(std::vector<int> &citations) {
    const int n = static_cast<int>(citations.size());
    std::vector<int> counts(n + 1, 0);

    for (const int citation : citations) {
        ++counts[std::min(citation, n)];
    }

    int total = 0;
    for (int citationCount = n; citationCount >= 0; --citationCount) {
        total += counts[citationCount];
        if (total >= citationCount) {
            return citationCount;
        }
    }
    return 0;
}