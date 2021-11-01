#include "hiphop/assets/timer_asset.h"

namespace HipHop {

    void TimerAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        stream->Read(&seconds);
        stream->Read(&randomRange);

        ReadLinks(stream);
    }

    void TimerAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        stream->Write(&seconds);
        stream->Write(&randomRange);

        WriteLinks(stream);
    }

}