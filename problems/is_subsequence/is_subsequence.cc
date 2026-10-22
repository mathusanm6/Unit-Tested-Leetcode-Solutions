#include "is_subsequence.h"

#include <cstddef>
#include <string>

bool isSubsequence(const std::string& s, const std::string& t) {
    if (s.empty()) {
        return true;
    }
    if (s.length() > t.length()) {
        return false;
    }

    std::size_t i = 0;
    const std::size_t n = s.length();

    for (const char c : t) {
        if (c == s[i]) {
            ++i;
            if (i == n) {
                return true;
            }
        }
    }

    return false;
}
