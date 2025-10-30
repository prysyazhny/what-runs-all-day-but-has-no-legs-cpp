#include <string>
#include <ctime>
#include <chrono>

#include "timer.hpp"

void Timer::start() {
   a = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
   b = std::chrono::high_resolution_clock::now();
   elapsed_time = b - a;
}

std::chrono::duration<double> Timer::get_elapsed_time() const {
    return elapsed_time;
}
