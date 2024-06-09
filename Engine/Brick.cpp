#include "Brick.h"

Brick::Brick(const RectF& rect, Color color)
	:
	m_rectangle{rect},
	m_color{color}
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(m_rectangle.GetExpanded(-padding), m_color);

	}
}

bool Brick::DoBallCollision(Ball& ball)
{

	if (!destroyed && m_rectangle.IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}

	return false;
}
