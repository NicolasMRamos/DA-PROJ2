#include "parsing.h"

std::vector<Pallet> parsePallets(const std::string & file, int n_pallets) {
    Pallet pallet{};
    std::vector<Pallet> result(n_pallets);
    std::string line;
    std::ifstream f;
    f.open(file);

    if (!f.is_open()) {
        std::cerr << "No file found.\n";
        return result;
    }

    getline(f, line);

    while (getline(f, line)) {

        if (line.find(',') == std::string::npos) continue;
        size_t separator = line.find(',');
        pallet.id = stoi(line.substr(0, separator));
        line.erase(0, separator + 1);

        separator = line.find(',');
        pallet.weight = stoi(line.substr(0, separator));
        line.erase(0, separator + 1);

        separator = line.find(',');
        pallet.profit = stoi(line.substr(0, separator));

        result[pallet.id - 1] = pallet;
    }

    f.close();
    return result;
}

std::pair<int, int> parseTruck(const std::string &file) {
    std::pair<int, int> info{};

    std::string line;
    std::ifstream f;
    f.open(file);

    if (!f.is_open()) {
        std::cerr << "No file found.\n";
        return info;
    }

    getline(f, line);
    getline(f, line);

    //Capacity
    size_t separator = line.find(',');
    info.first = stoi(line.substr(0, separator));
    line.erase(0, separator + 1);

    //number of Pallets
    separator = line.find(',');
    info.second = stoi(line.substr(0, separator));

    return info;
}
