#include "brace_expansion.h"

#include <algorithm>
#include <cstddef>
#include <regex>
#include <string>
#include <utility>
#include <vector>

namespace {

std::vector<std::string> splitByComma(const std::string& str) {
    std::vector<std::string> out;
    std::size_t start = 0;
    while (true) {
        const std::size_t pos = str.find(',', start);
        if (pos == std::string::npos) {
            out.emplace_back(str.substr(start));
            break;
        }
        out.emplace_back(str.substr(start, pos - start));
        start = pos + 1;
    }
    return out;
}

}  // namespace

std::vector<std::string> braceExpansion(const std::string& input) {
    std::vector<std::string> prefixes;
    prefixes.emplace_back("");  // Start with an empty prefix
    std::string remaining = input;

    // Regex captures (compile once; reuse):
    // 1) leading literal before {   ([^{}]*)
    // 2) choices inside {}          ([^}]*)
    // 3) literal after }            ([^{}]*)
    // 4) remaining tail             (.*)
    static const std::regex REGEX(R"(([^{}]*)\{([^}]*)\}([^{}]*)(.*))");

    std::smatch match;
    // Iterate group by group until no more braces
    while (std::regex_match(remaining, match, REGEX)) {
        const std::string& lead = match[1].str();
        const std::string& choicesStr = match[2].str();
        const std::string& mid = match[3].str();
        std::string tail = match[4].str();  // will become new remaining

        // Expand choices and sort them
        std::vector<std::string> choices = splitByComma(choicesStr);
        if (choices.size() > 1) {
            std::ranges::sort(choices);
        }

        std::vector<std::string> newPrefixes;
        newPrefixes.reserve(prefixes.size() * std::max(choices.size(), 1UL));
        for (const auto& prefix : prefixes) {
            for (const auto& choice : choices) {
                std::string newPrefix = prefix;
                newPrefix += lead;
                newPrefix += choice;
                newPrefix += mid;
                newPrefixes.emplace_back(std::move(newPrefix));
            }
        }

        prefixes.swap(newPrefixes);  // reuse memory
        remaining.swap(tail);        // continue with the tail
    }

    // Append final remaining tail (no more braces)
    std::vector<std::string> results;
    results.reserve(prefixes.size());
    if (!prefixes.empty()) {
        for (const auto& prefix : prefixes) {
            std::string result = prefix;
            result += remaining;
            results.emplace_back(std::move(result));
        }
    } else {
        results.emplace_back(remaining);  // input had no braces
    }

    return results;
}
