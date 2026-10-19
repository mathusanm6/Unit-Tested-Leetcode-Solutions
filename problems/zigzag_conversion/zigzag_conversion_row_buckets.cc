#include "zigzag_conversion.h"

#include <cstddef>
#include <string>
#include <vector>

std::string convert(const std::string &s, int numRows) {
    if (numRows <= 1 || static_cast<std::size_t>(numRows) >= s.length()) {
        return s;
    }

    std::vector<std::string> rows(static_cast<std::size_t>(numRows));
    int currRow = 0;
    int step = 1;

    for (const char c : s) {
        rows[static_cast<std::size_t>(currRow)] += c;

        if (currRow == 0) {
            step = 1;
        } else if (currRow == numRows - 1) {
            step = -1;
        }

        currRow += step;
    }

    std::string res;
    res.reserve(s.length());
    for (const std::string &row : rows) {
        res += row;
    }

    return res;
}
