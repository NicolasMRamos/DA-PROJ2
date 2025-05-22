#include "bruteforce.h"
#include <cmath>
#include <iostream>

using namespace std;

void increment (vector<bool> &bset) {
    for (size_t i = 0; i < bset.size(); i++) {
        //Adição binária
        if (bset[i] == 0) {
            bset[i] = 1;
            break;
        }

        bset[i] = 0;
    }
}

bool finishedCombs (const vector<bool> &bset) {
    for (auto i:bset) {
        if (i == 0) return false;
    }
    return true;
}

pair<int, vector<int>> bruteForceApproach(vector<Pallet> &pallets, int capacity) {
    pair<int, vector<int>> best = {0, {}};
    vector<bool> combinations(pallets.size());
    bool exit = false;
    bool last_comb = false;
    int run = 0;

    while (!exit) {
        if (finishedCombs(combinations) && !last_comb) {
            last_comb = true;
        }
        else if (last_comb) {
            exit = true;
        }

        int cur_capacity = capacity;
        int cur_value = 0;
        vector<int> cur_solution = {};
        for (int pos = 0; pos < pallets.size(); pos++) {
            if (combinations[pos]) {
                cur_capacity -= pallets[pos].weight;
                cur_value += pallets[pos].profit;
                cur_solution.push_back(pallets[pos].id);
            }
        }

        if (cur_capacity >= 0 && cur_value > best.first) {
            best.first = cur_value;
            best.second = cur_solution;
        }

        increment(combinations);
        run++;
        cout << run << '\n';
    }

    return best;
}
