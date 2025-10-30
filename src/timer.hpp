#include <string>

class Timer
{
    public:
        std::chrono::time_point<std::chrono::high_resolution_clock> a;
        std::chrono::time_point<std::chrono::high_resolution_clock> b;
        bool started = false;
        void start();
        void stop();
        std::chrono::duration<double> get_elapsed_time() const;
};