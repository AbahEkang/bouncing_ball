/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball({ 200.f, 200.f }, { 300.f, 300.f }),
	walls(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav"),
	paddle(Vec2(500.0f, 500.f), 50.0f, 10.f)
{
	const Color colors[4] = { Colors::Red, Colors::Green, Colors::Blue, Colors::Cyan };

	Vec2 topLeft(0.0f, 0.0f);

	int index{ 0 };
	for (int i = 0; i < nBricksDown; i++)
	{
		const Color c = colors[i];
		for (int j = 0; j < nBricksAccross; j++)
		{
			
			bricks[index] = Brick(RectF(topLeft.x, topLeft.x + brickWidth, topLeft.y, topLeft.y + brickHeight), c);
			index++;
			topLeft.x += brickWidth;
			
			if (topLeft.x >= float(Graphics::ScreenWidth))
			{
				topLeft.x = float(Graphics::ScreenWidth - 1.0f) - brickWidth;
			}
			
		}
		topLeft.y += brickHeight;
		topLeft.x = 0.0f;
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	
	const float dt = ft.Mark();

	paddle.Update(wnd.kbd, dt);

	ball.Update(dt);

	paddle.DoWallCollision(walls);


	for (Brick& brick : bricks)
	{
		if (brick.DoBallCollision(ball))
		{
			soundBrick.Play();
			break;
		}
	}
	

	if (paddle.DoBallCollision(ball))
	{
		soundPad.Play();
	}

	if (ball.DoWallCollision(walls))
	{
		soundPad.Play();
	}

}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	paddle.Draw(gfx);
	int index{ 0 };

	for (const Brick& brick : bricks)
	{
		brick.Draw(gfx);
	}
	
}
