#pragma once

#include <string>
#include <map>

namespace HipHop {

    enum class Region
    {
        NTSC,
        PAL,

        Count,
        Unknown = -1
    };

    inline std::string RegionToString(Region region)
    {
        switch (region)
        {
        case Region::NTSC: return "NTSC";
        case Region::PAL: return "PAL";
        default: return "";
        }
    }

    inline Region RegionFromString(const std::string& str)
    {
        static std::map<std::string, Region> regionMap =
        {
            { "NTSC", Region::NTSC },
            { "PAL", Region::PAL }
        };

        return (regionMap.find(str) != regionMap.end()) ? regionMap[str] : Region::Unknown;
    }

}