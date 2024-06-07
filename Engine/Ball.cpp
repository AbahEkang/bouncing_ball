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

void Ball::Update(float dt)
{
	m_pos += m_vel * dt;
}

bool Ball::DoWallCollision(const RectF& walls)
{
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.m_left < walls.m_left)
	{
		m_pos.x += walls.m_left - rect.m_left;
		ReboundX();
		collided = true;
	}
	else if (rect.m_right > walls.m_right)
	{
		m_pos.x -= rect.m_right - walls.m_right;
		ReboundX();
		collided = true;
	}
	if (rect.m_top < walls.m_top)
	{
		m_pos.y += walls.m_top - rect.m_top;
		ReboundY();
		collided = true;
	}
	else if (rect.m_bottom > walls.m_bottom)
	{
		m_pos.y -= rect.m_bottom - walls.m_bottom;
		ReboundY();
		collided = true;
	}

	return collided;
}

void Ball::ReboundX()
{
	m_vel.x = -m_vel.x;
}

void Ball::ReboundY()
{
	m_vel.y = -m_vel.y;
}

RectF& Ball::GetRect() const
{
	return RectF::FromCenter(m_pos, radius, radius);
}
