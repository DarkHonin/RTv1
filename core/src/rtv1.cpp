#include "rtv1.hpp"

#include "mesh.hpp"

int main(){
    RTV1::Window & window = *new RTV1::Window(800, 600, false);

    window.open();

    RTV1::Shader shader("default");

    RTV1::Types::Mesh &m = RTV1::Loader::loadMesh(std::filesystem::path("./assets/meshes/cube.obj"));



    while(!window.shouldClose()) {
        m.render(shader);
        window.update();
    }
}