#include "rtv1.hpp"

int main(){
    RTV1::Window & window = *new RTV1::Window(800, 600, false);

    window.open();

    while(!window.shouldClose()) window.update();
}