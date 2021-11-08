#pragma once

#include <string>
#include <map>

namespace HipHop {

    enum class Game
    {
        ScoobyNightOf100Frights,
        BattleForBikiniBottom,
        SpongeBobMovie,
        Incredibles,
        RiseOfTheUnderminer,

        Count,
        Unknown = -1
    };

    inline std::string GameToString(Game game)
    {
        switch (game)
        {
        case Game::ScoobyNightOf100Frights: return "Scooby-Doo! Night of 100 Frights";
        case Game::BattleForBikiniBottom: return "SpongeBob SquarePants: Battle for Bikini Bottom";
        case Game::SpongeBobMovie: return "The SpongeBob SquarePants Movie";
        case Game::Incredibles: return "The Incredibles";
        case Game::RiseOfTheUnderminer: return "The Incredibles: Rise of the Underminer";
        case Game::Unknown: return "Unknown";
        default: return "";
        }
    }

    inline Game GameFromString(const std::string& str)
    {
        static std::map<std::string, Game> gameMap =
        {
            { "Scooby-Doo! Night of 100 Frights", Game::ScoobyNightOf100Frights },
            { "SpongeBob SquarePants: Battle for Bikini Bottom", Game::BattleForBikiniBottom },
            { "The SpongeBob SquarePants Movie", Game::SpongeBobMovie },
            { "The Incredibles", Game::Incredibles },
            { "The Incredibles: Rise of the Underminer", Game::Unknown }
        };

        return (gameMap.find(str) != gameMap.end()) ? gameMap[str] : Game::Unknown;
    }

}