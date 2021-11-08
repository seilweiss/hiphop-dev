#pragma once

#include <string>
#include <map>

namespace HipHop {

    enum class Language
    {
        USCommon,
        UnitedKingdom,
        French,
        German,

        US,
        BE,
        CH,
        CZ,
        DE,
        DK,
        ES,
        FI,
        FR,
        IT,
        JP,
        KR,
        NL,
        NO,
        PL,
        PT,
        RU,
        SE,
        SK,
        TW,
        UK,

        Count,
        Unknown = -1,
    };

    inline std::string LanguageToString(Language language)
    {
        switch (language)
        {
        case Language::USCommon: return "US Common";
        case Language::UnitedKingdom: return "United Kingdom";
        case Language::French: return "French";
        case Language::German: return "German";
        case Language::US: return "US";
        case Language::BE: return "BE";
        case Language::CH: return "CH";
        case Language::CZ: return "CZ";
        case Language::DE: return "DE";
        case Language::DK: return "DK";
        case Language::ES: return "ES";
        case Language::FI: return "FI";
        case Language::FR: return "FR";
        case Language::IT: return "IT";
        case Language::JP: return "JP";
        case Language::KR: return "KR";
        case Language::NL: return "NL";
        case Language::NO: return "NO";
        case Language::PL: return "PL";
        case Language::PT: return "PT";
        case Language::RU: return "RU";
        case Language::SE: return "SE";
        case Language::SK: return "SK";
        case Language::TW: return "TW";
        case Language::UK: return "UK";
        default: return "";
        }
    }

    inline Language LanguageFromString(const std::string& str)
    {
        static std::map<std::string, Language> languageMap =
        {
            { "US Common", Language::USCommon },
            { "United Kingdom", Language::UnitedKingdom },
            { "French", Language::French },
            { "German", Language::German },
            { "US", Language::US },
            { "BE", Language::BE },
            { "CH", Language::CH },
            { "CZ", Language::CZ },
            { "DE", Language::DE },
            { "DK", Language::DK },
            { "ES", Language::ES },
            { "FI", Language::FI },
            { "FR", Language::FR },
            { "IT", Language::IT },
            { "JP", Language::JP },
            { "KR", Language::KR },
            { "NL", Language::NL },
            { "NO", Language::NO },
            { "PL", Language::PL },
            { "PT", Language::PT },
            { "RU", Language::RU },
            { "SE", Language::SE },
            { "SK", Language::SK },
            { "TW", Language::TW },
            { "UK", Language::UK }
        };

        return (languageMap.find(str) != languageMap.end()) ? languageMap[str] : Language::Unknown;
    }

}