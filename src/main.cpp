#include <iostream>

#include "menu.h"
#include "parsing.h"
#include "greedy.h"
#include "backtracking.h"
#include "dynamicprog.h"

int main(){
  bool approach_selected = false, dataset_loaded = false;
  int approach, option, dataset;
  std::string number, filenameTruck, filenamePallets;
  std::pair<int, int> capPal;
  std::vector<Pallet> pallets;

  while (true) {
    option = main_menu();

    if (option == 1) {

      std::cout << std::endl;
      std::cout << "Insert dataset id:" << std::endl;
      std::cin >> dataset;

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

    } else if (option == 2) {

      approach = approaches();
      approach_selected = approach;

    } else if (option == 3) {

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

    } else if (option == 4) {

      if (approach_selected && dataset_loaded) {

        std::pair<int, std::vector<int>> result;

        /*
        for (auto i:pallets) {
          std::cout << "Pallet: " << i.id << ' ' << i.weight << ' ' << i.profit << '\n';
        }

        std::cout << "Truck: " << capPal.first << ' ' << capPal.second << '\n';
        */

        if (approach == 1) {
          result = backtrackingApproach(pallets, capPal.first);
        } else if (approach == 2) {
          result = greedyApproach(pallets, capPal.first);
        } else if (approach == 3) {
          result = dpApproach(pallets, capPal.first);
        } else if (approach == 4) {
          std::cout << std::endl;
          std::cout << "ILP placeholder" << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Total profit: " << result.first << '\n';
        std::cout << "Pallets: ";
        for (auto i:result.second)
        {
          std::cout << i << ' ';
        }
        std::cout << '\n';

      } else {
        std::cout << std::endl;
        std::cout << "No dataset loaded and/or approach selected. Try again after loading a dataset and selecting an approach." << std::endl;
      }

    } else if (option == 5) {

      break;

    } else {
      std::cout << std::endl;
      std::cout << "Invalid option selected." << std::endl;
    }

  }

  return 0;
}
