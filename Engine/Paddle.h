#pragma once

#include "Colors.h"
#include "Vec2.h"
#include "Ball.h"
#include "Graphics.h"
#include "Keyboard.h"


class Paddle
{
public:
	Paddle(const Vec2& pos, float halfWidth, float halfHeight);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF& GetRect() const;
private:
	static constexpr float wingWidth{ 10.0f };
	Color wingColor{ Colors::Red };
	Color color{ Colors::White };
	float speed{ 400.0f };
	float m_halfWidth;
	float m_halfHeight;
	Vec2 m_pos;
};

