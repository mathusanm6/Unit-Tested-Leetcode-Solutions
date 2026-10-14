#include "integer_to_roman.h"

#include <string>
#include <utility>
#include <vector>

std::string intToRoman(int num) {
    const std::vector<std::pair<int, std::string>> valSym = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
        {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"},
    };

    std::string res;

    for (const auto& [val, sym] : valSym) {
        if (num == 0) {
            break;
        }

        for (int count = num / val; count > 0; count--) {
            res += sym;
        }
        num %= val;
    }
    return res;
}
