#pragma once

#include <string>
#include <map>

namespace HipHop {

    enum class Platform
    {
        GameCube,
        PS2,
        Xbox,

        Count,
        Unknown = -1
    };

    inline std::string PlatformToString(Platform platform)
    {
        switch (platform)
        {
        case Platform::GameCube: return "GameCube";
        case Platform::PS2: return "PlayStation 2";
        case Platform::Xbox: return "Xbox";
        default: return "";
        }
    }

    inline Platform PlatformFromString(const std::string& str)
    {
        static std::map<std::string, Platform> platformMap =
        {
            { "GameCube", Platform::GameCube },
            { "PlayStation 2", Platform::PS2 },
            { "Xbox", Platform::Xbox }
        };

        return (platformMap.find(str) != platformMap.end()) ? platformMap[str] : Platform::Unknown;
    }

}