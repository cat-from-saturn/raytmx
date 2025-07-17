#pragma once
#include "raylib.h"

class enemy
{
private:



public:

	void enemyInit(Vector2 playerPos, float dT);

	void EnemyMovement(Vector2& playerPos);


	enemy()
	{

	}

	~enemy()
	{

	}
};

#define enemy_amount 1

typedef struct monster
{
	Rectangle rec;
	bool active;
	Color color;
	Texture2D texture;
	int speed;
	Vector2 position;
} Enemy;
