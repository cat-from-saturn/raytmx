#pragma once
#include "raylib.h"
#include "raymath.h"
#include <math.h>

class CatCharacter
{


private:

	//Texture2D map = LoadTexture("assets/testmap.png");
	//Vector2 mapPos = { 0.0, 0.0 };
	Texture2D darkOverlay = LoadTexture("assets/darkness.png");
	Vector2 overlayPos = { 0.0, 0.0 };

	int speed{ 3 };
	float winWidth{ 1600.0f };
	float winHeight{ 1200.0f };




public:
	void MovementInput(Vector2& direction);
	Vector2 PerTick(float deltaT, int winWidth, int winHeight);
	//void SetCamera(Rectangle descRec, int winWidth, int winHeight);
	Texture2D playerCat = LoadTexture("assets/WhiteCar.png");
	Vector2 charPosition{ winWidth / 2, winHeight / 2 };

	CatCharacter() {

	}

	~CatCharacter() {

	}
};

