#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "GameOverState.h"

namespace Sonar
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Clock clock;

		Board* board;
		Food* food;

		Snake snek;

		Location delta_loc = { 1,0 };
		static constexpr int snekMovePeriod = 5;
		int snekMoveCounter = 0;
		bool gameIsOver = false;
	};
}