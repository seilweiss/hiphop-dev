#include "hiphop/assets/coll_table_asset.h"

namespace HipHop {

    void CollTableAsset::Read(Stream* stream)
    {
        entries.clear();

        int32_t count;
        stream->Read(&count);

        entries.reserve(count);

        for (int32_t i = 0; i < count; i++)
        {
            Entry entry;
            stream->Read(&entry.baseModel);
            stream->Read(&entry.colModel);
            stream->Read(&entry.camcolModel);
            entries.push_back(entry);
        }
    }

    void CollTableAsset::Write(Stream* stream)
    {
        int32_t count = (int32_t)entries.size();

        stream->Write(&count);

        for (int32_t i = 0; i < count; i++)
        {
            stream->Write(&entries[i].baseModel);
            stream->Write(&entries[i].colModel);
            stream->Write(&entries[i].camcolModel);
        }
    }

}