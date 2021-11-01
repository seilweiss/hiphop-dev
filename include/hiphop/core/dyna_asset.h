#pragma once

#include "hiphop/core/base_asset.h"

#define HIPHOP_DYNAASSET(typeName)\
    public:\
        static std::string GetStaticTypeName() { return typeName; }\
        virtual std::string GetTypeName() const { return typeName; }

namespace HipHop {

    struct DynaAsset : BaseAsset
    {
        HIPHOP_ASSET(AssetType::DYNA);

        uint32_t type = 0;
        uint16_t version = 0;
        uint16_t handle = 0;

        DynaAsset(uint32_t type, uint16_t version, Asset asset) : BaseAsset(asset, BaseType::Unknown), type(type), version(version) {}
        DynaAsset(const std::string& type, uint16_t version, Asset asset) : BaseAsset(asset, BaseType::Unknown), type(Util::Hash(type)), version(version) {}

        virtual std::string GetTypeName() const = 0;

        virtual void Read(Stream* stream);
        virtual void Write(Stream* stream);
    };

}