#ifndef STRUCTS_H

#define STRUCTS_H
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

inline bool operator<(const Pallet &lhs, const Pallet &rhs) {
  return lhs.weight < rhs.weight;
}

#endif //STRUCTS_H
