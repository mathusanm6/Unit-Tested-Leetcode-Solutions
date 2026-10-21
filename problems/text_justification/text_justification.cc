#include "text_justification.h"

#include <algorithm>
#include <cstddef>
#include <string>
#include <utility>
#include <vector>

std::vector<std::string> fullJustify(const std::vector<std::string>& words, int maxWidth) {
    std::vector<std::string> res;
    std::vector<std::string> line;
    int length = 0;

    for (const auto& w : words) {
        if (length + static_cast<int>(line.size()) + static_cast<int>(w.size()) > maxWidth) {
            // Distribute spaces across slots (or slot 0 if 1 word)
            const int slots = std::max(1, static_cast<int>(line.size()) - 1);
            const int spaces = maxWidth - length;
            for (int i = 0; i < spaces; ++i) {
                line[static_cast<std::size_t>(i % slots)] += ' ';
            }

            std::string joined;
            for (const auto& s : line) {
                joined += s;
            }
            res.push_back(std::move(joined));
            line.clear();
            length = 0;  // reset
        }

        line.push_back(w);
        length += static_cast<int>(w.size());
    }

    // Last line
    std::string lastLine;
    for (std::size_t i = 0; i < line.size(); ++i) {
        if (i > 0) {
            lastLine += ' ';
        }
        lastLine += line[i];
    }
    if (lastLine.size() < static_cast<std::size_t>(maxWidth)) {
        lastLine.append(static_cast<std::size_t>(maxWidth) - lastLine.size(), ' ');
    }
    res.push_back(std::move(lastLine));

    return res;
}
