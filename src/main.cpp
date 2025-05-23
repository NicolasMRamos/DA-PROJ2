/**
* @file main.cpp
 * @brief Entry point of the application that allows the user to load datasets,
 *        select algorithmic approaches, and execute optimization logic.
 *
 * This application simulates the loading and selection of pallets for a truck
 * based on various algorithmic strategies. It includes a user-driven menu system,
 * supports multiple datasets and the following approaches:
 * Brute Force, Greedy, Dynamic Programming and ILP.
 */

#include "menu.h"

int main(){
  bool approach_selected = false, dataset_loaded = false;
  int approach = 0, option, dataset;
  std::string number, filenameTruck, filenamePallets;
  std::pair<int, int> capPal;
  std::vector<Pallet> pallets;

  while (true) {
    option = main_menu();

    if (option == 1) {

      std::cout << std::endl;
      std::cout << "Insert dataset id:" << std::endl;
      std::cin >> dataset;

      loadDataset(dataset, filenameTruck, filenamePallets, number, capPal, pallets, dataset_loaded);

    } else if (option == 2) {

      approach = approaches();

      approach_selected = true;

    } else if (option == 3) {

      showSettings(number, dataset_loaded, approach_selected, approach);

    } else if (option == 4) {

      run(approach, capPal, pallets, approach_selected, dataset_loaded);

    } else if (option == 5) {

      break;

    } else {
      std::cout << std::endl;
      std::cout << "Invalid option selected." << std::endl;
    }

  }

  return 0;
}
