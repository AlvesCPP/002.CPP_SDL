#include "cGame.h"

	//CONSTRUCTORS
/*
FUNCTION: Default constructor of a game instance setting basic variables.
INPUTS: /
OUTPUTS: Setting of the background color and calling for the Init function.
*/
cGame::cGame()
{
	SDL_Color bcgColor = { 0, 0, 0, 255 };

	m_gameState = Init("Default game", SCREEN_W, SCREEN_H, bcgColor);
}

/*
FUNCTION: Game instance constructor with specific parameters.
INPUTS: String title of the game window, int screen width, int screen height.
OUTPUTS: Setting of the background default color, and calling for the Init function with passed parameters.
*/
cGame::cGame(std::string title, int screenW, int screenH)
{
	SDL_Color bcgColor = { 0, 0, 0, 255 };

	m_gameState = Init(title, screenW, screenH, bcgColor);
}

/*
FUNCTION: Game instance constructor with additional parameters.
INPUTS: String title of the game window, int screen width, int screen height, SDL_Color background color.
OUTPUTS: Setting of the background default color, and calling for the Init function with passed parameters.
*/
cGame::cGame(std::string title, int screenW, int screenH, SDL_Color bcgColor)
{
	m_gameState = Init(title, screenW, screenH, bcgColor);
}

//DESTRUCTORS
/*
FUNCTION: Game instance destructor, freeing the allocated memory of member variables.
INPUTS: /
OUTPUTS: Frees SDL and game objects memory allocations.
*/
cGame::~cGame()
{
	if (m_pScreen != NULL)
		SDL_DestroyWindow(m_pScreen);
	if (m_pRenderer != NULL)
		SDL_DestroyRenderer(m_pRenderer);

	if (m_gameObjects != NULL)
		delete(m_gameObjects);

	SDL_Quit();
}

	//INITIALIZATION
/*
FUNCTION: Game instance SDL initializer.
INPUTS: String title of the game window, int screen width, int screen height, SDL_Color background color.
OUTPUTS: Initialization of SDL subsystem, creation of SDL screen window and renderer, setting of the screen background color.
*/
GameState cGame::Init(std::string title, int screenW, int screenH, SDL_Color bcgColor)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("[SDL Error] Failed to initialize SDL : ", SDL_GetError());
		return Corrupted;
	}
	m_bcgColor = bcgColor;

	m_pScreen = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenW, screenH, SDL_WINDOW_SHOWN);
	if (m_pScreen == NULL)
	{
		SDL_Log("[SDL Error] Failed to create the screen window : ", SDL_GetError());
		return Corrupted;
	}

	m_pRenderer = SDL_CreateRenderer(m_pScreen, -1, SDL_RENDERER_ACCELERATED);
	if (m_pRenderer == NULL)
	{
		SDL_Log("[SDL Error] Failed to create the renderer : ", SDL_GetError());
		return Corrupted;
	}

	mN_timeElapsed = 0;

	return Initialized;
}
	
	//RENDERING
/*
FUNCTION: Body function of the game screen rendering methods.
INPUTS: /
OUTPUTS: Calling GameObjects and SDL rendering function.
*/
void cGame::RenderScreen()
{
	RenderGameObjects();
	SDL_RenderPresent(m_pRenderer);
	SDL_SetRenderTarget(m_pRenderer, NULL);
}

/*
FUNCTION: GameObjects rendering method, copies each visual representation of a GameObject to the game renderer.
INPUTS: /
OUTPUTS: Enumerating each GameObjects and renders it considering his boolean flipped value.
*/
void cGame::RenderGameObjects()
{
	SDL_Rect newRect = { (int)m_gameObjects[0].GetPosition().GetX(),
							(int)m_gameObjects[0].GetPosition().GetY(),
							(int)m_gameObjects[0].GetScale().GetX() * 100,
							(int)m_gameObjects[0].GetScale().GetY() * 100
	};

	if (m_gameObjects[0].GetSprite()->IsFlipped())
	{
		SDL_RenderCopyEx(m_pRenderer, m_gameObjects[0].GetSprite()->GetCurrentSprite(), NULL, &newRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
	}
	else
	{
		SDL_RenderCopy(m_pRenderer, m_gameObjects[0].GetSprite()->GetCurrentSprite(), NULL, &newRect);
	}
}

/*
FUNCTION: Game instance screen clearer.
INPUTS: /
OUTPUTS: Calls SDL rendering functions to clear out the screen with the background color.
*/
void cGame::ClearScreen()
{
	SDL_SetRenderDrawColor(m_pRenderer, m_bcgColor.r, m_bcgColor.g, m_bcgColor.b, m_bcgColor.a);
	SDL_RenderClear(m_pRenderer);
}

	//INPUTS
/*
FUNCTION: Analyze the SDL_Event input returned by the SDL_PollEvent function and returns a specific enum input type of variable.
INPUTS: /
OUTPUTS: Returning of the specific enum input type value.
*/
InputEvent cGame::GetEvent()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				return right_key;
			case SDLK_LEFT:
				return left_key;
			default:
				break;
			}
		case SDL_QUIT:
			m_gameState = Exiting;
			return mouse_click;
		default:
			break;
		}
	}

	return none;
}

	//ACCESSORS
