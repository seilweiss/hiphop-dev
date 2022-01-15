#pragma once

#include "hiphop/core/asset_serializer.h"

#ifdef HIPHOP_USE_RWS
#include "rws_core.h"
#else
#include "hiphop/core/default_asset.h"
#endif

namespace HipHop {

#ifdef HIPHOP_USE_RWS
	struct RenderWareAsset : AssetSerializer
	{
		RenderWareAsset(Asset asset) : AssetSerializer(asset) {}
		~RenderWareAsset();

		Rws::Chunk* GetChunk() const { return m_chunk; }
		void SetChunk(Rws::Chunk* chunk);

		virtual void Read(Stream* stream);
		virtual void Write(Stream* stream);

	protected:
		Rws::Chunk* ReadChunk(Stream* stream);
		void WriteChunk(Rws::Chunk* chunk, Stream* stream);

	private:
		Rws::Chunk* m_chunk = nullptr;
	};
#else
	struct RenderWareAsset : DefaultAsset
	{
		RenderWareAsset(Asset asset) : DefaultAsset(asset) {}
	};
#endif

}