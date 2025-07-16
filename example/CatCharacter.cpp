#include "CatCharacter.h"

void CatCharacter::MovementInput(Vector2& direction)
{
	if (IsKeyDown(KEY_A)) direction.x += 1.0f;
	if (IsKeyDown(KEY_D)) direction.x -= 1.0f;
	if (IsKeyDown(KEY_W)) direction.y += 1.0f;
	if (IsKeyDown(KEY_S)) direction.y -= 1.0f;
}

Vector2 CatCharacter::PerTick(float deltaT, int winWidth, int winHeight)
{
	Vector2 direction{};
	MovementInput(direction);

	//DrawTextureEx(map, mapPos, 0.0, 2.0, WHITE);
	DrawTextureEx(darkOverlay, overlayPos, 0.0, 2.0, WHITE);

	//Vector2 mousePos = GetMousePosition();
	//float charRotation = atan2f(mousePos.y - charPosition.y, mousePos.x - charPosition.x) * RAD2DEG;

	if (Vector2Length(direction) != 0.0)
	{
		// set mapPos = mapPos - direction
		charPosition = Vector2Subtract(charPosition, Vector2Scale(Vector2Normalize(direction), speed));
	}

	// Source rectangle (part of the texture to use for drawing)
	Rectangle sourceRec = { 0.0f, 0.0f, (float)playerCat.width, (float)playerCat.height };

	// Destination rectangle (screen rectangle where drawing part of texture)
	Rectangle destRec = { charPosition.x, charPosition.y, playerCat.width * 2.0f, playerCat.height * 2.0f };

	// Origin of the texture (rotation/scale point), it's relative to destination rectangle size
	Vector2 origin = { (float)playerCat.width, (float)playerCat.height };

	DrawTexturePro(playerCat, sourceRec, destRec, origin, 0.0, WHITE);

	return charPosition;


}