/*
FUNCTION: Accessor returning the current game state.
INPUTS: /
OUTPUTS: GameState.
*/
GameState cGame::GetGameState()
{
	return m_gameState;
}

/*
FUNCTION: Accessor returning the list of game objects.
INPUTS: /
OUTPUTS: cGameObject pointer.
*/
cGameObject * cGame::GetGameObjects()
{
	return m_gameObjects;
}

/*
FUNCTION: Accessor returning the game renderer associated.
INPUTS: /
OUTPUTS: SDL_Renderer pointer.
*/
SDL_Renderer* cGame::GetRenderer()
{
	return m_pRenderer;
}

/*
FUNCTION: Accessor returning the game screen reference.
INPUTS: /
OUTPUTS: SDL_Window pointer.
*/
SDL_Window* cGame::GetWindow()
{
	return m_pScreen;
}

/*
FUNCTION: Accessor returning the number of game objects created.
INPUTS: /
OUTPUTS: int nbGameObjects.
*/
int cGame::GetNbGameObjects()
{
	return mN_nbGameObjects;
}

	//GAME
/*
FUNCTION: Starting game with game objects creation.
INPUTS: int number of game objects.
OUTPUTS: Setting the gameObjects list and nbGameObjects, increments current game state, and calls out for GameLoop.
*/
void cGame::StartGame(int nbGameObjects)
{
	m_gameObjects = new cGameObject("Images/tile00", new cVect2D(SCREEN_W/2, SCREEN_H/2), new cVect2D((float)1, (float)1), m_pRenderer, true);
	mN_nbGameObjects = nbGameObjects;
	m_gameState = Running;

	RenderScreen();
	GameLoop();
}

/*
FUNCTION: Starting game with game objects creation.
INPUTS: GameObjects array, int nbGameObjects.
OUTPUTS: Setting the gameObjects list and nbGameObjects, increments current game state, and calls out for GameLoop.
*/
void cGame::StartGame(cGameObject* gameObjects, int nbGameObjects)
{
	m_gameObjects = gameObjects;
	mN_nbGameObjects = nbGameObjects;
	m_gameState = Running;
	RenderScreen();
}

/*
FUNCTION: Main game instance workflow, FPS rating, gameobject's sprite animation...
INPUTS: /
OUTPUTS: Setting gameObjects and game instance member variables.
*/
void cGame::GameLoop()
{
	int lastTime = 0, i = 0;

	while (m_gameState == Running)
	{
		mN_timeElapsed = SDL_GetTicks();

		if (mN_timeElapsed - lastTime > FPS)
			lastTime = mN_timeElapsed;
		else
			SDL_Delay(FPS - (mN_timeElapsed - lastTime));

		switch (GetEvent())//Handles user inputs and manipulates game objects in consequence.
		{
		case left_key://If left key is pressed, each game object that is input sensitive will move to the left.
			for (i = 0; i < GetNbGameObjects(); i++)
			{
				if (m_gameObjects[i].InputSensitive())
					m_gameObjects[i].SetSpeed(-DEFAULT_INPUT_VALUE);
			}
			break;
		case right_key://If right key is pressed, each game object that is input sensitive will move to the right.
			for (i = 0; i < GetNbGameObjects(); i++)
			{
				if (m_gameObjects[i].InputSensitive())
					m_gameObjects[i].SetSpeed(DEFAULT_INPUT_VALUE);
			}
			break;
		default://Otherwise if game objects speeds are not already equal to 0, it is set to 0.
			for (i = 0; i < GetNbGameObjects(); i++)
			{
				if (m_gameObjects[i].GetSpeed() != 0)
					m_gameObjects[i].SetSpeed(0);
			}
			break;
		}

		//Movement implementation
		for (i = 0; i < GetNbGameObjects(); i++)
		{
			if (m_gameObjects[i].GetSpeed() != 0)//if the game object is supposed to move
			{
				m_gameObjects[i].GetSprite()->NextSprite();//Its next image sprite is selected
				m_gameObjects[i].AddToX_Position(m_gameObjects[i].GetSpeed());//It is moving in the correct direction
				if (m_gameObjects[i].GetSpeed() > 0)//And flipped in consequence
					m_gameObjects[i].GetSprite()->Flip(true);
				else
					m_gameObjects[i].GetSprite()->Flip(false);
			}
		}
		//Rendering operations
		ClearScreen();
		RenderScreen();
	}
}
