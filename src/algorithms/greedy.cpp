#include "greedy.h"
#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief Solves the 0/1 Knapsack problem using a greedy approach based on profit-to-weight ratio.
 *
 * This function selects pallets by prioritizing those with the highest profit-to-weight ratio,
 * packing them into the truck until the capacity is exhausted. The solution is suboptimal but efficient.
 *
 * @param pallets A vector of `Pallet` objects, each with `id`, `weight`, and `profit` fields.
 * @param capacity The maximum weight capacity of the truck.
 * @return A `pair` where:
 *         - `first` is the total profit of the selected pallets.
 *         - `second` is a vector of IDs of the selected pallets.
 *
 * @note Time complexity: O(n log n) due to sorting, where `n` is the number of pallets.
 * @note Space complexity: O(n) for storing the ratios and selected pallets.
 */

std::pair<int, vector<int>> greedyApproach(vector<Pallet> &pallets, int capacity) {
    std::vector<std::pair<double, int>> ratios(pallets.size());
    for (int i = 0; i < pallets.size(); ++i) {
        ratios[i] = {static_cast<double>(pallets[i].profit) / pallets[i].weight, i};
    }

    std::sort(ratios.rbegin(), ratios.rend());

    int totalProfit = 0;
    std::vector<int> selectedPallets;

    for (const auto &ratio : ratios) {
        int index = ratio.second;
        if (pallets[index].weight <= capacity) {
            selectedPallets.push_back(pallets[index].id);
            totalProfit += pallets[index].profit;
            capacity -= pallets[index].weight;
        }
    }

    return {totalProfit, selectedPallets};
}