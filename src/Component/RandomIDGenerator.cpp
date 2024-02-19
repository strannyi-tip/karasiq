//
// Created by strannyi_tip on 29.10.23.
//

#include <random>
#include <iostream>
#include <limits>
#include "Component/RandomIDGenerator.hpp"

int Component::RandomIDGenerator::generate() {
    std::random_device rd;
    std::mt19937 mt(rd());
    auto limit = std::numeric_limits<int>::max();
    std::uniform_int_distribution<int> uniform_dist(1, limit);

    return uniform_dist(mt);
}

int Component::RandomIDGenerator::range(int min, int max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min,max);

    return static_cast<int>(dist(rng));
}

