#pragma once

#include "hiphop/core/stream.h"
#include "hiphop/core/games.h"
#include "hiphop/core/platforms.h"
#include "hiphop/core/regions.h"
#include "hiphop/core/languages.h"
#include "hiphop/core/asset.h"
#include "hiphop/core/layer.h"
#include "hiphop/core/util.h"

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#define HIPHOP_FILE_MAX_BLOCK_DEPTH 8

namespace HipHop {

    struct JSPGroup
    {
        std::vector<Asset> jsps;
        Asset jspInfo;
    };

    class File
    {
    public:
        File();
        File(Stream* stream);
        File(const std::string& path);
        File(const void* data, size_t size);
        ~File();

        void Create(Game game, Platform platform, Region region = Region::NTSC, Language language = Language::USCommon);
        void Destroy();

        Game GetGame() const { return m_game; }
        void SetGame(Game game) { m_game = game; }
        Platform GetPlatform() const { return m_platform; }
        void SetPlatform(Platform platform) { m_platform = platform; }
        Region GetRegion() const { return m_region; }
        void SetRegion(Region region) { m_region = region; }
        Language GetLanguage() const { return m_language; }
        void SetLanguage(Language language) { m_language = language; }

        Stream* GetStream() const { return m_stream; }
        void SetStream(Stream* stream);

        bool Read();
        bool Write();

        bool LoadAssets();
        bool UnloadAssets();
        bool LoadAsset(Asset asset);
        bool UnloadAsset(Asset asset);
        bool LoadLayer(Layer layer); // Loads all assets in layer
        bool UnloadLayer(Layer layer); // Unloads all assets in layer

        void SortAssets();
        void SortLayers();

        uint32_t GetSubVersion() const { return m_subVersion; }
        void SetSubVersion(uint32_t ver) { m_subVersion = ver; }
        uint32_t GetClientVersion() const { return m_clientVersion; }
        void SetClientVersion(uint32_t ver) { m_clientVersion = ver; }
        uint32_t GetCompatVersion() const { return m_compatVersion; }
        void SetCompatVersion(uint32_t ver) { m_compatVersion = ver; }
        time_t GetCreatedTime() const { return m_createdTime; }
        void SetCreatedTime(time_t t) { m_createdTime = t; }
        time_t GetModifiedTime() const { return m_modifiedTime; }
        void SetModifiedTime(time_t t) { m_modifiedTime = t; }
        time_t GetTimezoneOffset() const { return m_timezoneOffset; }
        void SetTimezoneOffset(time_t t) { m_timezoneOffset = t; }
        uint32_t GetPFLG() const { return m_pflg; }
        void SetPFLG(uint32_t pflg) { m_pflg = pflg; }
        uint32_t GetAINF() const { return m_ainf; }
        void SetAINF(uint32_t ainf) { m_ainf = ainf; }
        uint32_t GetLINF() const { return m_linf; }
        void SetLINF(uint32_t linf) { m_linf = linf; }
        int32_t GetDHDR() const { return m_dhdr; }
        void SetDHDR(int32_t dhdr) { m_dhdr = dhdr; }
        bool IsScoobyBeta() const { return m_scoobyBeta; }
        void SetScoobyBeta(bool isScoobyBeta) { m_scoobyBeta = isScoobyBeta; }
        bool DoEntAssetsHavePad();

