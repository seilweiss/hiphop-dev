#pragma once

#include "hiphop/core/asset.h"
#include "hiphop/core/layer_types.h"

#include <cstdint>
#include <vector>

namespace HipHop {

    class File;

    class Layer
    {
    public:
        Layer() : m_file(nullptr), m_id(0) {}
        Layer(File* file, int index);

        bool Exists() const;
        operator bool() const { return Exists(); }

        File* GetFile() const { return m_file; }
        int GetIndex() const;
        LayerType GetType() const;
        void SetType(LayerType type);
        int32_t GetAlign() const;
        void SetAlign(int32_t align);
        int GetAssetCount() const;
        uint32_t GetAssetID(int index) const;
        Asset GetAsset(int index) const { return Asset(m_file, GetAssetID(index)); }
        int GetAssetIndex(uint32_t id) const;
        int GetAssetIndex(Asset asset) const { return GetAssetIndex(asset.GetID()); }
        bool HasAsset(uint32_t id) const { return GetAssetIndex(id) != -1; }
        bool HasAsset(Asset asset) const { return HasAsset(asset.GetID()); }
        std::vector<uint32_t> GetAssetIDs() const;
        std::vector<Asset> GetAssets() const;
        bool Load();
        bool Unload();
        void AddAsset(Asset asset);
        void RemoveAsset(Asset asset);

    private:
        File* m_file;
        uint32_t m_id;

        void AddAssetID(uint32_t id);
        void UpdateAssetID(uint32_t oldID, uint32_t newID);

        friend class Asset;
        friend class File;
    };

}