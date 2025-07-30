#include "render.h"
#include <iostream>

using namespace std;

Renderer::Renderer(int screenWidth, int screenHeight)
    : window(nullptr), renderer(nullptr), width(screenWidth), height(screenHeight) {}

Renderer::~Renderer() {
    quit();
}

bool Renderer::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        cerr << "SDL_image could not initialize! IMG_Error: " << IMG_GetError() << endl;
        return false;
    }

    window = SDL_CreateWindow("Scrabble",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_SHOWN);

    if (!window) {
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

void Renderer::renderBackground(const string& backgroundPath) {
    SDL_Surface* surface = IMG_Load(backgroundPath.c_str());
    if (!surface) {
        cerr << "Unable to load image " << backgroundPath << "! IMG_Error: " << IMG_GetError() << endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        cerr << "Unable to create texture from " << backgroundPath << "! SDL_Error: " << SDL_GetError() << endl;
        return;
    }

    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);
}

void Renderer::clear() {
    SDL_RenderClear(renderer);
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}

void Renderer::quit() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

SDL_Renderer* Renderer::getSDLRenderer() {
    return renderer;
}
