#pragma once

#include "hiphop/core/ent_asset.h"

namespace HipHop {

	struct DestructObjAsset : EntAsset
	{
		HIPHOP_ASSET(AssetType::DSTR);

		DestructObjAsset(Asset asset) : EntAsset(asset, BaseType::DestructObj) {}

		float animSpeed;
		uint32_t initAnimState;
		uint32_t health;
		uint32_t spawnItemID;
		uint32_t dflags;
		uint8_t collType;
		uint8_t fxType;
		float blast_radius;
		float blast_strength;
		uint32_t shrapnelID_destroy;
		uint32_t shrapnelID_hit;
		uint32_t sfx_destroy;
		uint32_t sfx_hit;
		uint32_t hitModel;
		uint32_t destroyModel;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}