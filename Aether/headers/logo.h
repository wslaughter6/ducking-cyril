//
//  logo.h
//  Aether
//
//  Created by William Slaughter on 2/17/13.
//  Copyright (c) 2013 Grimalkin Games. All rights reserved.
//

#ifndef __Aether__logo__
#define __Aether__logo__

#include <iostream>
#include "stdio.h"
#include "SDL.h"
#include "SDL_image.h"

class logo {
    SDL_Surface *screen;
    SDL_Surface *image;
    SDL_Surface *readyImage;
    int blitResult;
public:
    logo(SDL_Surface *srcScreen);
    ~logo(void);
    void fadeIn();
    void fadeOut();
};

#endif /* defined(__Aether__logo__) */
