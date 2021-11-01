#include "hiphop/core/asset.h"

#include "hiphop/core/file.h"

namespace HipHop {

    bool Asset::Exists() const
    {
        return m_file != nullptr && m_file->HasAsset(m_id);
    }

    bool Asset::SetID(uint32_t newID)
    {
        if (newID == 0)
        {
            return false;
        }

        if (!m_file)
        {
            return false;
        }

        if (m_file->HasAsset(newID))
        {
            return false;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return false;
        }

        Layer layer = m_file->GetLayer(*this);

        if (!layer)
        {
            return false;
        }

        layer.UpdateAssetID(m_id, newID);

        ainfo->id = newID;

        m_file->SortAssets();

        return true;
    }

    void Asset::SetType(AssetType type)
    {
        if (!m_file)
        {
            return;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return;
        }

        ainfo->type = type;
    }

    AssetType Asset::GetType() const
    {
        if (!m_file)
        {
            return AssetType::Default;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return AssetType::Default;
        }

        return ainfo->type;
    }

    uint32_t Asset::GetFlags() const
    {
        if (!m_file)
        {
            return 0;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return 0;
        }

        return ainfo->flags;
    }

    void Asset::SetFlags(uint32_t flags)
    {
        if (!m_file)
        {
            return;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return;
        }

        ainfo->flags = flags;
    }

    int32_t Asset::GetAlign() const
    {
        if (!m_file)
        {
            return 0;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return 0;
        }

        return ainfo->align;
    }

    void Asset::SetAlign(int32_t align)
    {
        if (!m_file)
        {
            return;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return;
        }

        ainfo->align = align;
    }

    uint32_t Asset::GetChecksum() const
    {
        if (!m_file)
        {
            return 0;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return 0;
        }

        return ainfo->checksum;
    }

    const void* Asset::GetData() const
    {
        if (!m_file)
        {
            return nullptr;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return nullptr;
        }

        return ainfo->data;
    }

    uint32_t Asset::GetSize() const
    {
        if (!m_file)
        {
            return 0;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return 0;
        }

        return ainfo->size;
    }

    void Asset::SetData(const void* data, uint32_t size)
    {
        if (!m_file)
        {
            return;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return;
        }

        if (ainfo->data)
        {
            free(ainfo->data);
        }

        if (data && size != 0)
        {
            ainfo->data = malloc(size);
            ainfo->size = size;

            if (ainfo->data)
            {
                memcpy(ainfo->data, data, size);
            }
        }
        else
        {
            ainfo->data = nullptr;
            ainfo->size = 0;
        }

        ainfo->loaded = true;
    }

    bool Asset::IsLoaded() const
    {
        if (!m_file)
        {
            return false;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return false;
        }

        return ainfo->loaded;
    }

    bool Asset::Load()
    {
        if (!m_file)
        {
            return false;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return false;
        }

        return m_file->LoadAsset(*ainfo);
    }

    bool Asset::Unload()
    {
        if (!m_file)
        {
            return false;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return false;
        }

        return m_file->UnloadAsset(*ainfo);
    }

    std::string Asset::GetName() const
    {
        if (!m_file)
        {
            return std::string();
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return std::string();
        }

        return ainfo->name;
    }

    void Asset::SetName(const std::string& name, bool generateNewID)
    {
        if (!m_file)
        {
            return;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return;
        }

        ainfo->name = name;

        if (generateNewID)
        {
            SetID(m_file->GenerateUniqueAssetID(name));
        }
    }

    std::string Asset::GetFileName() const
    {
        if (!m_file)
        {
            return std::string();
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return std::string();
        }

        return ainfo->filename;
    }

    void Asset::SetFileName(const std::string& filename)
    {
        if (!m_file)
        {
            return;
        }

        File::AssetInfo* ainfo = m_file->GetAssetInfo(m_id);

        if (!ainfo)
        {
            return;
        }

        ainfo->filename = filename;
    }

    int Asset::GetIndex() const
    {
        if (!m_file)
        {
            return -1;
        }

        return m_file->GetAssetIndex(m_id);
    }

}