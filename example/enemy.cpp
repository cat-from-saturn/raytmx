#include "enemy.h"
#include "CatCharacter.h"
static Enemy monsterEnemy[enemy_amount] = { 0};

void enemy::enemyInit(Vector2 playerPos, float dT)
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
	}

	

	
}

void enemy::EnemyMovement(Vector2& playerPos)
{
	for (int i = 0; i < enemy_amount; i++)
	{
		if (monsterEnemy[i].active)
		{
			while (playerPos.x > monsterEnemy[i].rec.x)
			{
				monsterEnemy[i].rec.x += 1.f;
			}

			while (playerPos.x < monsterEnemy[i].rec.x)
			{
				monsterEnemy[i].rec.x -= 1.f ;
			}

			while (playerPos.y > monsterEnemy[i].rec.y)
			{
				monsterEnemy[i].rec.y += 1.f ;
			}

			while (playerPos.y < monsterEnemy[i].rec.y)
			{
				monsterEnemy[i].rec.y -= 1.f ;
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
