#pragma once
#include "GameUpdate.h"
#include "Title.h"
#include "end.h"

enum Scene {
	TITLE,
	GAME,
	END
};
class GameLoop
{
public:
	GameLoop();
	~GameLoop();

	void Update(const char* keys, const char* preKeys);
	void Draw();


private:
	int scene;
	GameUpdate* game;
	Title* title;
	end* end_;

};

