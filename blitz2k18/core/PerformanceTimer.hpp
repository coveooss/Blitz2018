#ifndef PERFORMANCE_TIMER_HPP
#define PERFORMANCE_TIMER_HPP

#include "blitz.hpp"

#ifdef _COVEO_PROFILE_FILTERMAP
#	include <chrono>
#   include <vector>

namespace coveo {

class PerformanceTimer {
public:
                                ~PerformanceTimer();

    void                        AddTime(std::chrono::microseconds duration);
    void                        DumpStats();

    static PerformanceTimer&    GetInstance();

private:
                                PerformanceTimer() : mutex(), vDurations() { vDurations.reserve(100000); }
                                
    std::mutex                              mutex;               // Mutex to serialize access to vDurations
    std::vector<std::chrono::microseconds>  vDurations;          // Vector of durations
};
    
class stopwatch {
public:
	stopwatch() : start(std::chrono::high_resolution_clock::now()) {}
	~stopwatch() {
		auto finish = std::chrono::high_resolution_clock::now();
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
        PerformanceTimer::GetInstance().AddTime(microseconds);
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

} // namespace coveo

#	define PROFILE_FUNCTION() coveo::stopwatch sw
#else
#	define PROFILE_FUNCTION()
#endif

#endif // PERFORMANCE_TIMER_HPP
