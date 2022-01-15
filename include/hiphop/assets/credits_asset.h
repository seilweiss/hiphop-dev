#pragma once

#include "hiphop/core/default_asset.h"

namespace HipHop {

	struct CreditsAsset : AssetSerializer
	{
		HIPHOP_ASSET(AssetType::CRDT);

		CreditsAsset(Asset asset) : AssetSerializer(asset) {}
	};

}