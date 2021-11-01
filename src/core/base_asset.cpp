#include "hiphop/core/base_asset.h"

namespace HipHop {

    void BaseAsset::Read(Stream* stream)
    {
        links.clear();

        uint32_t id;
        uint8_t bt;

        stream->Read(&id);
        stream->Read(&bt);
        stream->Read(&m_readLinkCount);
        stream->Read(&baseFlags);

        baseType = (BaseType)bt;
        links.reserve(m_readLinkCount);
    }

    void BaseAsset::Write(Stream* stream)
    {
        uint32_t id = GetAsset().GetID();
        uint8_t bt = (uint8_t)baseType;
        uint8_t linkCount = (uint8_t)links.size();

        stream->Write(&id);
        stream->Write(&bt);
        stream->Write(&linkCount);
        stream->Write(&baseFlags);
    }

    void BaseAsset::ReadLinks(Stream* stream)
    {
        for (size_t i = 0; i < m_readLinkCount; i++)
        {
            LinkAsset link;
            link.Read(stream);
            links.push_back(link);
        }
    }

    void BaseAsset::WriteLinks(Stream* stream)
    {
        for (LinkAsset& link : links)
        {
            link.Write(stream);
        }
    }

}