#ifndef PARSING_H
#define PARSING_H

#include "structs.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

std::vector<Pallet> parsePallets(const std::string &file, int n_pallets);
std::pair<int, int> parseTruck(const std::string &file);

#endif //PARSING_H
