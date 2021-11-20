#pragma once

#include "hiphop/core/base_asset.h"

namespace HipHop {

    struct FogAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::FOG);

        uint8_t bkgndColor[4] = { 0, 0, 0, 255 };
        uint8_t fogColor[4] = { 0, 0, 0, 255 };
        float fogDensity = 0.0f;
        float fogStart = 0.0f;
        float fogStop = 0.0f;
        float transitionTime = 0.0f;
        uint8_t fogType = 0;

        FogAsset(Asset asset) : BaseAsset(asset, BaseType::Fog) {}

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}