#include "length_of_last_word.h"

#include <string>

int lengthOfLastWord(const std::string& s) {
    int i = static_cast<int>(s.length()) - 1;
    int len = 0;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        --i;
    }

    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        ++len;
        --i;
    }

    return len;
}
