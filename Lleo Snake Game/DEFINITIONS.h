#pragma once

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700
#define dimension 20
#define MAXLOCATION 35

#define SPLASH_STATE_SHOW_TIME 3.0
#define GAME_OVER_STATE_SHOW_TIME 1.5

#define	SPLASH_SCENE_BACKGROUNG_FILEPATH "Resources/res/Splash Background.png"
#define	MAIN_MENU_BACKGROUNG_FILEPATH "Resources/res/grass.png"
#define	GAME_BACKGROUNG_FILEPATH "Resources/res/grassGame.jpg"
#define	GAME_OVER_BACKGROUNG_FILEPATH "Resources/res/grass.png"

#define	GAME_TITLE_FILEPATH "Resources/res/title.png"
#define	GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define	GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"

#define	PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

#define FOOD_FILEPATH "Resources/res/food.png"
#define	BOARD_FILEPATH "Resources/res/Tile.jpg"

#define BOARD_MOVEMENT_SPEED 1.0f

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};

#define FLASH_SPEED 1500.0f