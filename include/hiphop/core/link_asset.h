#pragma once

#include "hiphop/core/asset.h"
#include "hiphop/core/stream.h"

#include <vector>

namespace HipHop {

    struct LinkAsset
    {
        union Param
        {
            float f;
            uint32_t i;

            Param() : i(0) {}
            Param(float f) : f(f) {}
            Param(uint32_t i) : i(i) {}
        };

        static_assert(sizeof(Param) == sizeof(uint32_t), "sizeof(HipHop::LinkAsset::Param) != sizeof(uint32_t)");

        uint16_t srcEvent = 0;
        uint16_t dstEvent = 0;
        uint32_t dstAssetID = 0;
        Param param[4] = {};
        uint32_t paramWidgetAssetID = 0;
        uint32_t chkAssetID = 0;

        LinkAsset() {}

        LinkAsset(uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            paramWidgetAssetID = p_paramWidgetAsset;
        }

        LinkAsset(uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Param p_param0,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            param[0] = p_param0;
            paramWidgetAssetID = p_paramWidgetAsset;
        }

        LinkAsset(uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Param p_param0,
                  Param p_param1,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            param[0] = p_param0;
            param[1] = p_param1;
            paramWidgetAssetID = p_paramWidgetAsset;
        }

        LinkAsset(uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Param p_param0,
                  Param p_param1,
                  Param p_param2,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            param[0] = p_param0;
            param[1] = p_param1;
            param[2] = p_param2;
            paramWidgetAssetID = p_paramWidgetAsset;
        }

        LinkAsset(uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Param p_param0,
                  Param p_param1,
                  Param p_param2,
                  Param p_param3,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            param[0] = p_param0;
            param[1] = p_param1;
            param[2] = p_param2;
            param[3] = p_param3;
            paramWidgetAssetID = p_paramWidgetAsset;
        }

        LinkAsset(Asset p_chkAsset,
                  uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            paramWidgetAssetID = p_paramWidgetAsset;
            chkAssetID = p_chkAsset;
        }

        LinkAsset(Asset p_chkAsset,
                  uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Param p_param0,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            param[0] = p_param0;
            paramWidgetAssetID = p_paramWidgetAsset;
            chkAssetID = p_chkAsset;
        }

        LinkAsset(Asset p_chkAsset,
                  uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Param p_param0,
                  Param p_param1,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            param[0] = p_param0;
            param[1] = p_param1;
            paramWidgetAssetID = p_paramWidgetAsset;
            chkAssetID = p_chkAsset;
        }

        LinkAsset(Asset p_chkAsset,
                  uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Param p_param0,
                  Param p_param1,
                  Param p_param2,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            param[0] = p_param0;
            param[1] = p_param1;
            param[2] = p_param2;
            paramWidgetAssetID = p_paramWidgetAsset;
            chkAssetID = p_chkAsset;
        }

        LinkAsset(Asset p_chkAsset,
                  uint16_t p_srcEvent,
                  uint16_t p_dstEvent,
                  Asset p_dstAsset,
                  Param p_param0,
                  Param p_param1,
                  Param p_param2,
                  Param p_param3,
                  Asset p_paramWidgetAsset = Asset())
        {
            srcEvent = p_srcEvent;
            dstEvent = p_dstEvent;
            dstAssetID = p_dstAsset;
            param[0] = p_param0;
            param[1] = p_param1;
            param[2] = p_param2;
            param[3] = p_param3;
            paramWidgetAssetID = p_paramWidgetAsset;
            chkAssetID = p_chkAsset;
        }

        void Read(Stream* stream);
        void Write(Stream* stream);
    };

}