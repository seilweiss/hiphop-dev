#include "hiphop/core/layer.h"

#include "hiphop/core/file.h"

namespace HipHop {

    Layer::Layer(File* file, int index)
    {
        m_file = file;
        m_id = 0;

        if (file)
        {
            File::LayerInfo* linfo = file->GetLayerInfoAt(index);

            if (linfo)
            {
                m_id = linfo->id;
            }
        }
    }

    bool Layer::Exists() const
    {
        return m_file != nullptr && m_file->HasLayer(m_id);
    }

    int Layer::GetIndex() const
    {
        if (m_file)
        {
            return m_file->GetLayerIndex(m_id);
        }

        return -1;
    }

    LayerType Layer::GetType() const
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                return linfo->type;
            }
        }

        return LayerType::DEFAULT;
    }

    void Layer::SetType(LayerType type)
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                linfo->type = type;
            }
        }
    }

    int32_t Layer::GetAlign() const
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                return linfo->align;
            }
        }

        return -1;
    }

    void Layer::SetAlign(int32_t align)
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                linfo->align = align;
            }
        }
    }

    int Layer::GetAssetCount() const
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                return (int)linfo->assetIDs.size();
            }
        }

        return 0;
    }

    uint32_t Layer::GetAssetID(int index) const
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                return linfo->assetIDs[index];
            }
        }

        return 0;
    }

    int Layer::GetAssetIndex(uint32_t id) const
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                for (int i = 0; i < (int)linfo->assetIDs.size(); i++)
                {
                    if (linfo->assetIDs[i] == id)
                    {
                        return i;
                    }
                }
            }
        }

        return -1;
    }

    std::vector<uint32_t> Layer::GetAssetIDs() const
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                return linfo->assetIDs;
            }
        }

        return std::vector<uint32_t>();
    }

    std::vector<Asset> Layer::GetAssets() const
    {
        std::vector<uint32_t> assetIDs = GetAssetIDs();
        std::vector<Asset> assets;

        for (uint32_t id : assetIDs)
        {
            assets.push_back(Asset(m_file, id));
        }

        return assets;
    }

    bool Layer::Load()
    {
        if (m_file)
        {
            return m_file->LoadLayer(*this);
        }

        return false;
    }

    bool Layer::Unload()
    {
        if (m_file)
        {
            return m_file->UnloadLayer(*this);
        }

        return false;
    }

    void Layer::AddAsset(Asset asset)
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                Layer oldLayer = m_file->GetLayer(asset);

                if (oldLayer)
                {
                    if (oldLayer.m_id == m_id)
                    {
                        return;
                    }

                    oldLayer.RemoveAsset(asset);
                }

                linfo->assetIDs.push_back(asset.GetID());
            }
        }
    }

    void Layer::RemoveAsset(Asset asset)
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                int index = GetAssetIndex(asset);

                if (index != -1)
                {
                    linfo->assetIDs.erase(linfo->assetIDs.begin() + index);
                }
            }
        }
    }

    void Layer::AddAssetID(uint32_t id)
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                linfo->assetIDs.push_back(id);
            }
        }
    }

    void Layer::UpdateAssetID(uint32_t oldID, uint32_t newID)
    {
        if (m_file)
        {
            File::LayerInfo* linfo = m_file->GetLayerInfo(m_id);

            if (linfo)
            {
                for (uint32_t& id : linfo->assetIDs)
                {
                    if (id == oldID)
                    {
                        id = newID;
                        break;
                    }
                }
            }
        }
    }

}