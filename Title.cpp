#include "Title.h"
#include <Novice.h>

Title::Title()
{
	texBG = Novice::LoadTexture("./images/BGyozora.png");
	texStart = Novice::LoadTexture("./images/gamestart.png");
}

Title::~Title()
{
}

void Title::Update()
{
}

void Title::Draw()
{
	for (int i = 0; i < 2; i++) {
		Novice::DrawSprite(675 * i, 0, texBG, 2.25f, 2.25f, 0.0f, 0xFFFFFFFF);
	}
	Novice::DrawSprite(0, 0, texStart, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
