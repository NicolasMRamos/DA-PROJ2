#include "menu.h"

int main_menu(){

    std::cout << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "[1] Load dataset" << std::endl;
    std::cout << "[2] Choose algorithmic approach" << std::endl;
    std::cout << "[3] See loaded settings" << std::endl;
    std::cout << "[4] Run Program" << std::endl;
    std::cout << "[5] Exit Program" << std::endl;

    int number;
    std::cin >> number;

    return number;
}

int approaches(){

    std::cout << std::endl;
    std::cout << "Choose an approach:" << std::endl;
    std::cout << "[1] Brute-Force + Backtracking" << std::endl;
    std::cout << "[2] Greedy" << std::endl;
    std::cout << "[3] Dynamic Programming" << std::endl;
    std::cout << "[4] ILP" << std::endl;

    int number;
    std::cin >> number;

    return number;
}

void loadDataset(const int dataset, std::string &filenameTruck, std::string &filenamePallets, std::string &number, std::pair<int, int> &capPal, std::vector<Pallet> &pallets, bool &dataset_loaded) {

    if (dataset < 1 || dataset > 10) {
        std::cout << std::endl;
        std::cout << "Invalid dataset id. Try again." << std::endl;
    } else {
        if (dataset < 10) {
            number = '0' + std::to_string(dataset);
        }
        else if (dataset == 10) {
            number = std::to_string(dataset);
        }

        filenameTruck = "../data/TruckAndPallets_" + number + ".csv";
        filenamePallets = "../data/Pallets_" + number + ".csv";

        capPal = parseTruck(filenameTruck);
        pallets = parsePallets(filenamePallets, capPal.second);

        dataset_loaded = true;
    }
}

void showSettings(const std::string& number, const bool dataset_loaded, bool &approach_selected, const int approach) {

    if (dataset_loaded) {
        std::cout << std::endl;
        std::cout << "Loaded truck:" << std::endl;
        std::cout << "TruckAndPallets_" + number + ".csv" << std::endl;
        std::cout << "Loaded pallets:" << std::endl;
        std::cout << "Pallets_" + number + ".csv" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "No dataset loaded." << std::endl;
    }

    if (approach_selected) {
        std::cout << std::endl;
        std::cout << "Approach selected:" << std::endl;
        if (approach == 1) {
            std::cout << "Brute Force + Backtracking" << std::endl;
        } else if (approach == 2) {
            std::cout << "Greedy" << std::endl;
        } else if (approach == 3) {
            std::cout << "Dynamic Programming" << std::endl;
        } else if (approach == 4) {
            std::cout << "ILP" << std::endl;
        } else {
            std::cout << "Invalid approach selected. Try again." << std::endl;
            approach_selected = false;
        }
    } else {
        std::cout << std::endl;
        std::cout << "No approach selected." << std::endl;
    }
}

void run(const int approach, const std::pair<int, int> &capPal, std::vector<Pallet> pallets, const bool approach_selected, const bool dataset_loaded) {

    if (approach_selected && dataset_loaded) {

        std::pair<int, std::vector<int>> result;

        if (approach == 1) {
            result = backtrackingApproach(pallets, capPal.first);
        } else if (approach == 2) {
            result = greedyApproach(pallets, capPal.first);
        } else if (approach == 3) {
            result = dpApproach(pallets, capPal.first);
        } else if (approach == 4) {
            result = ilpApproach(pallets, capPal.first);
        }

        std::cout << std::endl;
        std::cout << "Total profit: " << result.first << '\n';
        std::cout << "Pallets: ";
        for (const auto i:result.second) {
            std::cout << i << ' ';
        }
        std::cout << '\n';

    } else {
        std::cout << std::endl;
        std::cout << "No dataset loaded and/or approach selected. Try again after loading a dataset and selecting an approach." << std::endl;
    }
}