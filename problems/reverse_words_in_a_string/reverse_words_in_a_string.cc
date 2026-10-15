#include "reverse_words_in_a_string.h"

#include <algorithm>
#include <cstddef>
#include <string>

std::string reverseWords(std::string s) {
    // Step 1: Clean spaces in-place
    const std::size_t n = s.size();
    std::size_t write = 0;

    for (std::size_t read = 0; read < n; ++read) {
        if (s[read] != ' ') {
            if (write > 0) {
                s[write++] = ' ';  // Add single space between words
            }
            while (read < n && s[read] != ' ') {
                s[write++] = s[read++];
            }
        }
    }
    s.resize(write);  // Shrink to cleaned size

    // Step 2: Reverse the whole string
    std::ranges::reverse(s);

    // Step 3: Reverse each word back
    auto wordStart = s.begin();
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it == ' ') {
            std::ranges::reverse(wordStart, it);
            wordStart = it + 1;
        }
    }
    std::ranges::reverse(wordStart, s.end());

    return s;
}
