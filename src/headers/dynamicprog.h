/**
* @file dynamicprog.h
 * @brief Header for the dynamic programming algorithm implementation of the 0/1 Knapsack problem.
 */

#ifndef DYNAMICPROG_H
#define DYNAMICPROG_H

#include "structs.h"
#include <vector>

using namespace std;

/**
 * @brief Solves the 0/1 Knapsack problem using dynamic programming.
 *
 * This function uses a bottom-up dynamic programming approach to find the most profitable subset
 * of pallets that can be carried by the truck without exceeding its weight capacity. It builds a
 * DP table to compute the maximum profit for each subproblem and then backtracks to determine the
 * items that were included in the optimal solution.
 *
 * @param pallets A vector of `Pallet` objects, each with `id`, `weight`, and `profit` fields.
 * @param capacity The maximum weight capacity of the truck.
 * @return A `pair` where:
 *         - `first` is the total profit of the selected pallets.
 *         - `second` is a vector of IDs of the selected pallets that were chosen in the optimal solution.
 *
 * @note Time complexity: O(n * W), where `n` is the number of pallets and `W` is the truck capacity.
 * @note Space complexity: O(n * W) due to the DP table.
 */

pair<int, vector<int>> dpApproach(const vector<Pallet>& pallets, int capacity);

#endif //DYNAMICPROG_H
