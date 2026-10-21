#include "h_index.h"

#include <algorithm>
#include <vector>

int hIndex(std::vector<int> &citations) {
    std::ranges::sort(citations);
    const int n = static_cast<int>(citations.size());
    for (int i = 0; i < n; i++) {
        if (n - i <= citations[i]) {
            return n - i;
        }
    }
    return 0;
}