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
//#include "Windows.h" //non-portable header, duh


AetherEngine::AetherEngine(){
    initflags = SDL_INIT_VIDEO; //init flags
    video_bpp = 32; //bpp
    videoflags = SDL_DOUBLEBUF; //| SDL_SWSURFACE;// | SDL_FULLSCREEN;
    if ( SDL_Init(initflags) < 0 ) { //init sdl
		fprintf(stderr, "Couldn't initialize SDL: %s\n",
                SDL_GetError());
		exit(1);
	}
    mainScreen=SDL_SetVideoMode(1024,768, video_bpp, videoflags); //init screen
    if (mainScreen == NULL) {
		fprintf(stderr, "Couldn't set 1024x768x%d video mode: %s\n",
                video_bpp, SDL_GetError());
		SDL_Quit();
		exit(2);
	}
	
    
    for(int i = 0; i < 322; i++){ //init keys
        KEYS[i] = false;
    }
    SDL_EnableKeyRepeat(0, 0);
}

//
//Methods ending in "Flip" flip the screen for you.
//Methods not ending in "Flip" will NOT flip the screen.
//Don't forget to flip the screen after calling a non flip method.
//

void AetherEngine::clearMainScreen(){
    SDL_FillRect(mainScreen,NULL, 0x000000);
}


void AetherEngine::loadLogo(std::string logoPath){
    SDL_Surface *temp = IMG_Load(logoPath.c_str());
    studioLogo = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    if (studioLogo == NULL){
        std::cout << "failed to load logo bitmap" << "\n";
    }else {
        //std::cout << "bitmap loaded successfully at address: " << studioLogo << "\n";
    }
}

void AetherEngine::drawLogoSequence(){
    clearMainScreen();
    if (studioLogo != NULL){
        //std::cout << "logo bitmap found at address: " << studioLogo << ", attempting to draw" << "\n";
        
        SDL_Rect dstRect;
        dstRect.x = 135;
        dstRect.y = 100;
        dstRect.w = studioLogo->w;
        dstRect.h = studioLogo->h;
        //SDL_BlitSurface(studioLogo, NULL, mainScreen, &dstRect);
        //SDL_Flip(mainScreen);
        clearMainScreen();
        SDL_Flip(mainScreen);
        clearMainScreen();
        SDL_Flip(mainScreen);
        keyboard();
        for(int i = 0; i < 255; i++){
            clearMainScreen();
            SDL_SetAlpha(studioLogo, SDL_SRCALPHA | SDL_RLEACCEL, i);
            SDL_BlitSurface(studioLogo, NULL, mainScreen, &dstRect);
            SDL_Flip(mainScreen);
            
        }
		SDL_Delay(1000); //Non-portable method, comes from Windows.h, won't work in mac
		for(int i = 0; i < 200; i++){
            clearMainScreen();
            SDL_SetAlpha(studioLogo, SDL_SRCALPHA | SDL_RLEACCEL, 255 - i);
            SDL_BlitSurface(studioLogo, NULL, mainScreen, &dstRect);
            SDL_Flip(mainScreen);
            
        } //this looponly goes to 200 for now, just to keep the logo move test workable.
		// change the limit to 255 to fade all the way out
        
        int moveLogo = 1;
        while(moveLogo){
            //SDL_Delay(20);
            //std::cout << mainScreen;
            //SDL_SetAlpha(studioLogo, SDL_SRCALPHA | SDL_RLEACCEL, i);
            keyboard();
			if (KEYS[SDLK_ESCAPE]){
				moveLogo = 0;
			}
            if (KEYS[SDLK_LEFT]){
                dstRect.x--;
            }
            if (KEYS[SDLK_RIGHT]){
                dstRect.x++;
            }
            if (KEYS[SDLK_UP]){
                dstRect.y--;
            }
            if (KEYS[SDLK_DOWN]){
                dstRect.y++;
            }
            clearMainScreen();
            SDL_BlitSurface(studioLogo, NULL, mainScreen, &dstRect);
            std::cout << SDL_Flip(mainScreen);
        }
		clearMainScreen();
		SDL_Flip(mainScreen);
        
        return;
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
void AetherEngine::keyboard() {
    // message processing loop
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // check for messages
        switch (event.type) {
                // exit if the window is closed
            case SDL_QUIT:
                //game_state = 0; // set game state to done,(do what you want here)
                SDL_Quit();
                break;
                // check for keypresses
            case SDL_KEYDOWN:
                KEYS[event.key.keysym.sym] = true;
                break;
            case SDL_KEYUP:
                KEYS[event.key.keysym.sym] = false;
                break;
            default:
                break;
        }
    } // end of message processing
}


