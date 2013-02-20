//
//  AetherEngine.h
//  Aether
//
//  Created by William Slaughter on 2/18/13.
//  Copyright (c) 2013 Grimalkin Games. All rights reserved.
//

#define __Aether__AetherEngine__

#include <iostream>
#include "stdio.h"
#include "SDL.h"
#include "SDL_image.h"

class AetherEngine {
    SDL_Surface *mainScreen;
    SDL_Surface *studioLogo;
    Uint32 initflags; /* See documentation for details */
	Uint8  video_bpp;
	Uint32 videoflags;

    bool KEYS[322];
    //SDL_Surface *image;
    //SDL_Surface *readyImage;
    int blitResult;
public:
    AetherEngine(void);
    void drawBitmap(SDL_Surface *bitmap, int x, int y);
    void loadLogo(std::string logoPath);
    void drawLogoSequence();
    void clearMainScreen();
    void shutdown();
private:
    void keyboard();
    
};