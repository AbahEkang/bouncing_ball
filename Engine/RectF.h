#pragma once

#include "Vec2.h"
class RectF
{
public:
	RectF() = default;
	RectF(float left, float right, float top, float bottom);
	RectF(const Vec2& topleft, const Vec2& bottomRight);
	RectF(const Vec2& topleft, float width, float height);
	static RectF FromCenter(const Vec2& center, float halfWidth, float halfHeight);
	bool IsOverlappingWith(const RectF& other) const;
	RectF GetExpanded(float offset) const;
public:
	float m_left;
	float m_right;
	float m_top;
	float m_bottom;
};