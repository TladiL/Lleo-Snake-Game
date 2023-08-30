#include "Board.h"

namespace Sonar
{
	Board::Board(GameDataRef data) :_data(data)
	{
		_boardSprite.setTexture(_data->assets.GetTexture("Board"));
	}

	void Board::DrawCell(const Location& loc)
	{
		_boardSprite.setPosition(loc.x * dimension, loc.y * dimension);
		_data->window.draw(_boardSprite);
	}

	bool Board::IsInsideBoard(const Location& loc) const
	{
		return loc.x >= 0 && loc.x < 35
			&& loc.y >= 0 && loc.y < 35;
	}

	const sf::Sprite& Board::GetSprite() const
	{
		return _boardSprite;
	}
}