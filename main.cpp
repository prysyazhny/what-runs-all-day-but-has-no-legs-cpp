#include <iostream>
#include <ctime>
#include <thread>

#include "src/timer.hpp"

std::time_t get_the_system_time()
{
  return std::time(nullptr);
}
void wait_for_a_few_seconds()
{
  std::cout << "\nWaiting for 3 seconds\n" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
}

void compare_the_times(std::time_t start_time, std::time_t end_time, std::chrono::duration<double> elapsed)
{
  std::cout << "Start time: " << std::ctime(&start_time);
  std::cout << "End time: " << std::ctime(&end_time);
  std::cout << "Elapsed time (Timer): " << elapsed.count() << " seconds" << std::endl;
  double diff = elapsed.count() - difftime(end_time, start_time);
  std::cout << "Difference: " << diff << " seconds" << std::endl;
}

int main()
{
  Timer timer;
  std::time_t current_time_1 = get_the_system_time();
  timer.start();
  wait_for_a_few_seconds();
  timer.stop();
  std::time_t current_time_2 = get_the_system_time();
  compare_the_times(current_time_1, current_time_2, timer.get_elapsed_time());
  std::cout << std::endl;
  return 0;
}

