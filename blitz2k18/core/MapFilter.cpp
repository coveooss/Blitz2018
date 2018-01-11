#include "MapFilter.hpp"
#include "PerformanceTimer.hpp"
#include <algorithm>
#include <set>

blitz::Map filterMap(const blitz::Map &map, int distance, int player) {
    PROFILE_FUNCTION();
    std::vector<blitz::Location> ownedSite;
    for(unsigned short i=0; i<map.contents.size(); ++i) {
        for(unsigned short j=0; j<map.contents.size(); ++j) {
            if(map.contents[i][j].owner == player) {
                ownedSite.push_back({i, j});
            }
        }
    }

    //Copy the current map
    blitz::Map visionMap(map);

    //Zero out what is not visible
     for(unsigned short i=0; i<map.contents.size(); ++i) {
		for(unsigned short j=0; j<map.contents.size(); ++j) {
			if(map.contents[i][j].owner != player) {
                auto result = std::find_if(
                        std::begin(ownedSite),
                        std::end(ownedSite),
                        [&](const blitz::Location& l1) { return map.getDistance(l1, {i, j}) <= distance; });
                if(result == std::end(ownedSite)) {
                visionMap.contents[i][j] = {0, 0, 0};
                }
            }
        }
    }
    return visionMap;
}
