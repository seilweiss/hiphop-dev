#include "hiphop/assets/lightkit_asset.h"

namespace HipHop {

    void LightKitLight::Read(Stream* stream)
    {
        uint32_t platLight;

        stream->Read(&type);
        stream->Read(color, sizeof(color));
        stream->Read(matrix, sizeof(matrix));
        stream->Read(&radius);
        stream->Read(&angle);
        stream->Read(&platLight);
    }

    void LightKitLight::Write(Stream* stream)
    {
        uint32_t platLight = 0;

        stream->Write(&type);
        stream->Write(color, sizeof(color));
        stream->Write(matrix, sizeof(matrix));
        stream->Write(&radius);
        stream->Write(&angle);
        stream->Write(&platLight);
    }

    void LightKitAsset::Read(Stream* stream)
    {
        uint32_t tagID;
        uint32_t lightCount;
        uint32_t lightListPtr;

        stream->Read(&tagID);
        stream->Read(&groupID);
        stream->Read(&lightCount);
        stream->Read(&lightListPtr);

        for (uint32_t i = 0; i < lightCount; i++)
        {
            LightKitLight light;
            light.Read(stream);
            lightList.push_back(light);
        }
    }

    void LightKitAsset::Write(Stream* stream)
    {
        uint32_t tagID = 'LKIT';
        uint32_t lightCount = (uint32_t)lightList.size();
        uint32_t lightListPtr = 0;

        stream->Write(&tagID);
        stream->Write(&groupID);
        stream->Write(&lightCount);
        stream->Write(&lightListPtr);

        for (LightKitLight& light : lightList)
        {
            light.Write(stream);
        }
    }

}