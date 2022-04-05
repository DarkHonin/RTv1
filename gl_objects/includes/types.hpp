#ifndef RTV1_TYPES_HPP
#define RTV1_TYPES_HPP

#include <glm/glm.hpp>

namespace RTV1{
    namespace Types{
        struct Vertex{
            glm::vec3 pos;
            glm::vec3 normal;
            glm::vec2 tex;
        };

        struct Texture{
            GLuint id;
            std::string type;
            std::string path;
        };
    }
}

#endif