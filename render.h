#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;

class Renderer {
public:
    Renderer(int screenWidth, int screenHeight);
    ~Renderer();

    bool init();
    void renderBackground(const string& backgroundPath);
    void present();
    void clear();
    void quit();

    SDL_Renderer* getSDLRenderer();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
};


#endif // RENDER_H_INCLUDED
