#ifndef ILP_H
#define ILP_H

#include <utility>
#include <vector>

#include "structs.h"

/**
 * @brief Solves the 0/1 Knapsack problem using integer linear programming.
 *
 * This function applies the ILP algorithm to solve the Knapsack problem.
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

std::pair<int, std::vector<int>> ilpApproach(std::vector<Pallet> &pallets, int capacity);

#endif //ILP_H