        std::vector<Asset> GetAssets();
        std::vector<Asset> GetAssets(AssetType type);
        int GetAssetCount() const { return (int)m_assetInfo.size(); }
        int GetAssetCount(AssetType type) const;
        Asset GetAssetAt(int index) { return Asset(this, m_assetInfo[index].id); }
        Asset GetAsset(uint32_t id) { return Asset(this, id); };
        Asset GetAsset(const std::string& name) { return Asset(this, Util::Hash(name)); }
        Asset GetAsset(AssetType type, int index = 0) { return Asset(this, m_assetInfo[GetAssetIndex(type, index)].id); }
        template <class T> T GetAssetAt(int index) { return T(GetAssetAt(index)); }
        template <class T> T GetAsset(uint32_t id) { return T(GetAsset(id)); }
        template <class T> T GetAsset(const std::string& name) { return T(GetAsset(name)); }
        template <class T> T GetAsset(int index = 0) { return T(GetAsset(T::GetStaticType(), index)); }
        int GetAssetIndex(Asset asset) const { return GetAssetIndex(asset.GetID()); }
        int GetAssetIndex(uint32_t id) const;
        int GetAssetIndex(const std::string& name) const { return GetAssetIndex(Util::Hash(name)); }
        int GetAssetIndex(AssetType type, int index = 0) const;
        bool HasAsset(uint32_t id) const { return GetAssetIndex(id) != -1; }
        bool HasAsset(const std::string& name) const { return GetAssetIndex(name) != -1; }
        bool AssetIsTypeAt(int index, AssetType type) const { return m_assetInfo[index].type == type; }
        bool AssetIsType(uint32_t id, AssetType type) const { int index = GetAssetIndex(id); return index != -1 && AssetIsTypeAt(index, type); }
        bool AssetIsType(const std::string& name, AssetType type) const { return AssetIsType(Util::Hash(name), type); }
        bool AssetIsType(Asset asset, AssetType type) const { return AssetIsType(asset.GetID(), type); }
        Asset CreateAsset(AssetType type, const std::string& name);
        Asset CreateAsset(AssetType type, const std::string& name, Layer layer);
        template <class T> T CreateAsset(const std::string& name) { return T(CreateAsset(T::GetStaticType(), name)); }
        template <class T> T CreateAsset(const std::string& name, Layer layer) { return T(CreateAsset(T::GetStaticType(), name, layer)); }
        JSPGroup CreateJSPGroup(const std::string& name, int jspCount);

        std::vector<Layer> GetLayers();
        std::vector<Layer> GetLayers(LayerType type);
        int GetLayerCount() const { return (int)m_layerInfo.size(); }
        int GetLayerCount(LayerType type) const;
        int GetLayerIndex(Layer layer) const { return GetLayerIndex(layer.m_id); }
        int GetLayerIndex(LayerType type, int index = 0) const;
        int GetLayerIndex(Asset asset) const;
        Layer GetLayerAt(int index) { return Layer(this, index); }
        Layer GetLayer(LayerType type, int index = 0) { return Layer(this, GetLayerIndex(type, index)); }
        Layer GetLayer(Asset asset) { return Layer(this, GetLayerIndex(asset)); }
        Layer CreateLayer(LayerType type, bool sort = true);

        int32_t GetDefaultLayerAlign() const { return m_defaultLayerAlign; }
        void SetDefaultLayerAlign(int32_t align) { m_defaultLayerAlign = align; }
        int32_t GetDefaultAssetAlign() const { return m_defaultAssetAlign; }
        void SetDefaultAssetAlign(int32_t align) { m_defaultAssetAlign = align; }
        int32_t GetDefaultAssetAlign(AssetType type) const { return m_defaultAssetTypeAlign.find(type) != m_defaultAssetTypeAlign.end() ? m_defaultAssetTypeAlign.at(type) : m_defaultAssetAlign; }
        void SetDefaultAssetAlign(AssetType type, int32_t align) { m_defaultAssetTypeAlign[type] = align; }
        LayerType GetDefaultLayerType(AssetType type) const { return m_defaultAssetTypeLayer.find(type) != m_defaultAssetTypeLayer.end() ? m_defaultAssetTypeLayer.at(type) : LayerType::DEFAULT; }
        void SetDefaultLayerType(AssetType type, LayerType layerType) { m_defaultAssetTypeLayer[type] = layerType; }
        int32_t GetDefaultAssetFlags(AssetType type) const { return m_defaultAssetTypeFlags.find(type) != m_defaultAssetTypeFlags.end() ? m_defaultAssetTypeFlags.at(type) : 0; }
        void SetDefaultAssetFlags(AssetType type, uint32_t flags) { m_defaultAssetTypeFlags[type] = flags; }

        uint32_t GenerateUniqueAssetID(const std::string& name) const;

    private:
        struct BlockReadInfo
        {
            size_t endpos;
        };

        struct BlockWriteInfo
        {
            size_t lenpos;
            size_t datapos;
        };

        struct AssetInfo
        {
            uint32_t id = 0;
            AssetType type = AssetType::Default;
            uint32_t flags = 0;
            int32_t align = 0;
            uint32_t checksum = 0;
            void* data = nullptr;
            uint32_t size = 0;
            bool loaded = false;
            std::string name;
            std::string filename;
            uint32_t offset = 0;
            uint32_t plus = 0;
            size_t writeOffsetPos = 0;
        };

        struct LayerInfo
        {
            uint32_t id = 0;
            LayerType type = LayerType::Unknown;
            int32_t align = -1;
            std::vector<uint32_t> assetIDs;
            uint32_t size = 0;
            uint32_t plus = 0;
            uint32_t readType = 0;
        };

