#ifndef RTV1_LOADER_HPP
#define RTV1_LOADER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

namespace RTV1{

    namespace Utils{
        std::filesystem::path getExecRoot();
    };

    namespace Loader{
        const char *readFileRaw(std::filesystem::path path);

    };

};

#endif