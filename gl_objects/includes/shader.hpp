#ifndef RTV1_SHADER_HPP
#define RTV1_SHADER_HPP

#include <string>
#include "loader.hpp"

#include <glad.h>
#include <iostream>
namespace RTV1{

    enum ShaderIndex{
        vertex, fragment
    };

    class Shader{
        public: 
            GLuint shaders[2];
            GLuint program;
            const std::string name;
            Shader(std::string shaderName);
    };
};

#endif
