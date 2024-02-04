#include "bullet.h"

Bullet::Bullet() {
	isAlive_ = false;
	damage_ = 0;
}

Bullet::~Bullet() {
}

void Bullet::Update() {

	if (isAlive_ == true) {
		pos_ = pos_ + velocity_;
	}
}

void Bullet::Draw() {
}