
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
#include "AetherEngine.h"


int main(int argc, char *argv[])
{
	Uint32 initflags = SDL_INIT_VIDEO;  /* See documentation for details */
	SDL_Surface *screen;
	Uint8  video_bpp = 16;
	Uint32 videoflags = SDL_DOUBLEBUF | SDL_SWSURFACE;// | SDL_FULLSCREEN;
	int done;
    int beginLogo;
    int endLogo;
    SDL_Event event;

	

	done = 0;
    //initialize Aether Engine
    AetherEngine *engine = new AetherEngine();
    engine->loadLogo("logo.png");
    engine->drawLogoSequence();
  
	while ( !done ) {
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
