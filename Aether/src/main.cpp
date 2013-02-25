
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
    int done;
    int finished;
    SDL_Event event;
	
    //initialize Aether Engine
    AetherEngine engine = *new AetherEngine();
    engine.loadLogo("/Users/will/logo.png");
    
    engine.drawLogoSequence();
    engine.loadLevel(1, "/Users/will/ducking-cyril/Aether/resources/level1.xml");
    engine.levelExplorer();
    finished = 0;
    done = 0;
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
