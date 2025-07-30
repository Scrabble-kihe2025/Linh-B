#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Renderer {
public:
    Renderer(int screenWidth, int screenHeight);
    ~Renderer();

    bool init();
    void clear();
    void present();
    void quit();

    void renderBackground(const std::string& imagePath);

private:
    int screenWidth;
    int screenHeight;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif
