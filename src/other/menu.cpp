#include "menu.h"

int main_menu(){

    std::cout << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "[1] Load dataset" << std::endl;
    std::cout << "[2] Choose algorithmic approach" << std::endl;
    std::cout << "[3] See loaded settings" << std::endl;
    std::cout << "[4] Run Program" << std::endl;
    std::cout << "[5] Exit Program" << std::endl;

    int number;
    std::cin >> number;

    return number;
}

int approaches(){

    std::cout << std::endl;
    std::cout << "Choose an approach:" << std::endl;
    std::cout << "[1] Brute-Force + Backtracking" << std::endl;
    std::cout << "[2] Greedy" << std::endl;
    std::cout << "[3] Dynamic Programming" << std::endl;
    std::cout << "[4] ILP" << std::endl;

    int number;
    std::cin >> number;

    return number;
}

