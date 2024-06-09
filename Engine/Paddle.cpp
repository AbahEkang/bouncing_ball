#include "Paddle.h"

Paddle::Paddle(const Vec2& pos, float halfWidth, float halfHeight)
	:
	m_pos{pos},
	m_halfWidth{halfWidth},
	m_halfHeight{halfHeight}
{
}

void Paddle::Draw(Graphics& gfx) const
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingColor);

	rect.m_left += wingWidth;
	rect.m_right -= wingWidth;
	gfx.DrawRect(rect, color);
}

bool Paddle::DoBallCollision(Ball& ball) const
{
	if (ball.GetVelocity().y > 0.0f && GetRect().IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF& walls)
{
	const RectF rect = GetRect();
	if (rect.m_left < walls.m_left)
	{
		m_pos.x += walls.m_left - rect.m_left;
	}
	else if (rect.m_right > walls.m_right)
	{
		m_pos.x -= walls.m_right - walls.m_right;
	}
}

// Paddle only moves left and right
void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		m_pos.x -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		m_pos.x += speed * dt;
	}

}

RectF& Paddle::GetRect() const
{
	return RectF::FromCenter(m_pos, m_halfWidth, m_halfHeight);
}
