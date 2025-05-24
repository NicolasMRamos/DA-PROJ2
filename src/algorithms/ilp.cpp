#include "ilp.h"

#include <fstream>
#include <iostream>

std::pair<int, std::vector<int>> ilpApproach(std::vector<Pallet> &pallets, int capacity) {
    std::pair<int, std::vector<int>> result;
    std::ofstream file("../src/input.txt");
    file << pallets.size() << '\n' << capacity << '\n';
    for (int i = 0; i < pallets.size(); i++)
        file << pallets[i].weight << ' ';

    file << '\n';
    for (int i = 0; i < pallets.size(); i++)
        file << pallets[i].profit << ' ';

    file.close();
    int ret = system("../venv/bin/python ../src/knapsack_solver.py ../src/input.txt ../src/output.txt");

    if (ret) {
        std::cerr << "Solver failed\n";
        return {};
    }

    std::ifstream fileIn("../src/output.txt");

    fileIn >> result.first;
    int weight;
    fileIn >> weight;

    int id;
    while (fileIn >> id) {
        result.second.push_back(id);
    }

    return result;
}
