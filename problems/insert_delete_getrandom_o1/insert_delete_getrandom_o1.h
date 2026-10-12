#pragma once

#include <cstddef>
#include <random>
#include <unordered_map>
#include <vector>

class RandomizedSet {
   public:
    RandomizedSet();

    bool insert(int val);
    bool remove(int val);
    int getRandom();

   private:
    std::vector<int> values_;                    // Dense array of values.
    std::unordered_map<int, size_t> positions_;  // Value -> index in values_.
    std::mt19937 rng_;
};
