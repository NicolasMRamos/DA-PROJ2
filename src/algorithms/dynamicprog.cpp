#include "dynamicprog.h"

std::pair<int, std::vector<int>> dpApproach(const std::vector<Pallet>& pallets, int capacity) {
    int n = pallets.size();
    std::vector dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (pallets[i - 1].weight <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - pallets[i - 1].weight] + pallets[i - 1].profit);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    std::vector<int> selected;
    int w = capacity;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(pallets[i - 1].id);
            w -= pallets[i - 1].weight;
        }
    }

    return {dp[n][capacity], selected};
}
