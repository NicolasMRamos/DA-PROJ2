/**
* @file menu.h
 * @brief Declares functions for user interface menus.
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "parsing.h"
#include "greedy.h"
#include "backtracking.h"
#include "dynamicprog.h"
#include "ilp.h"

/**
 * @brief Displays the main menu and prompts the user for a selection.
 *
 * @return The integer corresponding to the user's menu choice.
 *
 * Options:
 * - [1] Load dataset
 * - [2] Choose algorithmic approach
 * - [3] See loaded settings
 * - [4] Run Program
 * - [5] Exit Program
 */
int main_menu();

/**
 * @brief Displays the algorithm selection menu and prompts the user for a choice.
 *
 * @return The integer corresponding to the chosen algorithm.
 *
 * Options:
 * - [1] Brute-Force + Backtracking
 * - [2] Greedy
 * - [3] Dynamic Programming
 * - [4] ILP
 */
int approaches();

/**
 * @brief Loads the dataset (truck and pallets) from CSV files based on dataset ID.
 *
 * @param dataset The dataset ID to load (should be between 1 and 10).
 * @param filenameTruck Reference to the filename for the truck data.
 * @param filenamePallets Reference to the filename for the pallets data.
 * @param number Reference to the formatted dataset number string.
 * @param capPal Reference to the pair containing truck capacity and pallet count.
 * @param pallets Reference to the vector where parsed pallets will be stored.
 * @param dataset_loaded Reference to the flag that will be set to true if dataset is successfully loaded.
 */
void loadDataset(int dataset, std::string &filenameTruck, std::string &filenamePallets, std::string &number, std::pair<int, int> &capPal, std::vector<Pallet> &pallets, bool &dataset_loaded);

/**
 * @brief Displays the currently loaded dataset and selected algorithm approach.
 *
 * @param number The formatted dataset number string.
 * @param dataset_loaded Flag indicating if a dataset is loaded.
 * @param approach_selected Reference to the flag that is true if an approach has been selected.
 * @param approach The currently selected algorithm approach.
 */
void showSettings(const std::string& number, bool dataset_loaded, bool &approach_selected, int approach);

/**
 * @brief Runs the selected algorithmic approach on the loaded dataset.
 *
 * @param approach The chosen algorithm approach.
 * @param capPal Pair containing the truck's capacity and the number of pallets.
 * @param pallets Vector of loaded pallet data.
 * @param approach_selected Flag indicating if an approach has been selected.
 * @param dataset_loaded Flag indicating if a dataset is loaded.
 */
void run(int approach, const std::pair<int, int> &capPal, std::vector<Pallet> pallets, bool approach_selected, bool dataset_loaded);

#endif //MENU_H
