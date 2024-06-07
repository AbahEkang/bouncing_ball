#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect, Color color);
	void Draw(Graphics& gfx) const;
private:
	RectF m_rectangle;
	Color m_color;
	bool destroyed{ false };
};

