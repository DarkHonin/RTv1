#include "mesh.hpp"
#include <iostream>

namespace RTV1{
    namespace Types{
        Mesh::Mesh(GLO::VBO &verts, GLO::EBO &ind) : vertecies(verts), indecies(ind){
            glGenVertexArrays(1, &(this->VAO));
            glBindVertexArray(this->VAO);
            this->vertecies.bind();
            this->vertecies.allocate();

            this->indecies.bind();
            this->indecies.allocate();
        }

        void Mesh::render(Shader &shader){


            glBindVertexArray(this->VAO);
            glDrawElements(GL_TRIANGLES, this->indecies.length(), GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);
        }
    }

    namespace Loader{
        Types::Mesh & loadMesh(std::filesystem::path file){
            std::cout << "Reading mesh file: "<< std::filesystem::absolute(file) << std::endl;
            Assimp::Importer importer;

            const aiScene *scene = importer.ReadFile(file, aiProcess_Triangulate |
aiProcess_FlipUVs);

            GLO::VBO & verts = *new GLO::VBO();
            GLO::EBO & ind = *new GLO::EBO();

            aiMesh *mesh = scene->mMeshes[0];

            std::cout << "Mesh file read... loading" << std::endl;

            for(uint i = 0; i < mesh->mNumVertices; i++){
                aiVector3D vertex, normal;
                aiVector2D tex;

                vertex = mesh->mVertices[i];
                normal = mesh->mNormals[i];


                verts.push({
                    {
                        vertex.x,
                        vertex.y,
                        vertex.z
                    },
                    {
                        normal.x,
                        normal.y,
                        normal.z
                    },
                    
                });
            }
            std::cout << "Loaded vertecies" << std::endl;
            for(uint i = 0; i < mesh->mNumFaces; i++){
                aiFace &face = mesh->mFaces[i];
                for(uint m = 0; m < face.mNumIndices; m++){
                    ind.push(face.mIndices[m]);
                }
            }
            std::cout << "Loaded indecies" << std::endl;

            Types::Mesh &ret = *new Types::Mesh(verts, ind);

            return ret;
        }
    }
}