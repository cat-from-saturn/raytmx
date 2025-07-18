#include "CatCharacter.h"
#include <iostream>

void CatCharacter::MovementInput(Vector2& direction)
{
	if (IsKeyDown(KEY_A)) direction.x += 1.0f;
	if (IsKeyDown(KEY_D)) direction.x -= 1.0f;
	if (IsKeyDown(KEY_W)) direction.y += 1.0f;
	if (IsKeyDown(KEY_S)) direction.y -= 1.0f;
}

Vector2 CatCharacter::PerTick(float deltaT, int winWidth, int winHeight, const TmxMap* map)
{
	Vector2 oldPos{charPosition};
	Vector2 direction{};
	MovementInput(direction);
	//d::cout << charPosition.x << "," << charPosition.y << std::endl;
	//DrawTextureEx(map, mapPos, 0.0, 2.0, WHITE);
	DrawTextureEx(darkOverlay, overlayPos, 0.0, 2.0, WHITE);

	//Vector2 mousePos = GetMousePosition();
	//float charRotation = atan2f(mousePos.y - charPosition.y, mousePos.x - charPosition.x) * RAD2DEG;

	if (Vector2Length(direction) != 0.0)
	{
		direction = Vector2Normalize(direction);
		float step = speed * deltaT;

		TryMove(charPosition.x, -direction.x * step, map);
		TryMove(charPosition.y, -direction.y * step, map);
	}
	
	// Source rectangle (part of the texture to use for drawing)
	 sourceRec = { 0.0f, 0.0f, (float)playerCat.width, (float)playerCat.height };

	// Destination rectangle (screen rectangle where drawing part of texture)
	destRec = { charPosition.x - playerCat.width, charPosition.y - playerCat.height, playerCat.width * 1.3f, playerCat.height * 1.3f };

	// Origin of the texture (rotation/scale point), it's relative to destination rectangle size
	Vector2 origin = { (float)playerCat.width, (float)playerCat.height };

	DrawTexturePro(playerCat, sourceRec, destRec, Vector2{0,0}, 0.0, WHITE);
	DrawRectangle(0, 0, playerCat.width, playerCat.height, RED);

	return charPosition;


}

Rectangle CatCharacter::RebuildCollisionRec()
{
	return
	{
		// charPosition.x-playerCat.width*0.57f, charPosition.y - playerCat.height*0.7f, (float)playerCat.width*0.5f, (float)playerCat.height*0.8f
	};
}

void CatCharacter::TryMove(float& coord, float delta, const TmxMap* map)
{
	coord += delta;
	Rectangle hb = RebuildCollisionRec();

	if (CheckCollisionTMXTileLayersRec(map, map->layers, map->layersLength, hb, NULL)) coord -= delta;
}