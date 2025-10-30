#include <string>
#include <ctime>
#include <chrono>
#include <iostream>

#include "timer.hpp"

void Timer::start() {
   started = true;
   a = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
   try {
       if (!started) {
           throw std::string("Timer was not started. Cannot stop.");
       }
   } catch (const std::string& msg) {
       std::cerr << msg << std::endl;
       return;
   }
   b = std::chrono::high_resolution_clock::now();
   started = false;
}

std::chrono::duration<double> Timer::get_elapsed_time() const {
   if (!started) {
       std::cerr << "Timer was not started. Cannot get elapsed time." << std::endl;
       return std::chrono::duration<double>::zero();
   }
   return std::chrono::duration_cast<std::chrono::duration<double>>(b - a);
}
