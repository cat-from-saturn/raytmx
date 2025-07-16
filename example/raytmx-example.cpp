#define HOXML_IMPLEMENTATION
#define RAYTMX_IMPLEMENTATION

#include "raylib.h"
#include "raymath.h"
#include "CatCharacter.h"
#include "TileMap.h"



int main()
{
	int winWidth = 1600;
	int winHeight = 1200;
	InitWindow(winWidth, winHeight, "forgotten halls");

	Vector2 origin{ winWidth / 2, winHeight / 2 };
	Vector2 camTarget{ 0, 0 };

	Camera2D Camera{};
	Camera.offset = origin;
	Camera.target = camTarget;
	Camera.rotation = 0.0f;
	Camera.zoom = 1.0f;

	CatCharacter survivor{};
	TileMap halls{};

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		BeginMode2D(Camera);
		ClearBackground(BLACK);

		halls.DrawMap(&Camera, winWidth, winHeight);
		survivor.PerTick(GetFrameTime(), winWidth, winHeight);

		Camera.target = { survivor.charPosition.x, survivor.charPosition.y };

		EndDrawing();
	}
	EndMode2D();
	UnloadTexture(survivor.playerCat);
	CloseWindow();

}