        int32_t m_defaultLayerAlign = 32;
        int32_t m_defaultAssetAlign = 16;
        std::map<AssetType, int32_t> m_defaultAssetTypeAlign; // asset type => alignment value
        std::map<AssetType, LayerType> m_defaultAssetTypeLayer; // asset type => layer type
        std::map<AssetType, uint32_t> m_defaultAssetTypeFlags; // asset type => flags

        Game m_game = Game::Unknown;
        Platform m_platform = Platform::GameCube;
        Region m_region = Region::NTSC;
        Language m_language = Language::USCommon;
        uint32_t m_subVersion = 2;
        uint32_t m_clientVersion = 0x000A000F; // 10.15
        uint32_t m_compatVersion = 1;
        time_t m_createdTime = time(nullptr);
        time_t m_modifiedTime = time(nullptr);
        time_t m_timezoneOffset = 7 * 3600; // UTC-7:00 (Pacific Time)
        bool m_endTimeStringWithNewline = false; // true in scooby
        uint32_t m_pflg = 0x2E;
        uint32_t m_ainf = 0;
        uint32_t m_linf = 0;
        int32_t m_dhdr = -1;
        bool m_hasPLAT = true;
        bool m_writeAssetOffsetZeroIfSizeZero = true;
        bool m_scoobyBeta = false;
        bool m_entAssetsHavePad = false;
        bool m_entAssetsHavePadDetected = false;

        std::vector<AssetInfo> m_assetInfo;
        std::vector<LayerInfo> m_layerInfo;
        Stream* m_stream = nullptr;
        bool m_ownsStream = false;
        BlockReadInfo m_blockReadInfo[HIPHOP_FILE_MAX_BLOCK_DEPTH] = {};
        BlockWriteInfo m_blockWriteInfo[HIPHOP_FILE_MAX_BLOCK_DEPTH] = {};
        int m_blockDepth = -1;
        size_t m_dpakDataStart = 0;
        size_t m_maxLayerSizeWritePos = 0;
        bool m_unknownWhetherGameIsTSSMIncOrROTU = false;

        void InitDefaultSettings();

        bool LoadAsset(AssetInfo& asset);
        bool UnloadAsset(AssetInfo& asset);
        bool LoadLayer(LayerInfo& layer);
        bool UnloadLayer(LayerInfo& layer);

        static bool CompareAssets(const AssetInfo& a, const AssetInfo& b);
        static bool CompareLayers(const LayerInfo& a, const LayerInfo& b);

        AssetInfo* GetAssetInfo(uint32_t id);
        AssetInfo* GetAssetInfoAt(int index) { return &m_assetInfo[index]; }

        int GetLayerIndex(uint32_t id) const;
        bool HasLayer(uint32_t id) const { return GetLayerIndex(id) != -1; }
        LayerInfo* GetLayerInfo(uint32_t id);
        LayerInfo* GetLayerInfoAt(int index) { return &m_layerInfo[index]; }

        uint32_t GenerateUniqueLayerID() const;

        bool ReadString(std::string& str);
        bool WriteString(const std::string& str);

        bool BeginReadBlock(uint32_t* id);
        bool EndReadBlock();
        bool BeginWriteBlock(uint32_t id);
        bool EndWriteBlock();

        void ReadHIPA();
        void ReadPACK();
        void ReadPVER();
        void ReadPFLG();
        void ReadPCNT();
        void ReadPCRT();
        void ReadPMOD();
        void ReadPLAT();
        void ReadDICT();
        void ReadATOC();
        void ReadAINF();
        void ReadAHDR();
        void ReadADBG(AssetInfo& ainfo);
        void ReadLTOC();
        void ReadLINF();
        void ReadLHDR();
        void ReadLDBG(LayerInfo& linfo);
        void ReadSTRM();
        void ReadDHDR();
        void ReadDPAK();

        void WriteHIPA();
        void WritePACK();
        void WritePVER();
        void WritePFLG();
        void WritePCNT();
        void WritePCRT();
        void WritePMOD();
        void WritePLAT();
        void WriteDICT();
        void WriteATOC();
        void WriteAINF();
        void WriteAHDR(AssetInfo& ainfo);
        void WriteADBG(AssetInfo& ainfo);
        void WriteLTOC();
        void WriteLINF();
        void WriteLHDR(LayerInfo& linfo);
        void WriteLDBG(LayerInfo& linfo);
        void WriteSTRM();
        void WriteDHDR();
        void WriteDPAK();

        bool CalculateOffsets();
        bool WriteOffsets();

        void DetectEntAssetsHavePad();

        friend class Asset;
        friend class Layer;
    };

}