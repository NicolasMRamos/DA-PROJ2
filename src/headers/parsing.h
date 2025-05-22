//
// Created by Nicolas Magalhães on 10/04/2025.
//

#ifndef PARSING_H
#define PARSING_H

#include <string>
#include <vector>
#include "../structs/structs.h"



std::vector<Pallet> parsePallets(const std::string &file, int n_pallets);
std::pair<int, int> parseTruck(const std::string &file);

#endif //PARSING_H
