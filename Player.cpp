#include "Player.h"

Player::Player() {
	pos_ = { 640,600 };
	radius_ = 16;
	velocity_ = { 0,0 };
	speed_ = { 6,6 };
	texture_ = Novice::LoadTexture("./images/Player.png");
	isAlive_ = true;
	moveDirection_ = { 0,0 };
	playerDirection_ = { 0,-1 };
	isShot_ = false;
	bulletCollTimer_ = 0;
	rectNum_ = 0;
	for (auto &i : bullet) {
		i = new PlayerBullet();
	}
	HP_ = 100;
}

Player::~Player() {
	for (auto& i : bullet) {
		delete i;
	}
}

void Player::Initialize() {

	pos_ = { 640,600 };
	radius_ = 16;
	velocity_ = { 0,0 };
	speed_ = { 6,6 };
	isAlive_ = true;
	moveDirection_ = { 0,0 };
	playerDirection_ = { 0,-1 };
	isShot_ = false;
	bulletCollTimer_ = 0;
	rectNum_ = 0;
	for (auto& i : bullet) {
		i->Initialize();
	}
	HP_ = 100;
}

void Player::Update(const char* keys/*, const char* preKeys*/) {
	moveDirection_ = { 0,0 };
	if (isAlive_) {
		if (bulletCollTimer_ > 0) {
			bulletCollTimer_--;
		}

		if (keys[DIK_W]) {
			moveDirection_.y--;
		}
		if (keys[DIK_A]) {
			moveDirection_.x--;
		}
		if (keys[DIK_S]) {
			moveDirection_.y++;
		}
		if (keys[DIK_D]) {
			moveDirection_.x++;
		}

		if (keys[DIK_LEFT]) {
			rectNum_ = 1;
			playerDirection_ = { -1,0 };
		}
		if (keys[DIK_DOWN]) {
			rectNum_ = 2;
			playerDirection_ = { 0,1 };
		}
		if (keys[DIK_RIGHT]) {
			rectNum_ = 3;
			playerDirection_ = { 1,0 };
		}
		if (keys[DIK_UP]) {
			rectNum_ = 0;
			playerDirection_ = { 0,-1 };
		}
		for (auto& i : bullet) {
			if (i->GetIsAlive() == false) {
				i->SetPLDir(playerDirection_);
			}
		}

		velocity_ = moveDirection_.Normalize();
		velocity_ = (moveDirection_ * speed_) * velocity_;
		pos_ += velocity_;
		

		if (keys[DIK_SPACE]) {
			for (auto& i : bullet) {
				if (i->GetIsAlive() == false && bulletCollTimer_ <= 0) {
					i->SetAlive(true);
					i->SetPos(pos_);
					bulletCollTimer_ = kPlayerBulletCoolTime;
					break;
				}
			}
		}

		for (auto& i : bullet) {
			i->Update();
		}
	}
}

void Player::Draw() {
	Novice::DrawSpriteRect(int(pos_.x - 16), int(pos_.y - 16), 64 * rectNum_, 0, 64, 64, texture_, 0.125f, 0.5f, 0.0f, 0xFFFFFFFF);
	for (auto& i : bullet) {
		i->Draw();
	}
}

void Player::SetHP(float hp) {
	HP_ = hp;
}
