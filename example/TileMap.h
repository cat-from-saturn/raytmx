#pragma once
#include "raylib.h"
#include "hoxml.h"
#include "raytmx.h"

class TileMap
{

private:
	const char* tmx =  "assets/thehalls.tmx" ;
	TmxMap* unreality;
	TmxMap* TMXmap = LoadTMX(tmx);


public:

	void DrawMap(Camera2D* camera, int winWidth, int winHeight);




	TileMap() {

	}

	~TileMap() {
		
	}
};

