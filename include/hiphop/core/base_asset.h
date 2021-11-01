#pragma once

#include "hiphop/core/asset_editor.h"
#include "hiphop/core/link_asset.h"
#include "hiphop/core/base_types.h"

#include <vector>

namespace HipHop {

    struct BaseAsset : AssetEditor
    {
        enum BaseFlags
        {
            Enabled = 0x1,
            Persistent = 0x2,
            Valid = 0x4
        };

        BaseAsset(Asset asset, BaseType baseType = BaseType::Unknown) : AssetEditor(asset), baseType(baseType) {}

        BaseType baseType = BaseType::Unknown;
        uint16_t baseFlags = Enabled | Valid;
        std::vector<LinkAsset> links;

        virtual void Read(Stream* stream);
        virtual void Write(Stream* stream);

    protected:
        void ReadLinks(Stream* stream);
        void WriteLinks(Stream* stream);

    private:
        uint8_t m_readLinkCount = 0;
    };

}