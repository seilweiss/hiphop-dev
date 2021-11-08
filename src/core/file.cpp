#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "hiphop/core/file.h"

#include "hiphop/core/file_stream.h"
#include "hiphop/core/memory_stream.h"
#include "hiphop/core/util.h"

#include <algorithm>
#include <cstdlib>

#define CLTVER_SCOOBY 0x00040006
#define CLTVER_BFBB 0x000A000F

#define FOUR_CC(a,b,c,d) ( ((a)<<24) | ((b)<<16) | ((c)<<8) | (d) )

namespace HipHop {

    namespace {

        time_t ParseTime(const char* str)
        {
            static const char* WEEKDAYS[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
            static const char* MONTHS[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

            tm t = {};
            char weekday[4];
            char month[4];

            if (sscanf(str, "%3s %3s %d %d:%d:%d %d", weekday, month, &t.tm_mday, &t.tm_hour, &t.tm_min, &t.tm_sec, &t.tm_year) != 7)
            {
                return 0;
            }

            weekday[3] = '\0';
            month[3] = '\0';

            t.tm_year -= 1900;
            t.tm_wday = -1;
            t.tm_mon = -1;

            for (int i = 0; i < 7; i++)
            {
                if (strcmp(weekday, WEEKDAYS[i]) == 0)
                {
                    t.tm_wday = i;
                    break;
                }
            }

            if (t.tm_wday == -1)
            {
                return 0;
            }

            for (int i = 0; i < 12; i++)
            {
                if (strcmp(month, MONTHS[i]) == 0)
                {
                    t.tm_mon = i;
                    break;
                }
            }

            if (t.tm_mon == -1)
            {
                return 0;
            }

#ifdef _WIN32
            return _mkgmtime(&t);
#else
            return timegm(&t);
#endif
        }

        inline uint32_t LayerTypeToInt(LayerType type, Game game)
        {
            static const uint32_t map[(int)Game::Count][(int)LayerType::Count] =
            {
                { 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, // Scooby
                { 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, // BFBB
                { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, // TSSM
                { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, // Incredibles
                { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 } // ROTU
            };

            return map[(int)game][(int)type];
        }

        inline LayerType LayerTypeFromInt(uint32_t x, Game game)
        {
            static const uint32_t map[(int)Game::Count][(int)LayerType::Count] =
            {
                { 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0 }, // Scooby
                { 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0 }, // BFBB
                { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, // TSSM
                { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, // Incredibles
                { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, // ROTU
            };

            return (LayerType)map[(int)game][x];
        }

    }

    File::File()
    {
    }

    File::File(Stream* stream)
    {
        m_stream = stream;
        m_ownsStream = false;
    }

    File::File(const std::string& path)
    {
        m_stream = new FileStream(path);
        m_ownsStream = true;
    }

    File::File(const void* data, size_t size)
    {
        m_stream = new MemoryStream(data, size);
        m_ownsStream = true;
    }

    File::~File()
    {
        if (m_stream && m_ownsStream)
        {
            delete m_stream;
        }

        Destroy();
    }

    void File::Create(Game game, Platform platform, Region region, Language language)
    {
        if (game == Game::Unknown)
        {
            return;
        }

        Destroy();

        m_game = game;
        m_platform = platform;
        m_region = region;
        m_language = language;

        m_ainf = 0;
        m_linf = 0;
        m_dhdr = -1;

        m_subVersion = 2;
        m_compatVersion = 1;

        if (game == Game::ScoobyNightOf100Frights)
        {
            m_clientVersion = CLTVER_SCOOBY; // 4.6
            m_hasPLAT = false;
        }
        else
        {
            m_clientVersion = CLTVER_BFBB; // 10.15
            m_hasPLAT = true;
        }

        m_pflg = 0x2E;

        if (game == Game::BattleForBikiniBottom)
        {
            m_pflg |= 0x02000000;

            switch (platform)
            {
            case Platform::GameCube: m_pflg |= 0x290000; break;
            case Platform::Xbox: m_pflg |= 0x2A0000; break;
            case Platform::PS2: m_pflg |= 0x2C0000; break;
            }
        }

        m_entAssetsHavePad = (game == Game::BattleForBikiniBottom);
        m_entAssetsHavePadDetected = true;

        switch (game)
        {
        case Game::ScoobyNightOf100Frights:
            CreateLayer(LayerType::TEXTURE, false);
            CreateLayer(LayerType::BSP, false);
            CreateLayer(LayerType::MODEL, false);
            CreateLayer(LayerType::ANIMATION, false);
            CreateLayer(LayerType::DEFAULT, false);
            CreateLayer(LayerType::CUTSCENE, false);
            CreateLayer(LayerType::SRAM, false);
            CreateLayer(LayerType::SNDTOC, false);
            break;
        case Game::BattleForBikiniBottom:
            CreateLayer(LayerType::TEXTURE, false);
            CreateLayer(LayerType::TEXTURE, false);
            CreateLayer(LayerType::TEXTURE, false);
            CreateLayer(LayerType::BSP, false);
            CreateLayer(LayerType::BSP, false);
            CreateLayer(LayerType::BSP, false);
            CreateLayer(LayerType::JSPINFO, false);
            CreateLayer(LayerType::MODEL, false);
            CreateLayer(LayerType::MODEL, false);
            CreateLayer(LayerType::MODEL, false);
            CreateLayer(LayerType::ANIMATION, false);
            CreateLayer(LayerType::DEFAULT, false);
            CreateLayer(LayerType::CUTSCENE, false);
            CreateLayer(LayerType::SRAM, false);
            CreateLayer(LayerType::SNDTOC, false);
            break;
        case Game::SpongeBobMovie:
        case Game::Incredibles:
        case Game::RiseOfTheUnderminer:
            CreateLayer(LayerType::TEXTURE, false);
            CreateLayer(LayerType::TEXTURE, false);
            CreateLayer(LayerType::TEXTURE, false);
            CreateLayer(LayerType::TEXTURE_STRM, false);
            CreateLayer(LayerType::MODEL, false);
            CreateLayer(LayerType::MODEL, false);
            CreateLayer(LayerType::MODEL, false);
            CreateLayer(LayerType::ANIMATION, false);
            CreateLayer(LayerType::DEFAULT, false);
            CreateLayer(LayerType::CUTSCENE, false);
            CreateLayer(LayerType::SRAM, false);
            CreateLayer(LayerType::SNDTOC, false);
            CreateLayer(LayerType::CUTSCENETOC, false);
            break;
        }

        SortLayers();
        InitDefaultSettings();
    }

    void File::Destroy()
    {
        UnloadAssets();

        m_assetInfo.clear();
        m_layerInfo.clear();
    }

    void File::InitDefaultSettings()
    {
        m_defaultAssetTypeLayer.clear();

        m_defaultAssetTypeLayer[AssetType::RWTX] = LayerType::TEXTURE;
        m_defaultAssetTypeLayer[AssetType::BINK] = LayerType::TEXTURE_STRM;
        m_defaultAssetTypeLayer[AssetType::TEXS] = LayerType::TEXTURE_STRM;
        m_defaultAssetTypeLayer[AssetType::WIRE] = LayerType::TEXTURE_STRM;
        m_defaultAssetTypeLayer[AssetType::BSP] = LayerType::BSP;
        m_defaultAssetTypeLayer[AssetType::JSP] = LayerType::BSP;
        m_defaultAssetTypeLayer[AssetType::MODL] = LayerType::MODEL;
        m_defaultAssetTypeLayer[AssetType::CSSS] = LayerType::SRAM;
        m_defaultAssetTypeLayer[AssetType::SND] = LayerType::SRAM;
        m_defaultAssetTypeLayer[AssetType::SNDS] = LayerType::SRAM;
        m_defaultAssetTypeLayer[AssetType::SNDI] = LayerType::SNDTOC;
        m_defaultAssetTypeLayer[AssetType::CSN] = LayerType::CUTSCENE;

        switch (m_game)
        {
        case Game::ScoobyNightOf100Frights:
            m_defaultAssetTypeLayer[AssetType::ANIM] = LayerType::DEFAULT;
            m_defaultAssetTypeLayer[AssetType::CTOC] = LayerType::SNDTOC;
            break;
        case Game::BattleForBikiniBottom:
            m_defaultAssetTypeLayer[AssetType::ANIM] = LayerType::ANIMATION;
            m_defaultAssetTypeLayer[AssetType::CTOC] = LayerType::SNDTOC;
            break;
        case Game::SpongeBobMovie:
        case Game::Incredibles:
        case Game::RiseOfTheUnderminer:
            m_defaultAssetTypeLayer[AssetType::ANIM] = LayerType::ANIMATION;
            m_defaultAssetTypeLayer[AssetType::CTOC] = LayerType::CUTSCENETOC;
        }

        switch (m_platform)
        {
        case Platform::GameCube:
            m_defaultLayerAlign = 32;
            break;
        case Platform::PS2:
        case Platform::Xbox:
            m_defaultLayerAlign = 2048;
            break;
        }
    }

    void File::SetStream(Stream* stream)
    {
        if (m_stream && m_ownsStream)
        {
            delete m_stream;
        }

        m_stream = stream;
        m_ownsStream = false;
    }

    bool File::Read()
    {
        if (!m_stream || !m_stream->IsOpen() || !m_stream->IsOK())
        {
            return false;
        }

        m_game = Game::Unknown;
        m_platform = Platform::Unknown;
        m_language = Language::USCommon;
        m_region = Region::NTSC;

        m_stream->SetEndian(Endian::Big);

        {
            // Check if valid HIP/HOP file

            if (m_stream->GetSize() - m_stream->Tell() < 8)
            {
                return false;
            }

            size_t oldPos = m_stream->Tell();

            uint32_t hipa;
            m_stream->Read(&hipa);

            if (hipa != 'HIPA')
            {
                return false;
            }

            m_stream->Seek(oldPos);
        }

        m_blockDepth = -1;

        uint32_t id;

        while (BeginReadBlock(&id))
        {
            switch (id)
            {
            case 'HIPA': ReadHIPA(); break;
            case 'PACK': ReadPACK(); break;
            case 'DICT': ReadDICT(); break;
            case 'STRM': ReadSTRM(); break;
            }

            EndReadBlock();
        }

        if (!m_stream->IsOK())
        {
            return false;
        }

        if (m_game == Game::Unknown && m_unknownWhetherGameIsTSSMIncOrROTU)
        {
            bool couldBeTSSM = true;
            bool couldBeInc = true;
            bool couldBeROTU = true;

            for (const AssetInfo& ainfo : m_assetInfo)
            {
                switch (ainfo.type)
                {
                case AssetType::DSCO:
                case AssetType::EGEN:
                case AssetType::FLY:
                case AssetType::PKUP:
                    m_game = Game::SpongeBobMovie;
                    break;
                case AssetType::ATKT:
                case AssetType::DTRK:
                case AssetType::DUPC:
                case AssetType::GRSM:
                case AssetType::ONEL:
                case AssetType::SLID:
                case AssetType::SPLP:
                case AssetType::SSET:
                case AssetType::VIL:
                case AssetType::ZLIN:
                    m_game = Game::Incredibles;
                    break;
                case AssetType::CCRV:
                case AssetType::HANG:
                case AssetType::VOLU:
                    m_game = Game::RiseOfTheUnderminer;
                    break;
                case AssetType::BINK:
                case AssetType::NGMS:
                case AssetType::NPCS:
                case AssetType::PGRS:
                case AssetType::SUBT:
                case AssetType::TPIK:
                case AssetType::TRWT:
                case AssetType::WIRE:
                    couldBeTSSM = false;
                    break;
                case AssetType::JAW:
                case AssetType::PARE:
                case AssetType::PARP:
                case AssetType::PARS:
                case AssetType::PICK:
                    couldBeInc = false;
                    break;
                case AssetType::BUTN:
                case AssetType::CSN:
                case AssetType::CSNM:
                case AssetType::CSSS:
                case AssetType::CTOC:
                case AssetType::RANM:
                    couldBeROTU = false;
                    break;
                }

                if (m_game != Game::Unknown)
                {
                    break;
                }

                if (couldBeTSSM && !couldBeInc && !couldBeROTU)
                {
                    m_game = Game::SpongeBobMovie;
                    break;
                }

                if (couldBeInc && !couldBeTSSM && !couldBeROTU)
                {
                    m_game = Game::Incredibles;
                    break;
                }

                if (couldBeROTU && !couldBeTSSM && !couldBeInc)
                {
                    m_game = Game::RiseOfTheUnderminer;
                    break;
                }
            }
        }

        {
            Game layerGame = m_game;

            if (m_game == Game::Unknown)
            {
                if (m_unknownWhetherGameIsTSSMIncOrROTU)
                {
                    layerGame = Game::SpongeBobMovie;
                }
                else
                {
                    layerGame = Game::ScoobyNightOf100Frights;
                }
            }

            for (LayerInfo& linfo : m_layerInfo)
            {
                linfo.type = LayerTypeFromInt(linfo.readType, layerGame);
            }
        }

        m_entAssetsHavePadDetected = false;

        InitDefaultSettings();

        return true;
    }

    bool File::Write()
    {
        if (!m_stream || !m_stream->IsOpen() || !m_stream->IsOK())
        {
            return false;
        }

        if (m_game == Game::Unknown)
        {
            return false;
        }

        m_stream->SetEndian(Endian::Big);

        if (!LoadAssets()) // Make sure all assets are loaded first
        {
            return false;
        }

        m_stream->Clear();
        m_stream->SetPadByte(m_scoobyBeta ? 0x00 : 0x33);

        m_blockDepth = -1;

        BeginWriteBlock('HIPA');
        WriteHIPA();
        EndWriteBlock();

        BeginWriteBlock('PACK');
        WritePACK();
        EndWriteBlock();

        BeginWriteBlock('DICT');
        WriteDICT();
        EndWriteBlock();

        BeginWriteBlock('STRM');
        WriteSTRM();
        EndWriteBlock();

        if (!m_stream->IsOK())
        {
            return false;
        }

        return true;
    }

    bool File::LoadAssets()
    {
        if (!m_stream || !m_stream->IsOpen() || !m_stream->IsOK())
        {
            return false;
        }

        for (AssetInfo& ainfo : m_assetInfo)
        {
            if (!LoadAsset(ainfo))
            {
                return false;
            }
        }

        return true;
    }

    bool File::UnloadAssets()
    {
        for (AssetInfo& ainfo : m_assetInfo)
        {
            if (!UnloadAsset(ainfo))
            {
                return false;
            }
        }

        return true;
    }

    bool File::LoadAsset(Asset asset)
    {
        AssetInfo* ainfo = GetAssetInfo(asset);

        if (ainfo)
        {
            return LoadAsset(*ainfo);
        }

        return false;
    }

    bool File::LoadAsset(AssetInfo& ainfo)
    {
        if (!m_stream || !m_stream->IsOpen() || !m_stream->IsOK())
        {
            return false;
        }

        if (ainfo.loaded)
        {
            return true;
        }

        if (ainfo.size > 0)
        {
            ainfo.data = malloc(ainfo.size);

            if (!ainfo.data)
            {
                return false;
            }

            m_stream->Seek(ainfo.offset);

            if (m_stream->Read(ainfo.data, ainfo.size) != ainfo.size)
            {
                return false;
            }
        }

        ainfo.loaded = true;

        return true;
    }

    bool File::UnloadAsset(Asset asset)
    {
        AssetInfo* ainfo = GetAssetInfo(asset);

        if (ainfo)
        {
            return LoadAsset(*ainfo);
        }

        return false;
    }

    bool File::UnloadAsset(AssetInfo& ainfo)
    {
        if (!ainfo.loaded)
        {
            return true;
        }

        if (ainfo.data)
        {
            free(ainfo.data);
        }

        ainfo.data = nullptr;
        ainfo.loaded = false;

        return true;
    }

    bool File::LoadLayer(Layer layer)
    {
        LayerInfo* linfo = GetLayerInfo(layer.m_id);

        if (linfo)
        {
            return LoadLayer(*linfo);
        }

        return false;
    }

    bool File::LoadLayer(LayerInfo& linfo)
    {
        if (!m_stream || !m_stream->IsOpen() || !m_stream->IsOK())
        {
            return false;
        }

        for (uint32_t id : linfo.assetIDs)
        {
            int assetIndex = GetAssetIndex(id);

            if (assetIndex != -1)
            {
                if (!LoadAsset(GetAsset(assetIndex)))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool File::UnloadLayer(Layer layer)
    {
        LayerInfo* linfo = GetLayerInfo(layer.m_id);

        if (linfo)
        {
            return UnloadLayer(*linfo);
        }

        return false;
    }

    bool File::UnloadLayer(LayerInfo& linfo)
    {
        for (uint32_t id : linfo.assetIDs)
        {
            int assetIndex = GetAssetIndex(id);

            if (assetIndex != -1)
            {
                if (!UnloadAsset(GetAsset(assetIndex)))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool File::CompareAssets(const AssetInfo& a, const AssetInfo& b)
    {
        return a.id < b.id;
    }

    bool File::CompareLayers(const LayerInfo& a, const LayerInfo& b)
    {
        static const int order[] =
        {
            5, // DEFAULT
            0, // TEXTURE
            1, // TEXTURE_STRM
            2, // BSP
            3, // MODEL
            4, // ANIMATION
            7, // VRAM
            8, // SRAM
            9, // SNDTOC
            6, // CUTSCENE
            10, // CUTSCENETOC
            2 // JSPINFO - same as BSP (BSP and JSPINFO are grouped together)
        };

        return order[(int)a.type] < order[(int)b.type];
    }

    void File::SortAssets()
    {
        std::sort(m_assetInfo.begin(), m_assetInfo.end(), CompareAssets);
    }

    void File::SortLayers()
    {
        std::sort(m_layerInfo.begin(), m_layerInfo.end(), CompareLayers);
    }

    uint32_t File::GenerateUniqueAssetID(const std::string& name) const
    {
        uint32_t id = Util::Hash(name);

        while (id == 0 || HasAsset(id))
        {
            id++;
        }

        return id;
    }

    uint32_t File::GenerateUniqueLayerID() const
    {
        uint32_t id = rand();

        while (id == 0 || HasLayer(id))
        {
            id++;
        }

        return id;
    }

    bool File::DoEntAssetsHavePad()
    {
        if (!m_entAssetsHavePadDetected)
        {
            DetectEntAssetsHavePad();
            m_entAssetsHavePadDetected = true;
        }

        return m_entAssetsHavePad;
    }

    std::vector<Asset> File::GetAssets()
    {
        std::vector<Asset> assets;

        for (const AssetInfo& ainfo : m_assetInfo)
        {
            assets.push_back(Asset(this, ainfo.id));
        }

        return assets;
    }

    std::vector<Asset> File::GetAssets(AssetType type)
    {
        std::vector<Asset> assets;

        for (const AssetInfo& ainfo : m_assetInfo)
        {
            if (ainfo.type == type)
            {
                assets.push_back(Asset(this, ainfo.id));
            }
        }

        return assets;
    }

    int File::GetAssetCount(AssetType type) const
    {
        int count = 0;

        for (const AssetInfo& ainfo : m_assetInfo)
        {
            if (ainfo.type == type)
            {
                count++;
            }
        }

        return count;
    }

    File::AssetInfo* File::GetAssetInfo(uint32_t id)
    {
        int index = GetAssetIndex(id);

        return (index != -1) ? &m_assetInfo[index] : nullptr;
    }

    int File::GetAssetIndex(uint32_t id) const
    {
        if (id == 0)
        {
            return -1;
        }

        if (m_assetInfo.empty())
        {
            return -1;
        }

        if (m_assetInfo.size() == 1 && m_assetInfo[0].id == id)
        {
            return 0;
        }

        int32_t assetCount = (int32_t)m_assetInfo.size();
        int32_t index = (int32_t)((float)id / 0xFFFFFFFF * assetCount);

        if (index >= assetCount)
        {
            index = assetCount - 1;
        }

        if (m_assetInfo[index].id == id)
        {
            return index;
        }

        if (m_assetInfo[index].id < id)
        {
            index++;

            while (index < assetCount)
            {
                if (m_assetInfo[index].id == id)
                {
                    return index;
                }

                index++;
            }
        }
        else
        {
            index--;

            while (index >= 0)
            {
                if (m_assetInfo[index].id == id)
                {
                    return index;
                }

                index--;
            }
        }

        return -1;
    }

    int File::GetAssetIndex(AssetType type, int index) const
    {
        for (int i = 0; i < (int)m_assetInfo.size(); i++)
        {
            if (m_assetInfo[i].type == type)
            {
                if (index == 0)
                {
                    return i;
                }

                index--;
            }
        }

        return -1;
    }

    Asset File::CreateAsset(AssetType type, const std::string& name)
    {
        Layer layer;
        LayerType layerType = GetDefaultLayerType(type);
        int layerCount = GetLayerCount(layerType);

        if (layerCount == 0)
        {
            layer = CreateLayer(LayerType::DEFAULT);
        }
        else
        {
            layer = GetLayer(layerType, 0);

            for (int i = 1; i < layerCount; i++)
            {
                Layer testLayer = GetLayer(layerType, i);

                if (testLayer.GetAssetCount() < layer.GetAssetCount())
                {
                    layer = testLayer;
                }
            }
        }

        return CreateAsset(type, name, layer);
    }

    Asset File::CreateAsset(AssetType type, const std::string& name, Layer layer)
    {
        if (!layer)
        {
            return Asset();
        }

        uint32_t id = GenerateUniqueAssetID(name);
        AssetInfo ainfo;

        ainfo.type = type;
        ainfo.name = name;
        ainfo.id = id;
        ainfo.align = GetDefaultAssetAlign(type);
        ainfo.flags = GetDefaultAssetFlags(type);
        ainfo.loaded = true;

        m_assetInfo.push_back(ainfo);

        layer.AddAssetID(id);

        SortAssets();

        return Asset(this, id);
    }

    JSPGroup File::CreateJSPGroup(const std::string& name, int jspCount)
    {
        JSPGroup group;

        if (m_game == Game::Unknown || m_game == Game::ScoobyNightOf100Frights)
        {
            return group;
        }

        if (jspCount < 0)
        {
            jspCount = 0;
        }
        else if (jspCount > 3)
        {
            jspCount = 3;
        }

        group.jsps.reserve(jspCount);

        if (m_game == Game::BattleForBikiniBottom)
        {
            for (int i = 0; i < jspCount; i++)
            {
                Layer bspLayer = GetLayer(LayerType::BSP, i);

                if (bspLayer)
                {
                    group.jsps.push_back(CreateAsset(AssetType::JSP, name + std::to_string(i), bspLayer));
                }
            }

            Layer jspInfoLayer = GetLayer(LayerType::JSPINFO);

            if (jspInfoLayer)
            {
                group.jspInfo = CreateAsset(AssetType::JSP, name, jspInfoLayer);
            }
        }
        else
        {
            for (int i = 0; i < jspCount; i++)
            {
                Layer bspLayer = CreateLayer(LayerType::BSP, false);

                group.jsps.push_back(CreateAsset(AssetType::JSP, name + std::to_string(i), bspLayer));
            }

            Layer jspInfoLayer = CreateLayer(LayerType::JSPINFO, false);

            group.jspInfo = CreateAsset(AssetType::JSP, name, jspInfoLayer);

            SortLayers();
        }

        return group;
    }

    std::vector<Layer> File::GetLayers()
    {
        std::vector<Layer> layers;

        for (int i = 0; i < (int)m_layerInfo.size(); i++)
        {
            layers.push_back(Layer(this, i));
        }

        return layers;
    }

    std::vector<Layer> File::GetLayers(LayerType type)
    {
        std::vector<Layer> layers;

        for (int i = 0; i < (int)m_layerInfo.size(); i++)
        {
            if (m_layerInfo[i].type == type)
            {
                layers.push_back(Layer(this, i));
            }
        }

        return layers;
    }

    int File::GetLayerCount(LayerType type) const
    {
        int count = 0;

        for (const LayerInfo& linfo : m_layerInfo)
        {
            if (linfo.type == type)
            {
                count++;
            }
        }

        return count;
    }

    int File::GetLayerIndex(LayerType type, int index) const
    {
        for (int i = 0; i < (int)m_layerInfo.size(); i++)
        {
            if (m_layerInfo[i].type == type)
            {
                if (index == 0)
                {
                    return i;
                }

                index--;
            }
        }

        return -1;
    }

    int File::GetLayerIndex(Asset asset) const
    {
        for (int i = 0; i < (int)m_layerInfo.size(); i++)
        {
            for (uint32_t id : m_layerInfo[i].assetIDs)
            {
                if (id == asset.GetID())
                {
                    return i;
                }
            }
        }

        return -1;
    }

    int File::GetLayerIndex(uint32_t id) const
    {
        if (id == 0)
        {
            return -1;
        }

        for (int i = 0; i < (int)m_layerInfo.size(); i++)
        {
            if (m_layerInfo[i].id == id)
            {
                return i;
            }
        }

        return -1;
    }

    File::LayerInfo* File::GetLayerInfo(uint32_t id)
    {
        int index = GetLayerIndex(id);

        return (index != -1) ? &m_layerInfo[index] : nullptr;
    }

    Layer File::CreateLayer(LayerType type, bool sort)
    {
        uint32_t id = GenerateUniqueLayerID();
        LayerInfo linfo;

        linfo.id = id;
        linfo.type = type;
        linfo.align = -1;

        m_layerInfo.push_back(linfo);

        SortLayers();

        return Layer(this, GetLayerIndex(id));
    }

    bool File::ReadString(std::string& str)
    {
        str.clear();
        str.reserve(32);

        size_t len = 0;

        while (true)
        {
            if (m_stream->AtEnd())
            {
                break;
            }

            char ch;

            if (m_stream->Read(&ch, sizeof(char)) != sizeof(char))
            {
                return false;
            }

            len++;

            if (ch == '\0')
            {
                break;
            }

            str.push_back(ch);
        }

        if (len & 1)
        {
            char pad;

            if (m_stream->Read(&pad, sizeof(char)) != sizeof(char))
            {
                return false;
            }
        }

        return true;
    }

    bool File::WriteString(const std::string& str)
    {
        const char* buf = str.c_str();
        size_t len = strlen(buf) + 1;

        if (m_stream->Write(buf, len) != len)
        {
            return false;
        }

        if (len & 1)
        {
            char pad = '\0';

            if (m_stream->Write(&pad, sizeof(char)) != sizeof(char))
            {
                return false;
            }
        }

        return true;
    }

    bool File::BeginReadBlock(uint32_t* id)
    {
        if (m_stream->AtEnd())
        {
            return false;
        }

        if (m_blockDepth >= HIPHOP_FILE_MAX_BLOCK_DEPTH - 1)
        {
            return false;
        }

        if (m_blockDepth >= 0 && m_stream->Tell() >= m_blockReadInfo[m_blockDepth].endpos)
        {
            return false;
        }

        if (m_stream->Read(id) != sizeof(uint32_t))
        {
            return false;
        }

        uint32_t length;

        if (m_stream->Read(&length) != sizeof(uint32_t))
        {
            return false;
        }

        BlockReadInfo* block = &m_blockReadInfo[++m_blockDepth];
        block->endpos = m_stream->Tell() + length;

        return true;
    }

    bool File::EndReadBlock()
    {
        if (m_blockDepth < 0)
        {
            return false;
        }

        BlockReadInfo* block = &m_blockReadInfo[m_blockDepth--];

        m_stream->Seek(block->endpos);

        return true;
    }

    bool File::BeginWriteBlock(uint32_t id)
    {
        if (m_blockDepth >= HIPHOP_FILE_MAX_BLOCK_DEPTH - 1)
        {
            return false;
        }

        if (m_stream->Write(&id) != sizeof(uint32_t))
        {
            return false;
        }

        size_t lenpos = m_stream->Tell();
        uint32_t placeholderLength = 0;

        if (m_stream->Write(&placeholderLength) != sizeof(uint32_t))
        {
            return false;
        }

        BlockWriteInfo* block = &m_blockWriteInfo[++m_blockDepth];

        block->lenpos = lenpos;
        block->datapos = m_stream->Tell();

        return true;
    }

    bool File::EndWriteBlock()
    {
        if (m_blockDepth < 0)
        {
            return false;
        }

        BlockWriteInfo* block = &m_blockWriteInfo[m_blockDepth--];
        size_t endpos = m_stream->Tell();
        uint32_t length = (uint32_t)(endpos - block->datapos);

        m_stream->Seek(block->lenpos);

        if (m_stream->Write(&length) != sizeof(uint32_t))
        {
            m_blockDepth++;
            return false;
        }

        m_stream->Seek(endpos);

        return true;
    }

    void File::ReadHIPA()
    {
    }

    void File::ReadPACK()
    {
        m_hasPLAT = false;

        uint32_t id;

        while (BeginReadBlock(&id))
        {
            switch (id)
            {
            case 'PVER': ReadPVER(); break;
            case 'PFLG': ReadPFLG(); break;
            case 'PCNT': ReadPCNT(); break;
            case 'PCRT': ReadPCRT(); break;
            case 'PMOD': ReadPMOD(); break;
            case 'PLAT': m_hasPLAT = true; ReadPLAT(); break;
            }

            EndReadBlock();
        }
    }

    void File::ReadPVER()
    {
        m_stream->Read(&m_subVersion);
        m_stream->Read(&m_clientVersion);
        m_stream->Read(&m_compatVersion);

        if (m_game == Game::Unknown && m_clientVersion == CLTVER_SCOOBY)
        {
            m_game = Game::ScoobyNightOf100Frights;
        }
    }

    void File::ReadPFLG()
    {
        m_stream->Read(&m_pflg);

        if (m_game == Game::Unknown && (m_pflg & 0x02000000))
        {
            m_game = Game::BattleForBikiniBottom;
        }
    }

    void File::ReadPCNT()
    {
        uint32_t assetCount, layerCount;

        m_stream->Read(&assetCount);
        m_stream->Read(&layerCount);

        m_assetInfo.reserve(assetCount);
        m_layerInfo.reserve(layerCount);
    }

    void File::ReadPCRT()
    {
        uint32_t t;
        std::string s;

        m_stream->Read(&t);
        ReadString(s);

        m_createdTime = (time_t)t;

        time_t strTime = ParseTime(s.c_str());

        if (strTime != 0)
        {
            m_timezoneOffset = m_createdTime - strTime;
        }

        m_endTimeStringWithNewline = (s.back() == '\n');
    }

    void File::ReadPMOD()
    {
        uint32_t t;

        m_stream->Read(&t);

        m_modifiedTime = (time_t)t;
    }

    void File::ReadPLAT()
    {
        uint32_t platformID;

        m_stream->Read(&platformID);

        std::vector<std::string> platformInfo;

        while (m_stream->Tell() < m_blockReadInfo[m_blockDepth].endpos)
        {
            std::string s;

            ReadString(s);

            platformInfo.push_back(s);
        }

        switch (platformID)
        {
        case FOUR_CC('G', 'C', '\0', '\0'):
            m_platform = Platform::GameCube;
            break;
        case FOUR_CC('P', '2', '\0', '\0'):
        case FOUR_CC('P', 'S', '2', '\0'):
            m_platform = Platform::PS2;
            break;
        case FOUR_CC('X', 'B', '\0', '\0'):
        case FOUR_CC('B', 'X', '\0', '\0'):
            m_platform = Platform::Xbox;
            break;
        }

        if (!platformInfo.empty() && platformInfo.back() == "Sponge Bob")
        {
            m_game = Game::BattleForBikiniBottom;
        }

        m_unknownWhetherGameIsTSSMIncOrROTU = (m_game == Game::Unknown);

        if (platformInfo.size() >= 3)
        {
            std::string region = platformInfo[1];
            std::string language = (m_game == Game::BattleForBikiniBottom) ? platformInfo[2] : platformInfo[0];

            m_region = RegionFromString(region);
            m_language = LanguageFromString(language);
        }
    }

    void File::ReadDICT()
    {
        uint32_t id;

        while (BeginReadBlock(&id))
        {
            switch (id)
            {
            case 'ATOC': ReadATOC(); break;
            case 'LTOC': ReadLTOC(); break;
            }

            EndReadBlock();
        }
    }

    void File::ReadATOC()
    {
        uint32_t id;

        while (BeginReadBlock(&id))
        {
            switch (id)
            {
            case 'AINF': ReadAINF(); break;
            case 'AHDR': ReadAHDR(); break;
            }

            EndReadBlock();
        }
    }

    void File::ReadAINF()
    {
        m_stream->Read(&m_ainf);
    }

    void File::ReadAHDR()
    {
        AssetInfo ainfo;
        uint32_t type;

        m_stream->Read(&ainfo.id);
        m_stream->Read(&type);
        m_stream->Read(&ainfo.offset);
        m_stream->Read(&ainfo.size);
        m_stream->Read(&ainfo.plus);
        m_stream->Read(&ainfo.flags);

        ainfo.type = (AssetType)type;
        ainfo.data = nullptr;
        ainfo.loaded = false;

        if (ainfo.size == 0)
        {
            m_writeAssetOffsetZeroIfSizeZero = (ainfo.offset == 0);
        }

        uint32_t id;

        while (BeginReadBlock(&id))
        {
            switch (id)
            {
            case 'ADBG': ReadADBG(ainfo); break;
            }

            EndReadBlock();
        }

        m_assetInfo.push_back(ainfo);
    }

    void File::ReadADBG(AssetInfo& ainfo)
    {
        m_stream->Read(&ainfo.align);
        ReadString(ainfo.name);
        ReadString(ainfo.filename);
        m_stream->Read(&ainfo.checksum);
    }

    void File::ReadLTOC()
    {
        uint32_t id;

        while (BeginReadBlock(&id))
        {
            switch (id)
            {
            case 'LINF': ReadLINF(); break;
            case 'LHDR': ReadLHDR(); break;
            }

            EndReadBlock();
        }
    }

    void File::ReadLINF()
    {
        m_stream->Read(&m_linf);
    }

    void File::ReadLHDR()
    {
        LayerInfo linfo;
        uint32_t assetCount;

        m_stream->Read(&linfo.readType);
        m_stream->Read(&assetCount);

        for (uint32_t i = 0; i < assetCount; i++)
        {
            uint32_t id;

            m_stream->Read(&id);

            linfo.assetIDs.push_back(id);
        }

        uint32_t id;

        while (BeginReadBlock(&id))
        {
            switch (id)
            {
            case 'LDBG': ReadLDBG(linfo); break;
            }

            EndReadBlock();
        }

        linfo.id = GenerateUniqueLayerID();

        m_layerInfo.push_back(linfo);
    }

    void File::ReadLDBG(LayerInfo& linfo)
    {
        m_stream->Read(&linfo.align);
    }

    void File::ReadSTRM()
    {
        uint32_t id;

        while (BeginReadBlock(&id))
        {
            switch (id)
            {
            case 'DHDR': ReadDHDR(); break;
            case 'DPAK': ReadDPAK(); break;
            }

            EndReadBlock();
        }
    }

    void File::ReadDHDR()
    {
        m_stream->Read(&m_dhdr);
    }

    void File::ReadDPAK()
    {
    }

    void File::WriteHIPA()
    {
    }

    void File::WritePACK()
    {
        BeginWriteBlock('PVER');
        WritePVER();
        EndWriteBlock();

        BeginWriteBlock('PFLG');
        WritePFLG();
        EndWriteBlock();

        BeginWriteBlock('PCNT');
        WritePCNT();
        EndWriteBlock();

        BeginWriteBlock('PCRT');
        WritePCRT();
        EndWriteBlock();

        BeginWriteBlock('PMOD');
        WritePMOD();
        EndWriteBlock();

        if (m_hasPLAT)
        {
            BeginWriteBlock('PLAT');
            WritePLAT();
            EndWriteBlock();
        }
    }

    void File::WritePVER()
    {
        m_stream->Write(&m_subVersion);
        m_stream->Write(&m_clientVersion);
        m_stream->Write(&m_compatVersion);
    }

    void File::WritePFLG()
    {
        m_stream->Write(&m_pflg);
    }

    void File::WritePCNT()
    {
        uint32_t assetCount = (uint32_t)m_assetInfo.size();
        uint32_t layerCount = (uint32_t)m_layerInfo.size();

        m_stream->Write(&assetCount);
        m_stream->Write(&layerCount);

        uint32_t maxAssetSize = 0;
        uint32_t maxXformSize = 0;

        for (const AssetInfo& ainfo : m_assetInfo)
        {
            if (ainfo.size > maxAssetSize)
            {
                maxAssetSize = ainfo.size;
            }

            if ((ainfo.flags & Asset::READ_TRANSFORM) && ainfo.size > maxXformSize)
            {
                maxXformSize = ainfo.size;
            }
        }

        m_stream->Write(&maxAssetSize);

        m_maxLayerSizeWritePos = m_stream->Tell();

        uint32_t placeholderSize = 0;
        m_stream->Write(&placeholderSize);

        m_stream->Write(&maxXformSize);
    }

    void File::WritePCRT()
    {
        uint32_t t = (uint32_t)m_createdTime;

        m_stream->Write(&t);

        time_t time = m_createdTime - m_timezoneOffset;
        struct tm* tp = gmtime(&time);
        char str[32];

        strftime(str, sizeof(str), "%a %b %d %H:%M:%S %Y", tp);

        if (m_endTimeStringWithNewline)
        {
            strcat(str, "\n");
        }

        WriteString(str);
    }

    void File::WritePMOD()
    {
        uint32_t t = (uint32_t)m_modifiedTime;

        m_stream->Write(&t);
    }

    void File::WritePLAT()
    {
        uint32_t platformID;

        switch (m_game)
        {
        case Game::BattleForBikiniBottom:
        {
            switch (m_platform)
            {
            case Platform::GameCube: platformID = FOUR_CC('G', 'C', '\0', '\0'); break;
            case Platform::PS2: platformID = FOUR_CC('P', '2', '\0', '\0'); break;
            case Platform::Xbox: platformID = FOUR_CC('X', 'B', '\0', '\0'); break;
            }

            break;
        }
        case Game::SpongeBobMovie:
        case Game::Incredibles:
        case Game::RiseOfTheUnderminer:
        {
            switch (m_platform)
            {
            case Platform::GameCube: platformID = FOUR_CC('G', 'C', '\0', '\0'); break;
            case Platform::PS2: platformID = FOUR_CC('P', 'S', '2', '\0'); break;
            case Platform::Xbox: platformID = FOUR_CC('B', 'X', '\0', '\0'); break;
            }

            break;
        }
        }

        m_stream->Write(&platformID);

        switch (m_game)
        {
        case Game::BattleForBikiniBottom:
        {
            WriteString(PlatformToString(m_platform));
            WriteString(RegionToString(m_region));
            WriteString(LanguageToString(m_language));
            WriteString("Sponge Bob");
            break;
        }
        case Game::SpongeBobMovie:
        case Game::Incredibles:
        case Game::RiseOfTheUnderminer:
        {
            WriteString(LanguageToString(m_language));
            WriteString(RegionToString(m_region));
            WriteString("Incredibles");
            break;
        }
        }
    }

    void File::WriteDICT()
    {
        BeginWriteBlock('ATOC');
        WriteATOC();
        EndWriteBlock();

        BeginWriteBlock('LTOC');
        WriteLTOC();
        EndWriteBlock();
    }

    void File::WriteATOC()
    {
        BeginWriteBlock('AINF');
        WriteAINF();
        EndWriteBlock();

        for (AssetInfo& ainfo : m_assetInfo)
        {
            BeginWriteBlock('AHDR');
            WriteAHDR(ainfo);
            EndWriteBlock();
        }
    }

    void File::WriteAINF()
    {
        m_stream->Write(&m_ainf);
    }

    void File::WriteAHDR(AssetInfo& ainfo)
    {
        uint32_t type = (uint32_t)ainfo.type;

        m_stream->Write(&ainfo.id);
        m_stream->Write(&type);

        ainfo.writeOffsetPos = m_stream->Tell();

        uint32_t placeholderOffset = 0;
        m_stream->Write(&placeholderOffset);

        m_stream->Write(&ainfo.size);
        m_stream->Write(&ainfo.plus);
        m_stream->Write(&ainfo.flags);

        BeginWriteBlock('ADBG');
        WriteADBG(ainfo);
        EndWriteBlock();
    }

    void File::WriteADBG(AssetInfo& ainfo)
    {
        m_stream->Write(&ainfo.align);
        WriteString(ainfo.name);
        WriteString(ainfo.filename);
        m_stream->Write(&ainfo.checksum);
    }

    void File::WriteLTOC()
    {
        BeginWriteBlock('LINF');
        WriteLINF();
        EndWriteBlock();

        for (LayerInfo& linfo : m_layerInfo)
        {
            BeginWriteBlock('LHDR');
            WriteLHDR(linfo);
            EndWriteBlock();
        }
    }

    void File::WriteLINF()
    {
        m_stream->Write(&m_linf);
    }

    void File::WriteLHDR(LayerInfo& linfo)
    {
        uint32_t type = LayerTypeToInt(linfo.type, m_game);

        m_stream->Write(&type);

        uint32_t assetCount = (uint32_t)linfo.assetIDs.size();
        m_stream->Write(&assetCount);

        for (uint32_t id : linfo.assetIDs)
        {
            m_stream->Write(&id);
        }

        BeginWriteBlock('LDBG');
        WriteLDBG(linfo);
        EndWriteBlock();
    }

    void File::WriteLDBG(LayerInfo& linfo)
    {
        m_stream->Write(&linfo.align);
    }

    void File::WriteSTRM()
    {
        BeginWriteBlock('DHDR');
        WriteDHDR();
        EndWriteBlock();

        BeginWriteBlock('DPAK');
        WriteDPAK();
        EndWriteBlock();
    }

    void File::WriteDHDR()
    {
        m_stream->Write(&m_dhdr);
    }

    void File::WriteDPAK()
    {
        bool empty = (m_assetInfo.size() == 0);
        size_t padStart = m_stream->Tell();

        if (!empty && !m_scoobyBeta)
        {
            padStart += sizeof(uint32_t);
        }

        int32_t align = m_defaultLayerAlign;

        if (!m_scoobyBeta && m_layerInfo.size() && m_layerInfo[0].align > 0)
        {
            align = m_layerInfo[0].align;
        }

        if (m_scoobyBeta)
        {
            m_dpakDataStart = padStart;
        }
        else
        {
            m_dpakDataStart = Util::Align(padStart, align);
        }

        CalculateOffsets();

        if (!m_scoobyBeta)
        {
            uint32_t padAmount = (uint32_t)(m_dpakDataStart - padStart);

            if (!empty)
            {
                m_stream->Write(&padAmount);
            }

            m_stream->Skip(padAmount);
        }

        if (!empty)
        {
            for (const LayerInfo& linfo : m_layerInfo)
            {
                for (uint32_t id : linfo.assetIDs)
                {
                    int index = GetAssetIndex(id);

                    if (index >= 0)
                    {
                        AssetInfo* ainfo = GetAssetInfoAt(index);

                        if (ainfo)
                        {
                            if (ainfo->data)
                            {
                                m_stream->Write(ainfo->data, ainfo->size);
                            }
                            else
                            {
                                uint8_t oldPadByte = m_stream->GetPadByte();

                                m_stream->SetPadByte(0x00);
                                m_stream->Skip(ainfo->size);
                                m_stream->SetPadByte(oldPadByte);
                            }

                            m_stream->Skip(ainfo->plus);
                        }
                    }
                }

                m_stream->Skip(linfo.plus);
            }
        }

        size_t offset = m_stream->Tell();

        WriteOffsets();

        m_stream->Seek(offset);
    }

    bool File::CalculateOffsets()
    {
        size_t offset = m_dpakDataStart;
        size_t layerCount = m_layerInfo.size();

        for (size_t i = 0; i < layerCount; i++)
        {
            LayerInfo& linfo = m_layerInfo[i];
            size_t assetCount = linfo.assetIDs.size();

            for (size_t j = 0; j < assetCount; j++)
            {
                int index = GetAssetIndex(linfo.assetIDs[j]);

                if (index == -1)
                {
                    return false;
                }

                AssetInfo* ainfo = GetAssetInfoAt(index);

                if (ainfo)
                {
                    uint32_t size = ainfo->size;

                    ainfo->offset = (uint32_t)offset;

                    if (j == assetCount - 1)
                    {
                        ainfo->plus = 0;
                    }
                    else
                    {
                        int nextIndex = GetAssetIndex(linfo.assetIDs[j + 1]);

                        if (nextIndex == -1)
                        {
                            return false;
                        }

                        AssetInfo* nextAinfo = GetAssetInfoAt(nextIndex);

                        if (nextAinfo)
                        {
                            int32_t align = nextAinfo->align;

                            if (align <= 0)
                            {
                                align = GetDefaultAssetAlign(nextAinfo->type);
                            }

                            size = (uint32_t)(Util::Align(offset + size, align) - offset);
                            ainfo->plus = size - ainfo->size;
                        }
                    }

                    linfo.size += size;
                    offset += size;
                }
            }

            int32_t align = linfo.align;

            if (align <= 0 || m_scoobyBeta)
            {
                align = m_defaultLayerAlign;
            }

            size_t alignedOffset = Util::Align(offset, align);

            linfo.plus = (uint32_t)(alignedOffset - offset);

            offset = alignedOffset;
        }

        return true;
    }

    bool File::WriteOffsets()
    {
        for (AssetInfo& ainfo : m_assetInfo)
        {
            //ainfo.offset += m_dpakDataStart;

            if (ainfo.size == 0 && m_writeAssetOffsetZeroIfSizeZero)
            {
                ainfo.offset = 0;
            }

            m_stream->Seek(ainfo.writeOffsetPos);

            if (m_stream->Write(&ainfo.offset) != sizeof(uint32_t))
            {
                return false;
            }
        }

        m_stream->Seek(m_maxLayerSizeWritePos);

        uint32_t maxLayerSize = 0;

        for (const LayerInfo& linfo : m_layerInfo)
        {
            if (linfo.size > maxLayerSize)
            {
                maxLayerSize = linfo.size;
            }
        }

        if (m_stream->Write(&maxLayerSize) != sizeof(uint32_t))
        {
            return false;
        }

        return true;
    }

    void File::DetectEntAssetsHavePad()
    {
        m_entAssetsHavePad = false;

        bool detected = false;
        std::vector<AssetInfo*> assetsToUnload;

        for (AssetInfo& ainfo : m_assetInfo)
        {
            bool isEnt = false;

            switch (ainfo.type)
            {
            case AssetType::BOUL:
            case AssetType::BUTN:
            case AssetType::DSTR:
            case AssetType::EGEN:
            case AssetType::HANG:
            case AssetType::NPC:
            case AssetType::PEND:
            case AssetType::PKUP:
            case AssetType::PLAT:
            case AssetType::PLYR:
            case AssetType::SIMP:
            case AssetType::TRIG:
            case AssetType::UI:
            case AssetType::UIFT:
            case AssetType::VIL:
                isEnt = true;
                break;
            }

            if (isEnt)
            {
                if (!ainfo.loaded)
                {
                    LoadAsset(ainfo);
                    assetsToUnload.push_back(&ainfo);
                }

                MemoryStream stream(ainfo.data, ainfo.size);
                stream.SetEndian(Util::GetPlatformEndian(m_platform));

                uint32_t id;

                stream.Seek(0x0C);
                stream.Read(&id);

                if (id != 0 && AssetIsType(id, AssetType::SURF))
                {
                    m_entAssetsHavePad = false;
                    detected = true;
                    break;
                }

                stream.Seek(0x10);
                stream.Read(&id);

                if (id != 0 && AssetIsType(id, AssetType::SURF))
                {
                    m_entAssetsHavePad = true;
                    detected = true;
                    break;
                }

                stream.Seek(0x48);
                stream.Read(&id);

                if (id != 0 && (AssetIsType(id, AssetType::MODL) || AssetIsType(id, AssetType::MINF)))
                {
                    m_entAssetsHavePad = false;
                    detected = true;
                    break;
                }

                stream.Seek(0x4C);
                stream.Read(&id);

                if (id != 0 && (AssetIsType(id, AssetType::MODL) || AssetIsType(id, AssetType::MINF)))
                {
                    m_entAssetsHavePad = true;
                    detected = true;
                    break;
                }

                if (id != 0 && (AssetIsType(id, AssetType::ALST) || AssetIsType(id, AssetType::ANIM)))
                {
                    m_entAssetsHavePad = false;
                    detected = true;
                    break;
                }

                stream.Seek(0x50);
                stream.Read(&id);

                if (id != 0 && (AssetIsType(id, AssetType::ALST) || AssetIsType(id, AssetType::ANIM)))
                {
                    m_entAssetsHavePad = true;
                    detected = true;
                    break;
                }
            }
        }

        for (AssetInfo* ainfo : assetsToUnload)
        {
            UnloadAsset(*ainfo);
        }

        if (!detected)
        {
            m_entAssetsHavePad = (m_game == Game::BattleForBikiniBottom);
        }
    }

}