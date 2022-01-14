#pragma once

#include "hiphop/core/asset_editor.h"

#include <vector>

namespace HipHop {

	struct PipeInfo
	{
		enum ZWriteMode
		{
			ZWriteEnabled,
			ZWriteDisabled,
			ZWriteDepthPrePass,
		};

		enum CullMode
		{
			CullAuto,
			CullDisabled,
			CullBack,
			CullFrontThenBack
		};

		enum LightingMode
		{
			LightingEnabled,
			LightingDisabled,
			LightingEnabledPrelight
		};

		enum BlendFunction
		{
			BlendNA,
			BlendZero,
			BlendOne,
			BlendSrcColor,
			BlendInvSrcColor,
			BlendSrcAlpha,
			BlendInvSrcAlpha,
			BlendDstAlpha,
			BlendInvDstAlpha,
			BlendDstColor,
			BlendInvDstColor,
			BlendSrcAlphaSat
		};

		uint32_t ModelHashID;
		uint32_t SubObjectBits;

		union
		{
#pragma pack(push, 1)
			struct
			{
				uint8_t Unk0 : 2;
				uint8_t ZWrite : 2;
				uint8_t Cull : 2;
				uint8_t Lighting : 2;
				uint8_t BlendSrc : 4;
				uint8_t BlendDst : 4;
				bool DisableFog : 1;
				uint8_t Unk1 : 2;
				uint8_t AlphaLayer : 5;
				uint8_t AlphaCompare : 8;
			};
#pragma pack(pop)

			uint32_t PipeFlags;
		};

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

	struct PipeInfoTableAsset : AssetEditor
	{
		HIPHOP_ASSET(AssetType::PIPT);

		PipeInfoTableAsset(Asset asset) : AssetEditor(asset) {}

		std::vector<PipeInfo> pipeInfo;

		void Read(Stream* stream);
		void Write(Stream* stream);
	};

}