#pragma once

#include "hiphop/core/asset_serializer.h"

#include <vector>

namespace HipHop {

	struct CollTableAsset : AssetSerializer
	{
		HIPHOP_ASSET(AssetType::COLL);

		CollTableAsset(Asset asset) : AssetSerializer(asset) {}

		struct Entry
		{
			uint32_t baseModel;
			uint32_t colModel;
			uint32_t camcolModel;
		};

		std::vector<Entry> entries;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}