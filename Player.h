#pragma once
#include "Object.h"
#include "PlayerBullet.h"

static const int kPlayerBulletMax = 30;
static const int kPlayerBulletCoolTime = 12;

class Player : public Object
{

public:

	Player();
	~Player();

	void Initialize();

	void Update(const char* keys/*, const char* preKeys*/);
	void Draw();

	PlayerBullet& GetBullet(int itr) { return *bullet[itr]; }
	float GetHP() { return HP_; }
	float GetRadius() { return radius_; }
	Vector2 GetPos() { return pos_; }
	bool GetIsAlive() { return isAlive_; }
	


	void SetHP(float hp);

private:

	bool isAlive_;
	Vector2 moveDirection_;
	Vector2 playerDirection_;
	bool isShot_;
	int bulletCollTimer_;
	int rectNum_;
	PlayerBullet* bullet[kPlayerBulletMax];
	float HP_;

};

