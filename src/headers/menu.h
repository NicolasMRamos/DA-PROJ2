/**
* @file menu.h
 * @brief Declares functions for user interface menus.
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>

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

#endif //MENU_H
