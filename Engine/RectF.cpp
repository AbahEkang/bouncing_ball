#include "RectF.h"

RectF::RectF(float left, float right, float top, float bottom)
	:
	m_left(left),
	m_right(right),
	m_top(top),
	m_bottom(bottom)
{
}

RectF::RectF(const Vec2& topleft, const Vec2& bottomRight)
	:
	RectF(topleft.x, bottomRight.x, topleft.y, bottomRight.y)
{
}

RectF::RectF(const Vec2& topleft, float width, float height)
	:
	//bottom right is equal top left + width and height
	RectF(topleft, topleft + Vec2(width, height))
{
}

bool RectF::IsOverlappingWidth(const RectF& other) const
{
	return m_right > other.m_left && m_left < other.m_right
		&& m_bottom > other.m_top && m_top < other.m_bottom;
}
