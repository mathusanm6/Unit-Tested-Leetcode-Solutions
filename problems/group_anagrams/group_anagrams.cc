#include "group_anagrams.h"

#include <algorithm>
#include <ranges>  // NOLINT(misc-include-cleaner) needed for std::ranges::sort
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    groups.reserve(strs.size());

    for (const string& s : strs) {
        string key = s;
        std::ranges::sort(key);  // anagrams share the same sorted key
        groups[key].push_back(s);
    }

    vector<vector<string>> res;
    res.reserve(groups.size());
    for (auto& [k, v] : groups) {
        res.push_back(std::move(v));
    }
    return res;
}