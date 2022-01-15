#pragma once

#include "hiphop/core/asset_serializer.h"

#include <vector>

namespace HipHop {

	struct LightKitLight
	{
		enum Type
		{
			Ambient = 1,
			Directional = 2,
			Point = 3,
			Spot = 4
		};

		uint32_t type = Ambient;
		float color[4] = { 1, 1, 1, 1 };
		float matrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
		float radius = 0.0f;
		float angle = 0.0f;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct LightKitAsset : AssetSerializer
	{
		HIPHOP_ASSET(AssetType::LKIT);

		LightKitAsset(Asset asset) : AssetSerializer(asset) {}

		uint32_t groupID = 0;
		std::vector<LightKitLight> lightList;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}