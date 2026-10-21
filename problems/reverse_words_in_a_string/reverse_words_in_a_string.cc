#include "reverse_words_in_a_string.h"

#include <string>

std::string reverseWords(std::string s) {
    std::string result;
    int i = static_cast<int>(s.length()) - 1;

    while (i >= 0) {
        // Skip spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        if (i < 0) {
            break;
        }

        // Find word boundary
        const int j = i;
        while (i >= 0 && s[i] != ' ') {
            i--;
        }

        // Add delimiter and word
        if (!result.empty()) {
            result += ' ';
        }
        result.append(s, i + 1, j - i);
    }

    return result;
}
