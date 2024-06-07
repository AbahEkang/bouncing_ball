#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Colors.h"

class Ball
{

public:
	Ball(const Vec2& pos, const Vec2& vel);
	void Draw(Graphics& gfx) const;
private:
	static constexpr float radius{ 7.0f };
	static constexpr Color color{ Colors::Red };
	Vec2 m_pos;
	Vec2 m_vel;
};

