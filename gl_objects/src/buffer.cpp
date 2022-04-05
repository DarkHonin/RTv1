#include "buffer.hpp"

#include <iostream>

namespace RTV1{
    namespace GLO{

        EBO::EBO() : Buffer<GLuint, GL_ELEMENT_ARRAY_BUFFER>(){}
        VBO::VBO() : Buffer<Types::Vertex, GL_ARRAY_BUFFER>(){}

        void EBO::configure(){}
        void VBO::configure(){
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Types::Vertex), (void*)0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Types::Vertex), (void*) (offsetof(Types::Vertex, normal)));
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Types::Vertex), (void*) (offsetof(Types::Vertex, tex)));

            glEnableVertexAttribArray(0);
            glEnableVertexAttribArray(1);
            glEnableVertexAttribArray(2);
            std::cout << "VBO configured" << std::endl;
        }
    }
}