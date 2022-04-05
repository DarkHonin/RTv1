#ifndef RTV1_MESH_HPP
#define RTV1_MESH_HPP

#include "buffer.hpp"
#include <filesystem>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "shader.hpp"

namespace RTV1{
    namespace Types{
        class Mesh{
            public:
                GLuint VAO;

                GLO::VBO &vertecies;
                GLO::EBO &indecies;

                Mesh(GLO::VBO &verts, GLO::EBO &ind);

                void render(Shader &shader);
        };
    };

    namespace Loader {
        Types::Mesh & loadMesh(std::filesystem::path file);
    }
}

#endif
