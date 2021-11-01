#include "hiphop/assets/text_asset.h"

namespace HipHop {

    void TextAsset::Read(Stream* stream)
    {
        uint32_t len;
        stream->Read(&len);
        text.resize(len);

        for (uint32_t i = 0; i < len; i++)
        {
            char ch;
            stream->Read(&ch, 1);
            text[i] = ch;
        }

        stream->Align(4);
    }

    void TextAsset::Write(Stream* stream)
    {
        uint32_t len = (uint32_t)text.length();
        stream->Write(&len);
        stream->Write(text.c_str(), len);
        stream->Align(4);
    }

}