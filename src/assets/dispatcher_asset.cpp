#include "hiphop/assets/dispatcher_asset.h"

namespace HipHop {

    void DispatcherAsset::Read(Stream* stream)
    {
        BaseAsset::Read(stream);

        ReadLinks(stream);
    }

    void DispatcherAsset::Write(Stream* stream)
    {
        BaseAsset::Write(stream);

        WriteLinks(stream);
    }

}