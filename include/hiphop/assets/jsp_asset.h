#pragma once

#include "hiphop/core/renderware_asset.h"
#include "hiphop/core/math.h"

#ifdef HIPHOP_USE_RWS
#include "rws_core.h"
#include "rws_world.h"
#endif

#include <vector>

namespace HipHop {

    struct JSPAsset : RenderWareAsset
    {
        HIPHOP_ASSET(AssetType::JSP);

        JSPAsset(Asset asset) : RenderWareAsset(asset) {}

#ifdef HIPHOP_USE_RWS
        enum Type
        {
            Unknown,
            JSPInfo,
            JSPClump
        };

        struct BSPBranchNode
        {
            uint32_t leftInfo;
            uint32_t rightInfo;
            float leftValue;
            float rightValue;

            void Read(Stream* stream);
            void Write(Stream* stream);
        };

        struct BSPTriangle
        {
            uint16_t atomIndex;
            uint16_t meshVertIndex;
            uint8_t flags;
            uint8_t platData;
            uint16_t matIndex;

            void Read(Stream* stream);
            void Write(Stream* stream);
        };

        struct BSPTree
        {
            std::vector<BSPBranchNode> branchNodes;
            std::vector<BSPTriangle> triangles;

            void Read(Stream* stream);
            void Write(Stream* stream);
        };

        struct NodeInfo
        {
            enum Flags
            {
                ToggleZWrite = 0x2,
                ToggleCullMode = 0x4
            };

            int32_t originalMatIndex;
            int32_t nodeFlags;

            void Read(Stream* stream);
            void Write(Stream* stream);
        };

        Type type = JSPInfo;
        Rws::Clump* clump = nullptr;
        uint32_t version = 3;
        BSPTree bspTree;
        std::vector<NodeInfo> jspNodeList;
        std::vector<Vec3> verts;

        ~JSPAsset();

        void Read(Stream* stream);
        void Write(Stream* stream);

    private:
        void ReadBEEF01(Stream* stream);
        void ReadBEEF02(Stream* stream);
        void ReadBEEF03(Stream* stream);
        void WriteBEEF01(Stream* stream);
        void WriteBEEF02(Stream* stream);
        void WriteBEEF03(Stream* stream);
#endif
    };

}