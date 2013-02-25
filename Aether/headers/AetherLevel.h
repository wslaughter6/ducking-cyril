//
//  AetherLevel.h
//  Aether
//
//  Created by William Slaughter on 23.02.13.
//  Copyright (c) 2013 Grimalkin Games. All rights reserved.
//

#ifndef __Aether__AetherLevel__
#define __Aether__AetherLevel__

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SDL.h"
#include "SDL_Image.h"
#include "pugiconfig.hpp"
#include "pugixml.hpp"



#endif /* defined(__Aether__AetherLevel__) */


class Background {
    SDL_Surface *backgroundBitmap;
public:
    Background();
    int setBG(SDL_Surface *bg);
    int freeBG();
    bool isEmpty();
    SDL_Surface *getBGSurface();
    
};

class Platform {
    SDL_Surface *texture;
public:
    Platform();
};

class AetherLevel {
    Background backgrounds[2];
    Platform platforms[50];
    std::string levelName;
    int xdim;
    int ydim;
    int currentx;
    int currenty;
    SDL_Rect srcScreenRect;
    SDL_Rect dstScreenRect;
    SDL_Surface *currentScreen;
public:
    AetherLevel();
    int loadLevel(std::string filePath);
    int setBackground(int bgNum, std::string path);
    SDL_Surface *pollLevel();
    int getCurrentX();
    int getCurrentY();
    int setCurrentX(int curX);
    int setCurrentY(int curY);
};