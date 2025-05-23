/**
* @file parsing.h
 * @brief Declares functions for parsing pallet and truck data from files.
 */

#ifndef PARSING_H
#define PARSING_H

#include "structs.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

/**
 * @brief Parses a list of pallets from a CSV file.
 *
 * @param file The path to the CSV file containing pallet data.
 * @param n_pallets The number of pallets expected in the file.
 * @return A vector of Pallet objects parsed from the file.
 *
 * The CSV format should have rows with the format: id,weight,profit
 */
std::vector<Pallet> parsePallets(const std::string &file, int n_pallets);

/**
 * @brief Parses truck information from a CSV file.
 *
 * @param file The path to the CSV file containing truck data.
 * @return A pair where the first element is the truck capacity and the second is the number of pallets.
 *
 * The CSV format should have the second line in the format: capacity,n_pallets
 */
std::pair<int, int> parseTruck(const std::string &file);

#endif //PARSING_H
