#include "TileMap.h"

void TileMap::DrawMap(Camera2D* camera, int winWidth, int winHeight)
{
	
	DrawTMX(TMXmap, camera, winWidth / 2, winHeight / 2, WHITE);
	//void DrawTMXLayers(const TmxMap * map, const Camera2D * camera, const TmxLayer * layers, uint32_t layersLength, int posX, int posY, Color tint);
}
