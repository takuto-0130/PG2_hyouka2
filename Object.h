#pragma once
#include "Vector2Class.h"
#include "Vec2Functions.h"
#include <Novice.h>

class Object {

protected:

	Vector2 pos_;
	float radius_ = 0;
	Vector2 velocity_;
	Vector2 speed_;
	int texture_ = 0;

};
