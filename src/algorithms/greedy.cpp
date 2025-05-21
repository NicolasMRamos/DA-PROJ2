#include "greedy.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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