#include "hiphop/assets/anim_list_asset.h"

namespace HipHop {

    void AnimListAsset::Read(Stream* stream)
    {
        stream->Read(ids, sizeof(ids));
    }

    void AnimListAsset::Write(Stream* stream)
    {
        stream->Write(ids, sizeof(ids));
    }

}