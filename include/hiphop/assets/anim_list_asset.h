#pragma once

#include "hiphop/core/asset_serializer.h"

namespace HipHop {

	struct AnimListAsset : AssetSerializer
	{
		HIPHOP_ASSET(AssetType::ALST);

		AnimListAsset(Asset asset) : AssetSerializer(asset) {}

		uint32_t ids[10] = {};

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}