#include "hiphop/assets/group_asset.h"

namespace HipHop {

    void GroupAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        stream->Read(&itemCount);
        stream->Read(&groupFlags);

        items.clear();
        items.reserve(itemCount);

        for (uint16_t i = 0; i < itemCount; i++)
        {
            uint32_t id;
            stream->Read(&id);
            items.push_back(id);
        }

        ReadLinks(stream);
    }

    void GroupAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        stream->Write(&itemCount);
        stream->Write(&groupFlags);

        for (uint32_t id : items)
        {
            stream->Write(&id);
        }

        WriteLinks(stream);
    }

}