#pragma once
#include "raylib.h"
#include "raytmx.h"

class enemy
{
private:



public:

	void enemyInit(Vector2 playerPos);

	void EnemyMovement(Vector2& playerPos);

	void collisionDetect();

	void tryMove(float& coord, float delta, const TmxMap* map);

	Rectangle rebuildCollisionsRec();

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
	Vector2 position;
} Enemy;
