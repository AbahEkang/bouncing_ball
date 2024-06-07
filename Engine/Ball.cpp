#include "Ball.h"
#include "SpriteCodex.h"


Ball::Ball(const Vec2& pos, const Vec2& vel)
	:
	m_pos{pos},
	m_vel{vel}
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(m_pos, gfx);
}
