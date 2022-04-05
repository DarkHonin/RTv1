#include "shader.hpp"

bool shaderStatus(GLuint shader){
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success) {
        std::cout << infoLog << std::endl;
        return false;
    }
    return true;
}

bool programStatus(GLuint program){
    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
        return false;
    }
    return true;
}

GLuint createShader(std::string name, GLuint type){
    std::filesystem::path root = "assets/shaders/" + name;
    std::cout << "Absolute path for shader '" << name << "':" << std::filesystem::absolute(root) << std::endl;

    std::filesystem::path shader_source_path = root;

    switch(type){
        case GL_VERTEX_SHADER:
            shader_source_path.append("vertex.glsl");
            break;
        case GL_FRAGMENT_SHADER:
            shader_source_path.append("fragment.glsl");
            break;
        default:
            return -1;
    }


    const std::string & shader_source = RTV1::Loader::readFileRaw(std::filesystem::absolute(shader_source_path));
    GLuint shader = glCreateShader(type);
    const char * ss = shader_source.c_str();
    glShaderSource(shader, 1, &ss, NULL);

    glCompileShader(shader);
    if(!shaderStatus(shader)) return 0;

    delete &shader_source;
    std::cout << "Shader compiled: " << shader_source_path << std::endl;
    return shader;
}


namespace RTV1{
    Shader::Shader(std::string name) : name(name){
        this->shaders[ShaderIndex::vertex] = createShader(name, GL_VERTEX_SHADER);
        this->shaders[ShaderIndex::fragment] = createShader(name, GL_FRAGMENT_SHADER);

        this->program = glCreateProgram();
        for(int i = 0; i < sizeof(this->shaders); i ++)
            if(this->shaders[i] > 0)
                glAttachShader(this->program, this->shaders[i]);
        
        glLinkProgram(this->program);
        programStatus(this->program);
    }
}