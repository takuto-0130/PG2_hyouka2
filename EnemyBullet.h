#pragma once
#include "Bullet.h"

class EnemyBullet : public Bullet
{
public:

	EnemyBullet();
	~EnemyBullet();
	void Initialize();
	void SetEnemyBulletPlayerLength(const Vector2& player);
	void Update() override;
	void Draw() override;


	bool GetIsAlive() { return isAlive_; }
	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	float GetDamage() { return damage_; }



	void SetAngle(const Vector2& angle);
	void SetAlive(const bool& isAlive);
	void SetPos(const Vector2& Pos);

protected:

	Vector2 enemyBulletToPlayer_;
	float enemyBulletToPlayerLen_;
	Vector2 angle_;

};

