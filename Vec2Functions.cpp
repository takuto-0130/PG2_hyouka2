#include "Vec2Functions.h"

Vector2 Normalize(Vector2 v) {
	float denominator = sqrtf(v.x * v.x + v.y * v.y);
	Vector2 result = { 0,0 };
	if (denominator != 0) {
		result = { sqrtf(v.x * v.x) / denominator, sqrtf(v.y * v.y) / denominator };
	}
	return result;
}

float Distance(Vector2 v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

Vector2 Multiply(const Vector2& a, const Vector2& b) {
	Vector2 result;
	return result = { a.x * b.x, a.y * b.y };
}

Vector2 Multiply(const Vector2& a, const float& b) {
	Vector2 result;
	return result = { a.x * b, a.y * b };
}

Vector2 Multiply(const float& a, const Vector2& b) {
	Vector2 result;
	return result = { a * b.x, a * b.y };
}

Vector2 Add(const Vector2& a, const Vector2& b) {
	Vector2 result;
	return result = { a.x + b.x, a.y + b.y };
}