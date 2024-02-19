//
// Created by strannyi_tip on 22.12.23.
//
#include "Component/SequentlyIDGenerator.hpp"

int Component::SequentlyIDGenerator::generate(bool start_of_zero) {
    if (0 == id && start_of_zero) {
        id++;

        return 0;
    } else {
        return id++;
    }
}

Component::SequentlyIDGenerator *Component::SequentlyIDGenerator::init() {
    if (nullptr == instance) {
        instance = new SequentlyIDGenerator;
    }

    return instance;
}

