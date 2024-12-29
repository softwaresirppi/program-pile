#include <iostream>
#include <ctime>
#include <string>

#include "../potions/guesser.hpp"

// INCLUSIVE 1 - 6
void initRandom() {
    srand(time(NULL));
}

// 10 - 20
int generateRandom(int from, int to) {
    return from + rand() % (to - from + 1);
}
// from 25 - 50. x = 26
bool inRange(int x, int from, int to) {
    return x >= from && x <= to;
    // 26 >= 25 && 26 <= 50
}
int positify(int x) {
    if (x < 0) return -1 * x;
    return x;
}
/*
Error messages and range,
1-9        "you are getting very closee"
10-24       "you are getting closee"
25 - 49     "its somewhat \"close\""
50 - 74     "its kinda AWAY"
75 - 100    "need to go a LOOOONG way, fool!!"
*/
std::string getFailMessage(int error) {
    if (inRange(error, 1, 9)) {
        return "you are getting very closee";
    } else if (inRange(error, 10, 24)) {
        return "you are getting closee";
    } else if (inRange(error, 25, 49)) {
        return "its somewhat \"close\"";
    } else if (inRange(error, 50, 74)) {
        return "its kinda AWAY";
    } else if (inRange(error, 75, 100)) {
        return "need to go a LOOOONG way, fool!!";
    }


    return "I have a peanut-sized brain. You are " + std::to_string(error) + " away";
}
std::string getWinMessage() {
    return "FINALLY you have guessed.";
}
int Guesser::run() {
    initRandom();
    int number = generateRandom(0, 99);
    std::cout << "A number is GENERATED from 0 to 99 " << std::endl;
    int guess = 0;
    do {
        std::cout << "Try to guess it : ";
        std::cin >> guess;
        if (guess != number) {
            std::cout << getFailMessage(positify(number - guess)) << std::endl;
        } else {
            std::cout << getWinMessage();
        }
    } while (guess != number);
    std::cin.get();
    return 0;
}