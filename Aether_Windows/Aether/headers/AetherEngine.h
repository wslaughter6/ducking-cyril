//
//  AetherEngine.h
//  Aether
//
//  Created by William Slaughter on 2/18/13.
//  Copyright (c) 2013 Grimalkin Games. All rights reserved.
//
#include <iostream>
#include "stdio.h"
#include "SDL.h"
#include "SDL_image.h"

class AetherEngine {
    SDL_Surface *mainScreen;
    //SDL_Surface *image;
    //SDL_Surface *readyImage;
    int blitResult;
public:
    AetherEngine(SDL_Surface *srcScreen);
    ~AetherEngine(void);
    void fadeIn();
    void fadeOut();
};