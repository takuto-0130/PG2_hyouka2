#include "Vector2Class.h"
#include <math.h>
#define USE_MATH_DEFINES

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(const float& inputX, const float& inputY) {
	x = inputX;
	y = inputY;
}

Vector2::Vector2(const Vector2& input) {
	x = input.x;
	y = input.y;
}

Vector2::~Vector2() {
}

Vector2 Vector2::Normalize() {
	float denominator = sqrtf(x * x + y * y);
	Vector2 result = { 0,0 };
	if (denominator != 0) {
		result = { sqrtf(x * x) / denominator, sqrtf(y * y) / denominator };
	}
	return result;
}

float Vector2::Length(const Vector2& a) {
	return sqrtf((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
}