#pragma once
#include "raylib.h"
#include "raymath.h"
#include <math.h>
#include "raytmx.h"

class CatCharacter
{


private:

	//Texture2D map = LoadTexture("assets/testmap.png");
	//Vector2 mapPos = { 0.0, 0.0 };
	Texture2D darkOverlay = LoadTexture("assets/darkness.png");
	Vector2 overlayPos = { 0.0, 0.0 };

	int speed{ 300 };
	float winWidth{ 1600.0f };
	float winHeight{ 1200.0f };




public:
	void MovementInput(Vector2& direction);
	Vector2 PerTick(float deltaT, int winWidth, int winHeight, const TmxMap* map);
	Rectangle RebuildCollisionRec();
	void TryMove(float& coord, float delta, const TmxMap* map);
	//void SetCamera(Rectangle descRec, int winWidth, int winHeight);
	Texture2D playerCat = LoadTexture("assets/WhiteCar.png");
	Vector2 charPosition{ winWidth / 2 - 70, winHeight / 2 + 50 };

	Rectangle destRec{};
	Rectangle sourceRec{};
	Rectangle collisionRec{};


	CatCharacter() {

	}

	~CatCharacter() {

	}
};

