#include "insert_delete_getrandom_o1.h"

#include <cstddef>
#include <random>

RandomizedSet::RandomizedSet() : rng_(std::random_device{}()) {}

bool RandomizedSet::insert(int val) {
    if (positions_.contains(val)) {
        return false;
    }
    positions_[val] = values_.size();
    values_.push_back(val);
    return true;
}

bool RandomizedSet::remove(int val) {
    const auto it = positions_.find(val);
    if (it == positions_.end()) {
        return false;
    }

    const size_t index = it->second;
    positions_.erase(it);

    const int last = values_.back();
    values_.pop_back();

    if (index < values_.size()) {
        values_[index] = last;
        positions_[last] = index;
    }
    return true;
}

int RandomizedSet::getRandom() {
    std::uniform_int_distribution<size_t> dist(0, values_.size() - 1);
    return values_[dist(rng_)];
}
