#include "dynamicprog.h"
#include <vector>
#include <algorithm>
#include "structs.h"

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

pair<int, vector<int>> dpApproach(const vector<Pallet>& pallets, int capacity) {
    int n = pallets.size();
    vector dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (pallets[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - pallets[i - 1].weight] + pallets[i - 1].profit);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to determine which pallets were used
    vector<int> selected;
    int w = capacity;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(pallets[i - 1].id);
            w -= pallets[i - 1].weight;
        }
    }

    return {dp[n][capacity], selected};
}
