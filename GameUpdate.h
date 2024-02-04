#pragma once
#include "Player.h"
#include "Enemy.h"

class GameUpdate
{
public:
	GameUpdate();
	~GameUpdate();

	void Initialize();

	void Update(const char* keys);
	void Draw();

public:

	int GetFrag();

private:
	Player* player1;
	Enemy* enemy1;
	bool isClear_;
	bool isGameOver_;
	int texBG;
	int clearTex;
	int overTex;
	int barTex;
	
};

