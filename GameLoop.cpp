#include "GameLoop.h"

GameLoop::GameLoop()
{
	scene = TITLE;
	game = new GameUpdate();
	title = new Title();
	end_ = new end();
}

GameLoop::~GameLoop()
{
	delete game;
	delete title;
	delete end_;
}

void GameLoop::Update(const char* keys, const char* preKeys)
{
	switch (scene) {

	case TITLE:
		title->Update();
		game->Initialize();
		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
			scene = GAME;
		}
		break;

	case GAME:
		game->Update(keys);
		if (game->GetFrag() == 1) {
			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
				scene = END;
			}
		}
		if (game->GetFrag() == 2) {
			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
				scene = TITLE;
			}
		}
		break;

	case END:
		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
			scene = TITLE;
		}
		break;
	}
}

void GameLoop::Draw()
{
	switch (scene) {

	case TITLE:
		title->Draw();
		break;

	case GAME:
		game->Draw();
		break;

	case END:
		end_->Draw();
		break;
	}
}
