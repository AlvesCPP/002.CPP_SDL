#pragma once
#include <SDL.h>
#include <string>
#include "cGameObject.h"
#include "cVect2D.h"
#include <iostream>

/*
cGame class :

Is it an object containing all the methods needed to manage a Game framework such as : Inputs, GameObjects, and Renderer.
*/

//Public Enumeration defining the state of the current Game
typedef enum GameState
{
	Initialized, Running, Paused, Exiting, Corrupted, Other
}GameState;

//Public Enumeration defining the type of Input detected (More to add but less is currently needed)
typedef enum InputEvent
{
	right_key, left_key, mouse_click, none
}InputEvent;

class cGame
{
public:
	//CONSTS
	static const int SCREEN_W = 1280;//Default screen width.
	static const int SCREEN_H = 720;//Default screen height.
	static const int FPS = 30;//Default FPS.
	static const int DEFAULT_INPUT_VALUE = 4;//Default force value returned by an input.

	//Constructors
	cGame();//Default constructor.
	cGame(std::string title, int screenW, int screenH);//Constructor with specified parameters.
	cGame(std::string title, int screenW, int screenH, SDL_Color bcgColor);//Constructor with additional parameter : Background color.
	//Destructors
	virtual ~cGame();//Default constructor.

	//Initialization
	GameState Init(std::string title, int screenW, int screenH, SDL_Color bcgColor);//Initialization method called by each constructor. It is trying to initialize the game environment.
	//Rendering
	void RenderScreen();//Rendering body function of the screen.
	void RenderGameObjects();//Renders each game object.
	void ClearScreen();//Clears the screen with the background color.
	//Inputs
	InputEvent GetEvent();//Handles user inputs as events.
	//Accessors
	GameState GetGameState();//Returns the current game state.
	cGameObject* GetGameObjects();//Returns the GameObjects array.
	SDL_Renderer* GetRenderer();//Returns the renderer pointer.
	SDL_Window* GetWindow();//Returns the window pointer.
	int GetNbGameObjects();//Returns the number of GameObjects in this game.
	//Game
	void StartGame(int nbGameObjects);//GameObjects creation.
	void StartGame(cGameObject* gameObjects, int nbGameObjects);
	void GameLoop();//Handles the game environment flow.
protected:
private:
	GameState m_gameState;//Defines the current state of the game.
	cGameObject* m_gameObjects;//Contains each GameObject of the game.
	int mN_timeElapsed;//Defines the time elapsed since the game started in ms.
	int mN_nbGameObjects;//Defines the number of GameObjects in this game.

	SDL_Color m_bcgColor;//Defines the background color of this game.
	InputEvent m_lastEvent;//Defines the last input event.
	SDL_Window* m_pScreen;//References the screen window of this game.
	SDL_Renderer *m_pRenderer;//References the renderer object of this game.
};

