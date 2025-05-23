/**
 * @file greedy.h
 * @brief Header for the greedy algorithm implementation of the 0/1 Knapsack problem.
 */

#ifndef GREEDY_H
#define GREEDY_H

#include "structs.h"
#include <vector>
#include <algorithm>

/**
 * @brief Solves the 0/1 Knapsack problem using a greedy approach.
 *
 * The algorithm selects pallets based on their profit-to-weight ratio, prioritizing
 * items that offer the highest value per unit weight. This provides a suboptimal
 * but efficient solution.
 *
 * @param pallets Reference to a vector of `Pallet` objects (defined in `structs.h`).
 *                Each pallet must have `id`, `weight`, and `profit` fields.
 * @param capacity Maximum weight capacity of the truck.
 * @return A `std::pair` where:
 *         - `first` is the total profit of selected pallets.
 *         - `second` is a vector of IDs of the selected pallets.
 *
 * @note Time complexity: O(n log n) due to sorting.
 * @note Space complexity: O(n) for storing intermediate data.
 * @see greedy.cpp for the implementation.
 */

std::pair<int, std::vector<int>> greedyApproach(std::vector<Pallet> &pallets, int capacity);

#endif //GREEDY_H
