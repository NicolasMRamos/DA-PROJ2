//
// Created by Nicolas Magalhães on 10/04/2025.
//

#ifndef STRUCTS_H

#include <vector>

struct Pallet {
  int id;
  int weight;
  int profit;
};

struct Truck {
  int capacity;
  std::vector<Pallet> pallets;
};

#define STRUCTS_H

#endif //STRUCTS_H
