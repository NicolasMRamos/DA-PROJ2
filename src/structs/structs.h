//
// Created by Nicolas Magalhães on 10/04/2025.
//

#ifndef STRUCTS_H

#include <vector>

struct Pallet {
  int weight;
  int profit;
}

struct Truck {
  int capacity;
  std::vector<Pallet>;
}

#define STRUCTS_H

#endif //STRUCTS_H
