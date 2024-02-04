#pragma once
#include "Object.h"

class Bullet : public Object
{
public:

	Bullet();
	virtual ~Bullet();
	virtual void Update();
	virtual void Draw();

protected:

	bool isAlive_;
	float damage_;

};

