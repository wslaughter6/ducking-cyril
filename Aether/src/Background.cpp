//
//  Background.cpp
//  Aether
//
//  Created by William Slaughter on 23.02.13.
//  Copyright (c) 2013 Grimalkin Games. All rights reserved.
//

#include "AetherLevel.h"


Background::Background(){
    backgroundBitmap = NULL;
}

SDL_Surface *Background::getBGSurface(){
    return backgroundBitmap;
}

int Background::setBG(SDL_Surface *bg){
    if (backgroundBitmap != NULL){
        freeBG();
    }
    backgroundBitmap = SDL_DisplayFormat(bg);
    SDL_FreeSurface(bg);
    return 0;
}

int Background::freeBG(){
    if(backgroundBitmap == NULL){
        return 0;
    }else{
        SDL_FreeSurface(backgroundBitmap);
        return 0;
    }
}

bool Background::isEmpty(){
    if (backgroundBitmap == NULL){
        return true;
    }else return false;
}