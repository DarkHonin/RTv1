#include "rtv1.hpp"



int main(){
    RTV1::Window & window = *new RTV1::Window(800, 600, false);

    window.open();

    RTV1::Shader shader("default");

    while(!window.shouldClose()) window.update();
}