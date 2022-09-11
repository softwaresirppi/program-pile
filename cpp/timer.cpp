#include <chrono>
#include <iostream>
#include <string>
#include "../potions/timer.hpp"


// 987 612 693
// 012 345 678

std::string prettifyNumber(int64_t x){
  using namespace std;
  string prettyNumber = to_string(x);
  for(int i = 1; i < prettyNumber.size(); ++i){
    if(i % 4 == 0){
      prettyNumber.insert(i, " ");
    }
  }
  return prettyNumber;
}
void Timer::start() {
  std::cout << "Timer starts" << std::endl;
  _start = std::chrono::steady_clock::now();
}

std::chrono::nanoseconds Timer::getTimeElapsed() const {
  return ((std::chrono::steady_clock::now() - _start));
}
void Timer::printTimeElapsed() const {
  std::cout << "Time elapsed: " << prettifyNumber(getTimeElapsed().count()) << " ns" << std::endl;
}


ScopedTimer::ScopedTimer() {
  start();
}
ScopedTimer::~ScopedTimer() {
  printTimeElapsed();
}