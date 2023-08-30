#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"
#include <iostream>

namespace Sonar
{
	GameState::GameState(GameDataRef data) :_data(data), snek({2,2})
	{
	}

	void GameState::Init()
	{
						//Loading texture//
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUNG_FILEPATH);
		_data->assets.LoadTexture("Board", BOARD_FILEPATH);
		_data->assets.LoadTexture("Food", FOOD_FILEPATH);

						//Setting up the background//
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));

						//Initialize Snake//
		board = new Board(_data);
						//Initialize Food//
		food = new Food(_data);
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void GameState::Update(float dt)
	{
		if (!gameIsOver)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				delta_loc = { 0,-1 };
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				delta_loc = { 1,0 };
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				delta_loc = { 0,1 };
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				delta_loc = { -1,0 };
			}
			
			++snekMoveCounter;
			if (snekMoveCounter >= snekMovePeriod)
			{
				snekMoveCounter = 0;
				Location next = snek.GetNextHeadLocation(delta_loc);
				if (!board->IsInsideBoard(next) || snek.IsInTileExceptEnd(next))
				{
					gameIsOver = true;
					clock.restart();
				}
				else
				{
					bool eating = false;

					if (next.x == food->randomX && next.y == food->randomY)
					{
						eating = true;
					}
					
					if (eating == true)
					{
						food->RandomiseXY();
						snek.Grow();
						food->deleteFood();
					}

					snek.MoveBy(delta_loc);

					if (eating == true)
					{
						food->SpawnFood();
					}
				}

			}
		}
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		//Drawing The Snake//
		snek.Draw(*board);
		//Drawing The Food//
		food->DrawFood();
		
		//Game Over State//
		if (gameIsOver)
		{
			if (clock.getElapsedTime().asSeconds() > GAME_OVER_STATE_SHOW_TIME)
			{
				_data->machine.AddState(StateRef (new GameOverState(_data)), true);
			}
		}

		_data->window.display();

	}
}