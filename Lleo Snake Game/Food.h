#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "DEFINITIONS.h"
#include "Location.h"
#include <random>

#include <iostream>

namespace Sonar
{
	class Food
	{
	public:
		Food(GameDataRef data);

		//Call this to delete the foo
		//foodSprites.erase(foodSprites.begin() + 1);
		//
		void deleteFood();
		void SpawnFood();
		void DrawFood();
		void RandomiseXY();

		int randomY;// = 20;
		int randomX;// = 50;

		const sf::Sprite& GetSprite() const;

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> foodSprites;
	};
}