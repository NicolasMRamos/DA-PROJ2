/**
* @file structs.h
 * @brief Contains data structures for representing pallets and trucks.
 */

#ifndef STRUCTS_H

#define STRUCTS_H
#include <vector>

/**
 * @struct Pallet
 * @brief Represents a pallet with an identifier, weight, and associated profit.
 */
struct Pallet {
  int id;
  int weight;
  int profit;
};

/**
 * @struct Truck
 * @brief Represents a truck with a given capacity and a list of pallets it carries.
 */
struct Truck {
  int capacity;
  std::vector<Pallet> pallets;
};

/**
 * @brief Comparison operator for sorting pallets by weight.
 *
 * @param lhs Left-hand side pallet.
 * @param rhs Right-hand side pallet.
 * @return true if lhs has smaller weight than rhs, false otherwise.
 */
inline bool operator<(const Pallet &lhs, const Pallet &rhs) {
  return lhs.weight < rhs.weight;
}

#endif //STRUCTS_H
