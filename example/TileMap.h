#pragma once
#include "raylib.h"
#include "hoxml.h"
#include "raytmx.h"

class TileMap
{

private:
	const char* tmx =  "assets/thehalls.tmx";


public:

	void DrawMap(Camera2D* camera, int winWidth, int winHeight);

	bool CollisionCheck();

	TmxMap* TMXmap = LoadTMX(tmx);

	TileMap() {

	}

	~TileMap() {
		
	}
};

