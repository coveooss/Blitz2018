#include "PerformanceTimer.hpp"

#ifdef _COVEO_PROFILE_FILTERMAP

namespace coveo {

PerformanceTimer::~PerformanceTimer()
{
	DumpStats();
}
	
PerformanceTimer& PerformanceTimer::GetInstance()
{
	static PerformanceTimer perfTimer;
	return perfTimer;
}
	
void PerformanceTimer::AddTime(std::chrono::microseconds duration)
{
	std::lock_guard<std::mutex> lock(mutex);
    vDurations.push_back(duration);
}

void PerformanceTimer::DumpStats()
{
	long long maxValue = 0l, totalValue = 0l;
	for (auto duration : vDurations) {
		maxValue = std::max(maxValue, duration.count());
		totalValue += duration.count();
	}

	if (!vDurations.empty()) {
		std::cout << "Average duration: " << totalValue / vDurations.size() << "µs\n"
				<< "Max duration: " << maxValue << "µs\n";	
	}
}

} // namespace coveo

#endif
