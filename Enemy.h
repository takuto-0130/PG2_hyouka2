#pragma once
#include "Object.h"
#include "EnemyBullet.h"
#include "Vector2Class.h"

static const int kEnemyBulletWay = 16;
static const int kEnemyBulletMax = 100;
static const int kRespawnTime = 90;
static const int kMoveTime = 540;

enum EnemyPhase {
	PHASE1,
	PHASE2,
	PHASE3
};


class Enemy : public Object
{
public:
	Enemy();
	~Enemy();

	void Initialize();

	void Update();
	void Draw();

	bool GetIsAlive() { return isAlive_; }
	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	float GetHP() { return HP_; }
	EnemyBullet& GetBullet(int itr) { return *bullet[itr][0]; }

	bool GetEliminate() {
		if (EnemyPhase_ == PHASE3 && isAlive_ == false) {
			return true;
		}
		else {
			return false;
		}
	}


	void SetHP(float hp);
	void SetPlayerPos(const Vector2& playerpos);

private:
	bool isAlive_;
	int bulletCollTime_ ;
	int bulletCollTimer_;
	EnemyBullet* bullet[kEnemyBulletMax][kEnemyBulletWay];
	int shotWay_;
	bool isShot_[kEnemyBulletMax];
	int EnemyPhase_;
	int RespawnTimer_;
	int moveTimer_;
	float HP_;
	Vector2 move_;
	Vector2 playerPos_;
	float playerAngle_;

};

