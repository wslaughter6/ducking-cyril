//
//  AetherLevel.cpp
//  Aether
//
//  Created by William Slaughter on 23.02.13.
//  Copyright (c) 2013 Grimalkin Games. All rights reserved.
//

#include "AetherLevel.h"

AetherLevel::AetherLevel(){
    
    srcScreenRect.x = currentx;
    srcScreenRect.y = currenty;
    srcScreenRect.w = 1024;
    srcScreenRect.h = 768;
    
    dstScreenRect.x = 0;
    dstScreenRect.y = 0;
    dstScreenRect.w = 1024;
    dstScreenRect.h = 768;
    currentScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, 1024, 768, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
    

    xdim = 0;
    ydim = 0;
    for(int i = 0; i < 50; i++){
        platforms[i] = *new Platform();
    }
    
     backgrounds[0] = *new Background();
    backgrounds[1] = *new Background();
}


//
//
//Accessor Methods
//----------------
//
//

int AetherLevel::getCurrentX(){
    if(currentx){
        return currentx;
    }else return -1;
}
int AetherLevel::getCurrentY(){
    if(currenty){
        return currenty;
    }else return -1;
}
int AetherLevel::setCurrentX(int curX){
    return currentx = curX;
}
int AetherLevel::setCurrentY(int curY){
    return currenty = curY;
}

//
//
//End Accessor Methods
//--------------------
//
//


int AetherLevel::setBackground(int bgNum, std::string path){
    SDL_Surface *bg = IMG_Load(path.c_str());
    backgrounds[bgNum].setBG(bg);
    return 0;
}

int AetherLevel::loadLevel(std::string filePath){
    //load level file
    //
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.c_str());
    std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << std::endl;
    pugi::xml_node level = doc.child("level");
    
    
    //load level attributes
    //
    levelName = level.attribute("name").value();
    xdim = level.attribute("xdim").as_int();
    ydim = level.attribute("ydim").as_int();
    currentx = level.attribute("startingpointx").as_int();
    currenty = level.attribute("startingpointy").as_int();
    
    //load backgrounds
    //
    int i = 0;
    for (pugi::xml_node XMLbackgrounds = level.child("backgrounds").first_child(); XMLbackgrounds; XMLbackgrounds = XMLbackgrounds.next_sibling()){
        std::cout << "bgpng: " << XMLbackgrounds.attribute("bgpng").value() << "\n";
        std::cout << "transCol: " << XMLbackgrounds.attribute("transCol").value() << "\n";
        setBackground(i,XMLbackgrounds.attribute("bgpng").value());
        
    }
    
    pugi::xml_node foreground = level.child("foreground");
    
    for (pugi::xml_node XMLplatforms = foreground.child("platforms").first_child(); XMLplatforms; XMLplatforms = XMLplatforms.next_sibling()){
        std::cout << "x: " << XMLplatforms.attribute("x").value() << "\n";
        std::cout << "y: " << XMLplatforms.attribute("y").value() << "\n";
        std::cout << "platpng: " << XMLplatforms.attribute("platpng").value() << "\n";
        
    }
    
    for (pugi::xml_node XMLobjects = foreground.child("objects").first_child(); XMLobjects; XMLobjects = XMLobjects.next_sibling()){
        std::cout << "objpng: " << XMLobjects.attribute("objpng").value() << "\n";
        std::cout << "ismovable: " << XMLobjects.attribute("ismovable").value() << "\n";
        
    }
    
    for (pugi::xml_node XMLenemyspawns = foreground.child("enemyspawns").first_child(); XMLenemyspawns; XMLenemyspawns = XMLenemyspawns.next_sibling()){
        std::cout << "enemy type: " << XMLenemyspawns.attribute("enemytype").value() << "\n";
        std::cout << "x: " << XMLenemyspawns.attribute("x").value() << "\n";
        std::cout << "y: " << XMLenemyspawns.attribute("y").value() << "\n";
    }
        
    return 0;
    
}

SDL_Surface *AetherLevel::pollLevel(){
    srcScreenRect.x = currentx;
    srcScreenRect.y = currenty;
    //SDL_Surface *background0 = backgrounds[0]->getBGSurface();
    SDL_BlitSurface(backgrounds[0].getBGSurface(),&srcScreenRect,currentScreen, &dstScreenRect);
    return currentScreen;
}


