#include <iostream>
#include <chrono>
#include <thread>

#include "../potions/robot.hpp"

void backSpace(int times) {
    for (int i = 0; i < times; i++) {
        std::cout << '\b';
    }
}
int Robot::prompt() {
    using namespace std::chrono_literals;
    using namespace std::chrono;
    srand(time(0));
    std::cout << "Ask anything to ROBOT(thats me).\n";
    std::cin.get();
    bool decision = rand() % 2;
    std::cout << "Thinking...";
    std::this_thread::sleep_for((milliseconds(int(rand() % 2500))));
    backSpace(12);
    if (decision == 0) {
        std::cout << "YES.          ";

    } else {
        std::cout << "NO.           ";
    }
    std::cin.get();
    return 0;
}