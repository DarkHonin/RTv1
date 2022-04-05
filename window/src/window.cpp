#include "window.hpp"

void catchGLFWError(int num, const char* message){
            std::cout << "GLFW Error has occured: " << num << std::endl << message << std::endl;
        }

void glfwFrameBufferCallback(GLFWwindow *window, int w, int h){
    glViewport(0,0, w, h);
}

namespace RTV1{

    Window::Window(int w, int h, bool f) : width(w), height(h), fullscreen(f), glfw_init(false), glad_init(false){
        
    }

    void Window::init_glfw(){
        std::cout<< "Init glfw started..." << std::endl;
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        glfwSetErrorCallback(&catchGLFWError);
        

        this->glfw_init = true;
        std::cout << "GLFW init complete" << std::endl;
    }

    void Window::init_glad(){
        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
                std::cout << "Failed to init GLAD" << std::endl;
                this->glad_init = false;
            }
        glEnable(GL_DEPTH_TEST);
        this->glad_init = true;
    }

    void Window::open(){
        this->init_glfw();
        if(this->fullscreen)
            this->window = glfwCreateWindow(this->width, this->height, "Generic OpenGL window", glfwGetPrimaryMonitor(), NULL);
        else
            this->window = glfwCreateWindow(this->width, this->height, "Generic OpenGL window", NULL, NULL);
        glfwMakeContextCurrent(this->window);

        if(!this->window){
            std::cout << "Failed to open window" << std::endl;
            return;
        }


        this->init_glad();

        glfwSetFramebufferSizeCallback(this->window, &glfwFrameBufferCallback);
    }

    void Window::close(){
        glfwDestroyWindow(this->window);
        glfwTerminate();
    }

    Window::~Window(){
        this->close();
    }

    bool Window::shouldClose(){
        return glfwWindowShouldClose(this->window);
    }

    void Window::update(){
        Input::processInput(this->window);

        // Clear

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);

        // Render

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }

    GLFWwindow * Window::operator*(){
        return this->window;
    }

}