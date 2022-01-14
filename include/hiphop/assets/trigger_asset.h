#pragma once

#include "hiphop/core/ent_asset.h"

namespace HipHop {

	struct TriggerAsset : EntAsset
	{
		HIPHOP_ASSET(AssetType::TRIG);

		enum Type
		{
			Box,
			Sphere,
			VCylinder,
			VCircle
		};

		enum Flags
		{
			OneWay = 0x1
		};

		TriggerAsset(Asset asset) : EntAsset(asset, BaseType::Trigger) {}

		Vec3 p[4];
		Vec3 direction;
		uint32_t flags;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}