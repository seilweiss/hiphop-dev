#pragma once

#include "hiphop/core/asset_serializer.h"
#include "hiphop/core/math.h"

namespace HipHop {

	struct MarkerAsset : AssetSerializer
	{
		HIPHOP_ASSET(AssetType::MRKR);

		MarkerAsset(Asset asset) : AssetSerializer(asset) {}

		Vec3 pos;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}