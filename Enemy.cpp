#include "Enemy.h"

Enemy::Enemy() {
	pos_ = { 640,80 };
	radius_ = 20;
	velocity_ = { 0,0 };
	speed_ = { 0,0 };
	texture_ = Novice::LoadTexture("white1x1.png");
	isAlive_ = true;
	bulletCollTime_ = 22;
	bulletCollTimer_ = 0;
	shotWay_ = 8;
	for (auto& i : isShot_) {
		i = false;
	}
	for (auto& i : bullet) {
		for (auto& j : i) {
			j = new EnemyBullet();
		}
	}
	EnemyPhase_ = PHASE1;
	HP_ = 20.0f;
	moveTimer_ = 0;
	RespawnTimer_ = kRespawnTime;
	move_ = { 2,0 };
	playerPos_ = { 0,0 };
	playerAngle_= { 0 };
}

Enemy::~Enemy() {
	for (auto& i : bullet) {
		for (auto& j : i) {
			delete j;
		}
	}
}

void Enemy::Initialize() {

	pos_ = { 640,80 };
	isAlive_ = true;
	bulletCollTimer_ = 0;
	for (auto& i : bullet) {
		for (auto& j : i) {
			j->Initialize();
		}
	}
	EnemyPhase_ = PHASE1;
	moveTimer_ = 0;
	RespawnTimer_ = kRespawnTime;
	move_ = { 2,0 };
	playerPos_ = { 0,0 };
	playerAngle_ = { 0 };
	HP_ = 20;
}

void Enemy::Update() {

	if (isAlive_) {
		pos_ += move_;
		if (pos_.x < 400 || pos_.x > 880) {
			move_.x *= -1;
		}
		if (pos_.y < 50 || pos_.y > 120) {
			move_.y *= -1;
		}
		playerPos_ -= pos_;
		playerAngle_ = { sqrtf(playerPos_.x * playerPos_.x + playerPos_.y * playerPos_.y) };

	}

	bulletCollTimer_--;
	switch (EnemyPhase_) {
	case PHASE1:

		if (isAlive_) {
			if (bulletCollTimer_ <= 0) {
				for (int i = 0; i < kEnemyBulletMax; i++) {
					if (bullet[i][0]->GetIsAlive() == false) {
						bullet[i][0]->SetPos(pos_);
						bullet[i][0]->SetAlive(true);
						bulletCollTimer_ = bulletCollTime_;
						break;
					}
				}

			}
		}
		if (HP_ <= 0) {
			isAlive_ = false;
		}
		if (isAlive_ == false) {
			RespawnTimer_--;
		}
		if (RespawnTimer_ <= 0) {
			isAlive_ = true;
			RespawnTimer_ = kRespawnTime;
			EnemyPhase_ = PHASE2;
			HP_ = 20;
		}
		break;

	case PHASE2:



		if (isAlive_) {
			if (bulletCollTimer_ <= 0) {
				for (int i = 0; i < kEnemyBulletMax; i++) {
					if (bullet[i][0]->GetIsAlive() == false) {
						bullet[i][0]->SetPos(pos_);
						bullet[i][0]->SetAngle({ playerPos_.x / playerAngle_, playerPos_.y / playerAngle_ });
						bullet[i][0]->SetAlive(true);
						bulletCollTimer_ = bulletCollTime_;
						break;
					}
				}

			}
		}


		if (HP_ <= 0) {
			isAlive_ = false;
		}
		if (isAlive_ == false) {
			RespawnTimer_--;
		}
		if (RespawnTimer_ <= 0) {
			isAlive_ = true;
			RespawnTimer_ = kRespawnTime;
			EnemyPhase_ = PHASE3;
			HP_ = 20;
			move_ = { 2,2 };
		}
		break;

	case PHASE3:


		if (isAlive_) {
			if (bulletCollTimer_ <= 0) {
				for (int i = 0; i < kEnemyBulletMax; i++) {
					if (bullet[i][0]->GetIsAlive() == false) {
						bullet[i][0]->SetPos(pos_);
						bullet[i][0]->SetAngle({ playerPos_.x / playerAngle_, playerPos_.y / playerAngle_ });
						bullet[i][0]->SetAlive(true);
						bulletCollTimer_ = bulletCollTime_;
						break;
					}
				}

			}
		}

		if (HP_ <= 0) {
			isAlive_ = false;
		}
		break;

	default:

		break;

	}
	for (auto& i : bullet) {
		for (auto& j : i) {
			j->Update();
		}
	}
}

void Enemy::Draw() {

	if(isAlive_) {
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, 0x44FF44FF, kFillModeSolid);
	}
	for (auto& i : bullet) {
		for (auto& j : i) {
			j->Draw();
		}
	}
}


void Enemy::SetHP(float hp) {
	HP_ = hp;
}

void Enemy::SetPlayerPos(const Vector2& playerpos) {
	playerPos_ = playerpos;
}
