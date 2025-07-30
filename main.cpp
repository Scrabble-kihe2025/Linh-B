#include <iostream>
#include <SDL.h>
#include "renderer.h"
using namespace std;

const int SCREEN_WIDTH = 789;
const int SCREEN_HEIGHT = 789;

int main(int argc, char* argv[]) {
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!renderer.init()) {
        cerr << "Failed to initialize renderer.\n";
        return -1;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }

        renderer.clear();
        renderer.renderBackground("bg.jpg");
        renderer.present();

        SDL_Delay(16);
    }

    renderer.quit();
    return 0;
}
