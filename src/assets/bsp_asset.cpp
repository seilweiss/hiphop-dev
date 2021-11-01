#include "hiphop/assets/bsp_asset.h"

namespace HipHop {

#ifdef HIPHOP_USE_RWS
    void BSPAsset::Read(Stream* stream)
    {
        RenderWareAsset::Read(stream);
    }

    void BSPAsset::Write(Stream* stream)
    {
        RenderWareAsset::Write(stream);
    }
#endif

}