#include "zigzag_conversion.h"

#include <cstddef>
#include <string>

std::string convert(const std::string &s, int numRows) {
    const int n = static_cast<int>(s.length());
    if (numRows <= 1 || numRows >= n) {
        return s;
    }

    std::string res;
    res.reserve(s.length());  // Avoid reallocations

    const int cycleLen = 2 * (numRows - 1);

    for (int r = 0; r < numRows; ++r) {
        for (int i = r; i < n; i += cycleLen) {
            res += s[static_cast<std::size_t>(i)];  // Vertical step

            // Diagonal step for inner rows
            const int diagIdx = i + cycleLen - (2 * r);
            if (r > 0 && r < numRows - 1 && diagIdx < n) {
                res += s[static_cast<std::size_t>(diagIdx)];
            }
        }
    }

    return res;
}
