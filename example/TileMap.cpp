#include "TileMap.h"

void TileMap::DrawMap(Camera2D* camera, int winWidth, int winHeight)
{
	
	DrawTMX(TMXmap, camera, 0, 0, WHITE);
	
}
