#include "Food.h"

namespace Sonar
{
	Food::Food(GameDataRef data) : _data(data)
	{
		randomX = 20;
		randomY = 15;
		SpawnFood();
	}

	void Food::deleteFood()
	{
		for (unsigned short int i = 0; i < foodSprites.size(); i++)
		{
			foodSprites.erase(foodSprites.begin() + i);
		}
	}

	void Food::SpawnFood()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Food"));
		sprite.setPosition(randomX * dimension,randomY * dimension);
		foodSprites.push_back(sprite);
	}

	void Food::DrawFood()
	{
		for (unsigned short int i = 0; i < foodSprites.size(); i++)
		{
			_data->window.draw(foodSprites.at(i));
		}
	}

	void Food::RandomiseXY()
	{
		randomX = rand() % ( MAXLOCATION );
		randomY = rand() % ( MAXLOCATION );
	}

	const sf::Sprite& Food::GetSprite() const
	{
		return foodSprites.at(0);
	}
}