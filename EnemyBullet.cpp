#include "EnemyBullet.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

EnemyBullet::EnemyBullet() {

	pos_ = { 0,0 };
	radius_ = 10.0f;
	velocity_ = { 0,0 };
	speed_ = { 4,4 };
	texture_ = Novice::LoadTexture("white1x1.png");
	isAlive_ = false;
	damage_ = 1;
	enemyBulletToPlayer_ = { 0,0 };
	enemyBulletToPlayerLen_ = 0;
	angle_ = { 0,1 };
}

EnemyBullet::~EnemyBullet() {
}

void EnemyBullet::Initialize() {

	pos_ = { 0,0 };
	velocity_ = { 0,0 };
	isAlive_ = false;
	damage_ = 1;
	enemyBulletToPlayer_ = { 0,0 };
	enemyBulletToPlayerLen_ = 0;
	angle_ = { 0,1 };
}

void EnemyBullet::SetEnemyBulletPlayerLength(const Vector2& player) {

	enemyBulletToPlayer_.x = pos_.x - player.x;
	enemyBulletToPlayer_.y = pos_.y - player.y;
	enemyBulletToPlayerLen_ = sqrtf(
		enemyBulletToPlayer_.x * enemyBulletToPlayer_.x +
		enemyBulletToPlayer_.y * enemyBulletToPlayer_.y);
}

void EnemyBullet::Update() {

	if (pos_.x < 0 - radius_ || pos_.x > 1280 + radius_ || pos_.y < 0 - radius_ || pos_.y > 720 + radius_) {
		isAlive_ = false;
	}
	velocity_ = speed_ * angle_;
	if (isAlive_ == true) {
		pos_ = pos_ + velocity_;
	}
}

void EnemyBullet::Draw() {

	if (isAlive_ == true) {
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, 0xFF0000FF, kFillModeSolid);
	}
}


void EnemyBullet::SetAngle(const Vector2& angle) {
	angle_ = angle;
 }



void EnemyBullet::SetAlive(const bool& isAlive) {
	isAlive_ = isAlive;
}

void EnemyBullet::SetPos(const Vector2& Pos) {
	pos_ = Pos;
}