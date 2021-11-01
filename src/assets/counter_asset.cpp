#include "hiphop/assets/counter_asset.h"

namespace HipHop {

    void CounterAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        stream->Read(&count);
        stream->Align(4);

        ReadLinks(stream);
    }

    void CounterAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        stream->Write(&count);
        stream->Align(4);

        WriteLinks(stream);
    }

}