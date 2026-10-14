#include "roman_to_integer.h"

#include <cstddef>
#include <string>
#include <unordered_map>

int romanToInt(const std::string &s) {
    const std::unordered_map<char, int> val = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000},
    };

    const std::size_t n = s.length();
    int res = 0;

    for (std::size_t i = 0; i < n; ++i) {
        if (i + 1 < n && val.at(s[i]) < val.at(s[i + 1])) {
            res -= val.at(s[i]);
        } else {
            res += val.at(s[i]);
        }
    }

    return res;
}
