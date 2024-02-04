#include "end.h"
#include <Novice.h>

end::end()
{
	clearTex = Novice::LoadTexture("./images/congra.png");
}

end::~end()
{
}

void end::Draw()
{
	Novice::DrawSprite(0, 0, clearTex, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
