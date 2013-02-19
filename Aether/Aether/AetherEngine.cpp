//
//  AetherEngine.cpp
//  Aether
//
//  Created by William Slaughter on 2/18/13.
//  Copyright (c) 2013 Grimalkin Games. All rights reserved.

#include "AetherEngine.h"
#include "SDL.h"
#include "SDL_image.h"
#include "stdio.h"


AetherEngine::AetherEngine(SDL_Surface *screen){
    mainScreen = screen;
}

void AetherEngine::loadLogo(std::string logoPath){
    studioLogo = IMG_Load(logoPath.c_str());
    if (studioLogo == NULL){
        std::cout << "failed to load logo bitmap" << "\n";
    }else {
        std::cout << "bitmap loaded successfully at address: " << studioLogo << "\n";
    }
}

void AetherEngine::drawLogoSequence(){
    if (studioLogo != NULL){
        std::cout << "logo bitmap found at address: " << studioLogo << ", attempting to draw" << "\n";
        drawBitmap(studioLogo, 135, 100);
        
    }else {
        std::cout << "no logo has been loaded" << "\n";
        return;
    }
    
}

void AetherEngine::drawBitmap(SDL_Surface *bitmap, int x, int y){
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_BlitSurface(bitmap, NULL, this->mainScreen, &dest);
}
