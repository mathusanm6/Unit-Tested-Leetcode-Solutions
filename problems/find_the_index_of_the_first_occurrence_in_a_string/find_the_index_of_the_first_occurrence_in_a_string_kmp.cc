#include "find_the_index_of_the_first_occurrence_in_a_string.h"

#include <string>
#include <vector>

int strStr(const std::string& haystack, const std::string& needle) {
    const int n = static_cast<int>(haystack.size());
    const int m = static_cast<int>(needle.size());

    if (m == 0) {
        return 0;
    }
    if (n < m) {
        return -1;
    }

    // 1. Build Longest Prefix Suffix (LPS) array
    std::vector<int> lps(m, 0);
    int prevLps = 0;
    int i = 1;

    while (i < m) {
        if (needle[i] == needle[prevLps]) {
            prevLps++;
            lps[i] = prevLps;
            i++;
        } else if (prevLps == 0) {
            lps[i] = 0;
            i++;
        } else {
            prevLps = lps[prevLps - 1];
        }
    }

    // 2. Match needle against haystack
    int hIdx = 0;
    int nIdx = 0;

    while (hIdx < n) {
        if (haystack[hIdx] == needle[nIdx]) {
            hIdx++;
            nIdx++;

            if (nIdx == m) {
                return hIdx - m;
            }
        } else {
            if (nIdx == 0) {
                hIdx++;
            } else {
                nIdx = lps[nIdx - 1];
            }
        }
    }

    return -1;
}
