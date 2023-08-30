#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"
#include "Location.h"

namespace Sonar
{
	class Board
	{
	public:
		Board(GameDataRef data);

		void DrawCell(const Location& loc);
		bool IsInsideBoard(const Location& loc) const;

		const sf::Sprite& GetSprite() const;

	private:
		GameDataRef _data;

		sf::Sprite _boardSprite;
	};
}


