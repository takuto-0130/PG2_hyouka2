#pragma once
#include "Bullet.h"
class PlayerBullet : public Bullet
{
public:

	PlayerBullet();
	~PlayerBullet() override;
	void Initialize();
	void SetAlive(const bool &isAlive);
	void SetPos(const Vector2& PLPos);
	void SetPLDir(const Vector2& PLDir);
	void Update() override;
	void Draw() override;


	bool GetIsAlive() { return isAlive_; }
	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	float GetDamage() { return damage_; }

private:
	Vector2 PLDir_;

};

