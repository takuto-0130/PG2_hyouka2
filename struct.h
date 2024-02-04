#pragma once
#include "Vector2.h"

struct EnemyBullet {
	bool isShot;
	Vector2 pos;
	float radius;
	Vector2 velocity;
	Vector2 speed;
	float damage;
	int intervalTimer;
	float enemyToPlayerA;
	float enemyToPlayerB;
	float enemyToPlayerC;
	int texture;
};

struct BulletAngle {
	float angleDenomi;
	float theta;
	float angleChange;
	float angle;
	float reverseAngle;
};

static const int bulletWayMax = 16;
static const int bulletMax = 200;

struct Enemy {
	bool isAlive;
	Vector2 pos;
	float radius;
	int hp;
	int respawnTimer;
	int texture;
};

struct PlayerBullet {
	bool isShot;
	Vector2 pos;
	float radius;
	Vector2 velocity;
	Vector2 speed;
	float damage;
	int intervalTimer;
	int texture;
};