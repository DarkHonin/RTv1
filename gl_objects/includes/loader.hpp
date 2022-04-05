#ifndef RTV1_LOADER_HPP
#define RTV1_LOADER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

namespace RTV1{

    namespace Util{
        std::filesystem::path getExecRoot();
    };

    namespace Loader{
        const std::string &readFileRaw(std::filesystem::path path);

    };

};

#endif