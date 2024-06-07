#include "Brick.h"

Brick::Brick(const RectF& rect, Color color)
	:
	m_rectangle{rect},
	m_color{color}
{
}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(m_rectangle, m_color);
}
