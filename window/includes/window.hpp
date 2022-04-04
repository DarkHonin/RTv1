#ifndef RTV1_WINDOW_HPP
# define RTV1_WINDOW_HPP

#include <glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "input.hpp"

namespace RTV1{

    class Window {
        public:
            int width, height;
            bool fullscreen;
            GLFWwindow* window;
            
            Window(int width, int height, bool fullscreen);

            void open();
            void close();
            void update();

            bool shouldClose();

            GLFWwindow * operator*();

            ~Window();
        private: 
            bool glfw_init, glad_init;
            void init_glfw();
            void init_glad();
    };
};

#endif