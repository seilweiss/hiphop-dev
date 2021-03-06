#pragma once

#include "hiphop/core/asset.h"
#include "hiphop/core/stream.h"

#define HIPHOP_ASSET(type)\
    public:\
        static AssetType GetStaticType() { return type; }\
        virtual AssetType GetType() const { return type; }

namespace HipHop {

	struct AssetSerializer
	{
		HIPHOP_ASSET(AssetType::Default);

		AssetSerializer(Asset asset) : m_asset(asset) {}
		virtual ~AssetSerializer() {}

		Asset GetAsset() const { return m_asset; }
		File* GetFile() const { return m_asset.GetFile(); }
		bool Exists() const { return m_asset.Exists() && m_asset.GetType() == GetType(); }

		operator Asset() const { return m_asset; }
		operator uint32_t() const { return m_asset.GetID(); }
		operator bool() const { return Exists(); }

		void Load();
		void Save();

		virtual void Read(Stream* stream) = 0;
		virtual void Write(Stream* stream) = 0;

	private:
		Asset m_asset;
	};

}