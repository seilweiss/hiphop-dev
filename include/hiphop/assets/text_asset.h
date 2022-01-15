#pragma once

#include "hiphop/core/asset_serializer.h"

namespace HipHop {

	struct TextAsset : AssetSerializer
	{
		HIPHOP_ASSET(AssetType::TEXT);

		TextAsset(Asset asset) : AssetSerializer(asset) {}

		std::string text;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}