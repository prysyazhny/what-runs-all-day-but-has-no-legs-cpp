#include <string>

class Timer
{
    public:
        std::chrono::time_point<std::chrono::high_resolution_clock> a;
        std::chrono::time_point<std::chrono::high_resolution_clock> b;
        std::chrono::duration<double> elapsed_time;
        void start();
        void stop();
        std::chrono::duration<double> get_elapsed_time() const;
};