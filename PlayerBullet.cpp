#include "PlayerBullet.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

PlayerBullet::PlayerBullet() {

	pos_ = { 0,0 };
	radius_ = 8.0f;
	velocity_ = { 0,0 };
	speed_ = { 12,12 };
	texture_ = Novice::LoadTexture("white1x1.png");
	isAlive_ = false;
	damage_ = 1;
	PLDir_ = { 0,-1 };
}

PlayerBullet::~PlayerBullet() {
}

void PlayerBullet::Initialize() {

	pos_ = { 0,0 };
	velocity_ = { 0,0 };
	isAlive_ = false;
	damage_ = 1;
	PLDir_ = { 0,-1 };
}

void PlayerBullet::SetAlive(const bool& isAlive) {
	isAlive_ = isAlive;
}

void PlayerBullet::SetPos(const Vector2& PLPos) {
	pos_ = PLPos;
}

void PlayerBullet::SetPLDir(const Vector2& PLDir) {
	PLDir_ = PLDir;
}

void PlayerBullet::Update() {

	if (pos_.x < 0 - radius_ || pos_.x > 1280 + radius_ || pos_.y < 0 - radius_ || pos_.y > 720 + radius_) {
		isAlive_ = false;
	}

	if (isAlive_ == true) {
		velocity_ = speed_ * PLDir_;
		pos_ = pos_ + velocity_;
	}
}

void PlayerBullet::Draw() {

	if (isAlive_ == true) {
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, 0x4444FFFF, kFillModeSolid);
	}
}