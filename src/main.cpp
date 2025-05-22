//
// Created by Nicolas Magalhães on 10/04/2025.
//

#include <iostream>

#include "parsing.h"
#include "greedy.h"
#include "bruteforce.h"

int main(){
  int dataset;
  std::cout << "Dataset number:\n";
  std::cin >> dataset;

  std::string number;

  if (dataset < 10) {
    number = '0' + std::to_string(dataset);
  }

  std::string filenameTruck = "../data/TruckAndPallets_" + number + ".csv";
  std::string filenamePallets = "../data/Pallets_" + number + ".csv";

  std::pair<int, int> capPal = parseTruck(filenameTruck);
  std::vector<Pallet> pallets = parsePallets(filenamePallets, capPal.second);

  /*for (auto i:pallets) {
    std::cout << "Pallet: " << i.id << ' ' << i.weight << ' ' << i.profit << '\n';
  }

  std::cout << "Truck: " << capPal.first << ' ' << capPal.second << '\n';*/

  std::cout << "Greedy approach:\n";

  auto result = greedyApproach(pallets, capPal.first);

  std::cout << "Total profit: " << result.first << '\n';
  std::cout << "Pallets: ";
  for (auto i:result.second)
  {
      std::cout << i << ' ';
  }
  std::cout << '\n';
  std::cout << "Brute Force approach:\n";

  result = bruteForceApproach(pallets, capPal.first);

  std::cout << "Total profit: " << result.first << '\n';
  std::cout << "Pallets: ";
  for (auto i:result.second)
  {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}
