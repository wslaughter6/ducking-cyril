
/* Simple program:  Create a blank window, wait for keypress, quit.

   Please see the SDL documentation for details on using the SDL API:
   /Developer/Documentation/SDL/docs.html
*/
   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "SDL.h"
#include "SDL_image.h"
#include "logo.h"
class logo;

int main(int argc, char *argv[])
{
	Uint32 initflags = SDL_INIT_VIDEO;  /* See documentation for details */
	SDL_Surface *screen;
    SDL_Surface *image;
    SDL_Surface *temp;
	Uint8  video_bpp = 16;
	Uint32 videoflags = SDL_DOUBLEBUF;// | SDL_FULLSCREEN;
	int done;
    int beginLogo;
    int endLogo;
    SDL_Event event;

	/* Initialize the SDL library */
	if ( SDL_Init(initflags) < 0 ) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",
			SDL_GetError());
		exit(1);
	}

	/* Set 640x480 video mode */
	screen=SDL_SetVideoMode(1024,768, video_bpp, videoflags);
        if (screen == NULL) {
		fprintf(stderr, "Couldn't set 1024x768x%d video mode: %s\n",
                        video_bpp, SDL_GetError());
		SDL_Quit();
		exit(2);
	}

	done = 0;
    beginLogo = 1;
    endLogo = 0;
    logo *logoScreen = new logo(screen);
	while ( !done ) {
        if(beginLogo){
            logoScreen->fadeIn();
            beginLogo = 0;
        }
        if(endLogo) {
            logoScreen->fadeOut();
            done = 1;
        }
        
        
        

		/* Check for events */
		while ( SDL_PollEvent(&event) ) {
			switch (event.type) {

				case SDL_MOUSEMOTION:
					break;
				case SDL_MOUSEBUTTONDOWN:
					break;
				case SDL_KEYDOWN:
					/* Any keypress quits the app... */
				case SDL_QUIT:
					done = 1;
					break;
				default:
					break;
			}
		}
	}
	
	/* Clean up the SDL library */
	SDL_Quit();
	return(0);
}
