#pragma once

#include "hiphop/core/base_asset.h"
#include "hiphop/core/math.h"

namespace HipHop {

    struct EnvAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::ENV);

        EnvAsset(Asset asset) : BaseAsset(asset, BaseType::Env) {}

		uint32_t bspAssetID = 0;
		uint32_t startCameraAssetID = 0;
		uint32_t climateFlags = 0;
		float climateStrengthMin = 0.0f;
		float climateStrengthMax = 0.0f;
		uint32_t bspLightKit = 0;
		uint32_t objectLightKit = 0;
		uint32_t flags = 0;
		uint32_t bspCollisionAssetID = 0;
		uint32_t bspFXAssetID = 0;
		uint32_t bspCameraAssetID = 0;
		uint32_t bspMapperID = 0;
		uint32_t bspMapperCollisionID = 0;
		uint32_t bspMapperFXID = 0;
		float loldHeight = 10.0f;
		Vec3 minBounds;
		Vec3 maxBounds;

		void Read(Stream* stream);
		void Write(Stream* stream);
    };

}