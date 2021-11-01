#include "hiphop/assets/texture_asset.h"

namespace HipHop {

#ifdef HIPHOP_USE_RWS
    void TextureAsset::Read(Stream* stream)
    {
        RenderWareAsset::Read(stream);
    }

    void TextureAsset::Write(Stream* stream)
    {
        RenderWareAsset::Write(stream);
    }
#endif

}