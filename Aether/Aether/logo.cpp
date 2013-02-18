//
//  logo.cpp
//  Aether
//
//  Created by William Slaughter on 2/17/13.
//  Copyright (c) 2013 Grimalkin Games. All rights reserved.
//
#include "stdio.h"
#include "logo.h"
#include "SDL.h"
#include "SDL_image.h"

std::string filename = "/Users/will/logo.png";
logo::logo(SDL_Surface *srcScreen){
    screen = srcScreen;
    image = IMG_Load(filename.c_str());
    std::cout << "imgage load: " << image;
}

void logo::fadeIn(){
    readyImage = SDL_DisplayFormat(image);
    SDL_FreeSurface(image);
    SDL_Rect dstRect;
    dstRect.x = 135;
    dstRect.y = 100;
    dstRect.w = image->w;
    dstRect.h = image->h;
    blitResult = SDL_BlitSurface(readyImage, NULL, screen, &dstRect);
    //SDL_Upper
    SDL_Flip(screen);
    
    
    
}

void logo::fadeOut(){
    
}
