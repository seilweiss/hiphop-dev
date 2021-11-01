#pragma once

#include "hiphop/core/asset_types.h"
#include "hiphop/core/util.h"

#include <cstdint>
#include <string>

namespace HipHop {

    class File;

    class Asset
    {
    public:
        enum Flags
        {
            SOURCE_FILE = 0x1,
            SOURCE_VIRTUAL = 0x2,
            READ_TRANSFORM = 0x4,
            WRITE_TRANSFORM = 0x8
        };

        explicit Asset() : m_file(nullptr), m_id(0) {}
        explicit Asset(uint32_t id) : m_file(nullptr), m_id(id) {}
        explicit Asset(const std::string& name) : m_file(nullptr), m_id(Util::Hash(name)) {}
        explicit Asset(File* file, uint32_t id) : m_file(file), m_id(id) {}
        explicit Asset(File* file, const std::string& name) : m_file(file), m_id(Util::Hash(name)) {}

        bool Exists() const;
        operator bool() const { return Exists(); }
        operator uint32_t() const { return m_id; }
        operator std::string() const { return GetName(); }

        File* GetFile() const { return m_file; }
        uint32_t GetID() const { return m_id; }
        bool SetID(uint32_t newID); // Will return false if an asset already exists with the given ID
        AssetType GetType() const;
        void SetType(AssetType type);
        uint32_t GetFlags() const;
        void SetFlags(uint32_t flags);
        int32_t GetAlign() const;
        void SetAlign(int32_t align);
        uint32_t GetChecksum() const;
        const void* GetData() const;
        uint32_t GetSize() const;
        void SetData(const void* data, uint32_t size = 0);
        bool IsLoaded() const;
        bool Load();
        bool Unload();
        std::string GetName() const;
        void SetName(const std::string& name, bool generateNewID = true);
        std::string GetFileName() const;
        void SetFileName(const std::string& filename);
        int GetIndex() const;

    private:
        File* m_file;
        uint32_t m_id;

        friend class File;
    };

}