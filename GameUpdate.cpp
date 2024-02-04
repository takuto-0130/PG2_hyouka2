#include "GameUpdate.h"



GameUpdate::GameUpdate() {

	player1 = new Player();
	enemy1 = new Enemy();
	isClear_ = false;
	isGameOver_ = false;
	texBG = Novice::LoadTexture("./images/BGyozora.png");
	clearTex = Novice::LoadTexture("./images/gameclear.png");
	overTex = Novice::LoadTexture("./images/gameover.png");
	barTex = Novice::LoadTexture("./images/setumei.png");
}

GameUpdate::~GameUpdate() {

	delete player1;
	delete enemy1;
}

void GameUpdate::Initialize() {
	player1->Initialize();
	enemy1->Initialize();
	isClear_ = false;
	isGameOver_ = false;
}

void GameUpdate::Update(const char* keys) {

	if(isClear_ == false && isGameOver_ == false) {

		player1->Update(keys);
		enemy1->SetPlayerPos(player1->GetPos());
		enemy1->Update();

		if (enemy1->GetIsAlive()) {
			for (int i = 0; i < kPlayerBulletMax; i++) {
				PlayerBullet& PLBullet = player1->GetBullet(i);
				float bulletEnemyLength = PLBullet.GetPos().Length(enemy1->GetPos());
				if (bulletEnemyLength < enemy1->GetRadius() + PLBullet.GetRadius() && PLBullet.GetIsAlive()) {
					enemy1->SetHP(enemy1->GetHP() - PLBullet.GetDamage());
					PLBullet.SetAlive(false);
				}
			}
			float playerEnemyLen = player1->GetPos().Length(enemy1->GetPos());
			if (playerEnemyLen < enemy1->GetRadius() + player1->GetRadius() && player1->GetIsAlive()) {
				player1->SetHP(player1->GetHP() - 1.0f);
			}
		}
		if (player1->GetIsAlive()) {
			for (int i = 0; i < kEnemyBulletMax; i++) {
				EnemyBullet& ENBullet = enemy1->GetBullet(i);
				float bulletEnemyLength = ENBullet.GetPos().Length(player1->GetPos());
				if (bulletEnemyLength < player1->GetRadius() + ENBullet.GetRadius() && ENBullet.GetIsAlive()) {
					player1->SetHP(player1->GetHP() - ENBullet.GetDamage());
					ENBullet.SetAlive(false);
				}
			}
		}
	}

	if (enemy1->GetEliminate()) {
		isClear_ = true;
	}

	if (player1->GetHP() <= 0) {
		isGameOver_ = true;
	}
}

void GameUpdate::Draw() {
	for (int i = 0; i < 2; i++) {
		Novice::DrawSprite(675 * i, 0, texBG, 2.25f, 2.25f, 0.0f, 0xFFFFFFFF);
	}
	enemy1->Draw();
	player1->Draw();
	Novice::ScreenPrintf(0, 0, "enemyHP%.02f", enemy1->GetHP());
	Novice::ScreenPrintf(0, 20, "playerHP%.02f", player1->GetHP());

	if (isClear_ == true || isGameOver_ == true) {

		Novice::DrawSprite(0, 0, barTex, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
		if (isGameOver_ == true) {
			Novice::DrawSprite(0, 0, overTex, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
		}

		if (isClear_ == true) {
			Novice::DrawSprite(0, 0, clearTex, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
		}
	}
}

int GameUpdate::GetFrag() {
	if (isClear_ == true) {
		return 1;
	}
	else if (isGameOver_ == true) {
		return 2;
	}
	else {
		return 0;
	}
}
