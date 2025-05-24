#include "backtracking.h"

std::pair<int, std::vector<int>> backtrackingAux(const std::vector<Pallet> &pallets, int currentValue, int remainingCapacity, const std::vector<int> &state, int element) {
    std::vector<int> left = state;
    std::vector<int> right = state;

    if (element >= pallets.size() || pallets[element].weight > remainingCapacity) {
        return {currentValue, left};
    }

    right.push_back(pallets[element].id);
    std::pair<int, std::vector<int>> resultLeft = backtrackingAux(pallets, currentValue, remainingCapacity, left, element + 1);
    std::pair<int, std::vector<int>> resultRight = backtrackingAux(pallets, currentValue + pallets[element].profit, remainingCapacity - pallets[element].weight, right, element + 1);

    if (resultLeft.first > resultRight.first) {
        return {resultLeft.first, resultLeft.second};
    }
    return {resultRight.first, resultRight.second};
}

std::pair<int, std::vector<int>> backtrackingApproach(const std::vector<Pallet> &pallets, int capacity) {
    std::vector<int> left;
    std::vector<int> right;
    std::vector<Pallet> sorted_pallets = pallets;
    std::sort(sorted_pallets.begin(), sorted_pallets.end());
    int element = 0;

    if ( element >= pallets.size() || sorted_pallets[element].weight > capacity) {
        return {0, left};
    }

    right.push_back(sorted_pallets[element].id);

    std::pair<int, std::vector<int>> resultLeft = backtrackingAux(sorted_pallets, 0, capacity, left, element + 1);
    std::pair<int, std::vector<int>> resultRight = backtrackingAux(sorted_pallets, sorted_pallets[element].profit, capacity - sorted_pallets[element].weight, right, element + 1);

    if (resultLeft.first > resultRight.first) {
        return {resultLeft.first, resultLeft.second};
    }
    return {resultRight.first, resultRight.second};
}


