#define HOXML_IMPLEMENTATION
#define RAYTMX_IMPLEMENTATION

#include "raylib.h"
#include "raymath.h"
#include "CatCharacter.h"
#include "TileMap.h"
#include "enemy.h"



int main()
{
	int winWidth = 1600;
	int winHeight = 1200;
	InitWindow(winWidth, winHeight, "forgotten halls");

	CatCharacter survivor{}; 
	TileMap halls{};
	enemy hostile{};
	hostile.enemyInit(survivor.charPosition);
	Vector2 origin{ winWidth/2,winHeight/2 };
	Vector2 camTarget{ 0, 0 };

	Camera2D Camera{};
	Camera.offset = origin;
	Camera.target = camTarget;
	Camera.rotation = 0.0f;
	Camera.zoom = 1.5f;

	const TmxMap* map = halls.TMXmap;
    
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		BeginMode2D(Camera);
		ClearBackground(BLACK);

		halls.DrawMap(&Camera, winWidth, winHeight);
		survivor.PerTick(GetFrameTime(), winWidth, winHeight, map);
		DrawRectangleRec(survivor.RebuildCollisionRec(), RED);
		Camera.target = { survivor.charPosition.x + survivor.playerCat.width/2, survivor.charPosition.y + survivor.playerCat.height/2};

		
		hostile.EnemyMovement(survivor.charPosition);

		EndDrawing();
	}
	EndMode2D();
	UnloadTexture(survivor.playerCat);
	UnloadTMX(halls.TMXmap);
	CloseWindow();

}