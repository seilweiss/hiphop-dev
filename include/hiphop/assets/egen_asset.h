#pragma once

#include "hiphop/core/ent_asset.h"

namespace HipHop {

	struct EGenAsset : EntAsset
	{
		HIPHOP_ASSET(AssetType::EGEN);

		EGenAsset(Asset asset) : EntAsset(asset, BaseType::EGenerator) {}

		Vec3 src_dpos;
		uint8_t damage_type;
		uint8_t flags;
		float ontime;
		uint32_t onAnimID;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}