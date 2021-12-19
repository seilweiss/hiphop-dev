#include "hiphop/assets/marker_asset.h"

namespace HipHop {

    void MarkerAsset::Read(Stream* stream)
    {
        pos.Read(stream);
    }

    void MarkerAsset::Write(Stream* stream)
    {
        pos.Write(stream);
    }

}