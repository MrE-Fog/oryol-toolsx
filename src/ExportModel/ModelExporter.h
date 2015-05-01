#pragma once
//------------------------------------------------------------------------------
/**
    @class OryolTools::ModelExporter
    @brief export 3D models to Oryol file format using assimp
*/
#include <string>
#include "assimp/Importer.hpp"
#include "ExportUtil/Vertex.h"
#include "ExportUtil/VertexBuffer.h"
#include "ExportUtil/IndexBuffer.h"

namespace OryolTools {

class ModelExporter {
public:
    /// set aiProcess scene processing flags
    void SetAiProcessFlags(unsigned int flags);
    /// set component removal flags (PP_RVC_FLAGS)
    void SetAiProcessRemoveComponentsFlags(unsigned int flags);
    /// set primitive type removal flags (PP_SBP_REMOVE)
    void SetAiProcessSortByPTypeRemoveFlags(unsigned int flags);
    /// set requested index size (must be 2 or 4 for 16-bit or 32-bit indices, default: 2)
    void SetIndexSize(int size);
    /// set vertex layout description
    void SetVertexLayout(const VertexLayout& layout);
    /// import data
    bool Import(const std::string& path);
    /// export converted import data
    bool Export(const std::string& path);
    /// get pointer to imported scene
    const aiScene* GetScene() const;

private:
    /// convert vertex data into embedded VertexBuffer object
    bool exportVertices();
    /// convert index data into embedded IndexBuffer object
    bool exportIndices();

    Assimp::Importer importer;
    const aiScene* scene = nullptr;
    unsigned int aiProcessFlags = 0;
    unsigned int aiProcessRemoveComponentsFlags = 0;
    unsigned int aiProcessSortByPTypeRemoveFlags = 0;
    int indexSize = 2;
    VertexLayout requestedVertexLayout;
    VertexBuffer vertexBuffer;
    IndexBuffer indexBuffer;
};

} // namespace OryolTools

