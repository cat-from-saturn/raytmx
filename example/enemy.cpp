#include "enemy.h"

static Enemy monsterEnemy[enemy_amount] = { 0 };

void enemy::enemyInit(Vector2 playerPos)
{
	for (int i = 0; i < enemy_amount; i++)
	{
		monsterEnemy[i].rec.width = 40;
		monsterEnemy[i].rec.height = 40;
		monsterEnemy[i].active = true;
		monsterEnemy[i].color = RED;
		//monsterEnemy[i].texture = LoadTexture("");
		//monsterEnemy[i].speed = {};
		monsterEnemy[i].rec.x = 886;
		monsterEnemy[i].rec.y = 2936;
		monsterEnemy[i].position = { monsterEnemy[i].rec.x, monsterEnemy[i].rec.y };
	}

	

	
}

void enemy::EnemyMovement(Vector2& playerPos)
{
	float deltaMult = { 270 * GetFrameTime() };

	for (int i = 0; i < enemy_amount; i++)
	{
		if (monsterEnemy[i].active)
		{
			if (playerPos.x > monsterEnemy[i].rec.x)
			{
				monsterEnemy[i].rec.x += deltaMult;
			}
			
			else if (playerPos.x < monsterEnemy[i].rec.x)
			{
				monsterEnemy[i].rec.x -= deltaMult; 
			}

			if (playerPos.y > monsterEnemy[i].rec.y)
			{
				monsterEnemy[i].rec.y += deltaMult; 
			}

			else if (playerPos.y < monsterEnemy[i].rec.y)
			{
				monsterEnemy[i].rec.y -= deltaMult;
			}
		}
	}

	for (int i = 0; i < enemy_amount; i++)
	{
		if (monsterEnemy[i].active)
		{
			DrawRectangleRec(monsterEnemy[i].rec, monsterEnemy[i].color);
		}
	}
}

Rectangle enemy::rebuildCollisionsRec()
{
	for (int i = 0; i < enemy_amount; i++)
	{
		return
		{
			 monsterEnemy[i].rec.x, monsterEnemy[i].rec.y, 40, 40
		};
	}

}

void enemy::tryMove(float& coord, float delta, const TmxMap* map)
{
	coord += delta;
	Rectangle hitb = rebuildCollisionsRec();

	if (CheckCollisionTMXTileLayersRec(map, map->layers, map->layersLength, hitb, NULL)) coord -= delta;
}

void enemy::collisionDetect()
{
	for (int i = 0; i < enemy_amount; i++)
	{
		/*while (!WindowShouldClose())
		{

		}*/
		Vector2 prevPos = { monsterEnemy[i].position };
		float step = 270 * GetFrameTime();

		//tryMove(monsterEnemy[i].rec.x, step, map);
		//tryMove();
	}
	
}
