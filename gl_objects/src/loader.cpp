#include "loader.hpp"

namespace RTV1{
    namespace Util{
        std::filesystem::path getExecRoot(){
            return std::filesystem::absolute(".");
        }
    }

    namespace Loader{
        const std::string & readFileRaw(std::filesystem::path path){
            if(!std::filesystem::exists(path)){
                std::cout << "Could not open file: " << path << "\n\t Does not exist" << std::endl;
                return "";
            }
            std::ifstream file(path);
            file.seekg(0, file.end);
            int length = file.tellg();
            file.seekg(0, file.beg);

            char * buffer = new char [ length];

            file.read(buffer, length);

            std::string & ret = *new std::string(buffer);
            delete[] buffer;
            return ret;
        }
    }
}