#include "hiphop/assets/jsp_asset.h"

#include "hiphop/core/memory_stream.h"
#include "hiphop/core/file.h"

namespace HipHop {

#ifdef HIPHOP_USE_RWS
    void JSPAsset::BSPBranchNode::Read(Stream* stream)
    {
        stream->Read(&leftInfo);
        stream->Read(&rightInfo);
        stream->Read(&leftValue);
        stream->Read(&rightValue);
    }

    void JSPAsset::BSPBranchNode::Write(Stream* stream)
    {
        stream->Write(&leftInfo);
        stream->Write(&rightInfo);
        stream->Write(&leftValue);
        stream->Write(&rightValue);
    }

    void JSPAsset::BSPTriangle::Read(Stream* stream)
    {
        stream->Read(&atomIndex);
        stream->Read(&meshVertIndex);
        stream->Read(&flags);
        stream->Read(&platData);
        stream->Read(&matIndex);
        stream->Align(4);
    }

    void JSPAsset::BSPTriangle::Write(Stream* stream)
    {
        stream->Write(&atomIndex);
        stream->Write(&meshVertIndex);
        stream->Write(&flags);
        stream->Write(&platData);
        stream->Write(&matIndex);
        stream->Align(4);
    }

    void JSPAsset::BSPTree::Read(Stream* stream)
    {
        uint32_t magic;
        uint32_t numBranchNodes;
        uint32_t numTriangles;

        branchNodes.clear();
        triangles.clear();

        stream->Read(&magic);
        stream->Read(&numBranchNodes);
        stream->Read(&numTriangles);

        branchNodes.reserve(numBranchNodes);
        triangles.reserve(numTriangles);

        for (uint32_t i = 0; i < numBranchNodes; i++)
        {
            BSPBranchNode branchNode;
            branchNode.Read(stream);
            branchNodes.push_back(branchNode);
        }

        for (uint32_t i = 0; i < numTriangles; i++)
        {
            BSPTriangle triangle;
            triangle.Read(stream);
            triangles.push_back(triangle);
        }
    }

    void JSPAsset::BSPTree::Write(Stream* stream)
    {
        uint32_t magic = 'CCOL';
        uint32_t numBranchNodes = (uint32_t)branchNodes.size();
        uint32_t numTriangles = (uint32_t)triangles.size();

        stream->Write(&magic);
        stream->Write(&numBranchNodes);
        stream->Write(&numTriangles);

        for (BSPBranchNode& branchNode : branchNodes)
        {
            branchNode.Write(stream);
        }

        for (BSPTriangle& triangle : triangles)
        {
            triangle.Write(stream);
        }
    }

    void JSPAsset::NodeInfo::Read(Stream* stream)
    {
        stream->Read(&originalMatIndex);
        stream->Read(&nodeFlags);
    }

    void JSPAsset::NodeInfo::Write(Stream* stream)
    {
        stream->Write(&originalMatIndex);
        stream->Write(&nodeFlags);
    }

    JSPAsset::~JSPAsset()
    {
        if (clump)
        {
            delete clump;
        }
    }

    void JSPAsset::Read(Stream* stream)
    {
        type = Unknown;
        clump = nullptr;

        while (!stream->AtEnd())
        {
            Rws::Chunk* chunk = ReadChunk(stream);

            if (chunk)
            {
                switch (chunk->GetType())
                {
                case Rws::ID_CLUMP:
                {
                    type = JSPClump;
                    clump = chunk->As<Rws::Clump>();
                    break;
                }
                case 0xBEEF01:
                case 0xBEEF02:
                case 0xBEEF03:
                {
                    type = JSPInfo;

                    Rws::DefaultChunk* defaultChunk = (Rws::DefaultChunk*)chunk;
                    MemoryStream memStream((void*)defaultChunk->byteArray.GetData(), (size_t)defaultChunk->byteArray.GetLength());
                    memStream.SetEndian(stream->GetEndian());

                    switch (chunk->GetType())
                    {
                    case 0xBEEF01:
                        ReadBEEF01(&memStream);
                        break;
                    case 0xBEEF02:
                        ReadBEEF02(&memStream);
                        break;
                    case 0xBEEF03:
                        ReadBEEF03(&memStream);
                        break;
                    }

                    delete chunk;
                    break;
                }
                default:
                {
                    delete chunk;
                    break;
                }
                }
            }
        }
    }

    void JSPAsset::ReadBEEF01(Stream* stream)
    {
        bspTree.Read(stream);
    }

    void JSPAsset::ReadBEEF02(Stream* stream)
    {
        char idtag[4];
        uint32_t jspNodeCount;

        jspNodeList.clear();

        stream->Read(idtag, 4);
        stream->Read(&version);
        stream->Read(&jspNodeCount);
        stream->Skip(12);

        jspNodeList.reserve(jspNodeCount);

        for (uint32_t i = 0; i < jspNodeCount; i++)
        {
            NodeInfo nodeInfo;
            nodeInfo.Read(stream);
            jspNodeList.push_back(nodeInfo);
        }
    }

    void JSPAsset::ReadBEEF03(Stream* stream)
    {
        uint32_t vertCount;

        verts.clear();

        stream->Read(&vertCount);

        verts.reserve(vertCount);

        for (uint32_t i = 0; i < vertCount; i++)
        {
            Vec3 vert;
            vert.Read(stream);
            verts.push_back(vert);
        }
    }

    void JSPAsset::Write(Stream* stream)
    {
        switch (type)
        {
        case JSPClump:
        {
            WriteChunk(clump, stream);
            break;
        }
        case JSPInfo:
        {
            Rws::DefaultChunk defaultChunk;

            MemoryStream memStream;
            memStream.SetEndian(stream->GetEndian());

            WriteBEEF01(&memStream);

            defaultChunk.SetType(0xBEEF01);
            defaultChunk.byteArray.SetData((Rws::UInt8*)memStream.GetData(), (Rws::UInt32)memStream.GetSize());
            
            WriteChunk(&defaultChunk, stream);

            memStream.Clear();

            WriteBEEF02(&memStream);

            defaultChunk.SetType(0xBEEF02);
            defaultChunk.byteArray.SetData((Rws::UInt8*)memStream.GetData(), (Rws::UInt32)memStream.GetSize());

            WriteChunk(&defaultChunk, stream);

            if (GetFile()->GetPlatform() == Platform::GameCube)
            {
                memStream.Clear();

                WriteBEEF03(&memStream);

                defaultChunk.SetType(0xBEEF03);
                defaultChunk.byteArray.SetData((Rws::UInt8*)memStream.GetData(), (Rws::UInt32)memStream.GetSize());

                WriteChunk(&defaultChunk, stream);
            }

            break;
        }
        }
    }

    void JSPAsset::WriteBEEF01(Stream* stream)
    {
        bspTree.Write(stream);
    }

    void JSPAsset::WriteBEEF02(Stream* stream)
    {
        char idtag[4] = "JSP";
        uint32_t jspNodeCount = (uint32_t)jspNodeList.size();
        uint32_t null = 0;

        stream->Write(idtag, 4);
        stream->Write(&version);
        stream->Write(&jspNodeCount);
        stream->Write(&null);
        stream->Write(&null);
        stream->Write(&null);

        for (NodeInfo& nodeInfo : jspNodeList)
        {
            nodeInfo.Write(stream);
        }
    }

    void JSPAsset::WriteBEEF03(Stream* stream)
    {
        uint32_t vertCount = (uint32_t)verts.size();

        stream->Write(&vertCount);

        for (Vec3& vert : verts)
        {
            vert.Write(stream);
        }
    }
#endif

}