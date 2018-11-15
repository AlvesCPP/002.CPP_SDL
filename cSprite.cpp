#include "cSprite.h"

	//CONSTRUCTORS
/*
FUNCTION: Constructor with no parameter.
INPUTS: /
OUTPUTS: Sets the m_images pointer to NULL and calls the Initialization function.
*/
cSprite::cSprite()
{
	m_images = NULL;
	Initialization();
}

/*
FUNCTION: Constructor with SDL_Texture* array parameter.
INPUTS: SDL_Texture pointer array (all the tiles necessary for the sprite).
OUTPUTS: Sets the m_images pointer to address already allocated in parameter, and calls the Initialization function.
*/
cSprite::cSprite(SDL_Texture** img)
{
	m_images = img;
	Initialization();
}

/*
FUNCTION: Constructor with the base image path, and the renderer pointer.
INPUTS: Image path needed to load all the images, and the renderer pointer to link the SDL_Texture pointers to.
OUTPUTS: Loads as many images in m_images as possible considering imgPath, links m_images cells to the renderer and calls the Initialization function.
*/
cSprite::cSprite(std::string imgPath, SDL_Renderer* renderer)
{
	int i = 0;
	SDL_Surface* newSurf;

	m_imgPath = imgPath;
	//Trying to as many images as possible in the images folder
	while ((newSurf = IMG_Load((m_imgPath + std::to_string(i) + ".png").c_str())) != NULL)
	{
		m_images = (SDL_Texture**)realloc(m_images, sizeof(SDL_Texture**) * (i + 1));
		m_images[i] = SDL_CreateTextureFromSurface(renderer, newSurf);
		i++;
	}
	if (i > 0)//Informs of the loading state in the console.
	{
		std::cout << i << " images successfully loaded." << std::endl;
	}else
	{
		std::cout << "No image found." << std::endl;
	}
	//Adding one more cell in the array to calculate the size of it.
	m_images = (SDL_Texture**)realloc(m_images, sizeof(SDL_Texture**) * (i + 1));
	m_images[i + 1] = NULL;

	Initialization();
}

	//DESTRUCTORS
/*
FUNCTION: Destructor with no parameter.
INPUTS: /
OUTPUTS: Deallocates (if any memory has been allocated) the memory of m_images.
*/
cSprite::~cSprite()
{
	int i = 0;

	if (m_images != NULL)//If any memory has been allocated to m_images it is being freed.
	{
		for (i = 0; i < GetNbImages() ; i++)
		{
			SDL_DestroyTexture(m_images[i]);
		}
	}
}

	//ACCESSORS
/*
FUNCTION: Accessor returning the number of SDL_Texture in m_images.
INPUTS: Image path needed to load all the images, and the renderer pointer to link the SDL_Texture pointers to.
OUTPUTS: Loads as many images in m_images as possible considering imgPath, links m_images cells to the renderer and calls the Initialization function.
*/
SDL_Texture** cSprite::GetIMG()
{
	return m_images;
}

/*
FUNCTION: Accessor returning the current image defined by mN_spriteIndex.
INPUTS: /
OUTPUTS: SDL_Texutre pointer referencing the address of the current image.
*/
SDL_Texture * cSprite::GetCurrentSprite()
{
	return m_images[mN_spriteIndex];
}

/*
FUNCTION: Accessor returning the number of images contained within m_images.
INPUTS: /
OUTPUTS: Integer defining the length of m_images.
*/
int cSprite::GetNbImages()
{
	int i = 0;

	while (m_images[i] != NULL)
	{
		i += 1;
	}
	return i - 1;
}

/*
FUNCTION: Accessor returning the index of the current image in m_images.
INPUTS: /
OUTPUTS: Integer.
*/
int cSprite::GetSpriteIndex()
{
	return mN_spriteIndex;
}

/*
FUNCTION: Accessor returning the boolean defining if the sprite is flipped.
INPUTS: /
OUTPUTS: Boolean.
*/
bool cSprite::IsFlipped()
{
	return mB_flipped;
}

	//MUTATORS
/*
FUNCTION: Mutator setting the SDL_Texture pointers array with a SDL_Texture**.
INPUTS: SDL_Texture pointers array.
OUTPUTS: Setting of m_images.
*/
void cSprite::SetIMG(SDL_Texture** img)
{
	m_images = img;
}

/*
FUNCTION: Mutator setting the mB_flipped boolean.
INPUTS: Boolean value.
OUTPUTS: Setting mB_flipped value.
*/
void cSprite::Flip(bool value)
{
	mB_flipped = value;
}

	//INITIALIZATION	
/*
FUNCTION: Initialize common member variables such as mN_spriteIndex. It is called by each constructor.
INPUTS: /
OUTPUTS: Setting common member variables.
*/
void cSprite::Initialization()
{
	mN_spriteIndex = 0;
}


	//OTHER
/*
FUNCTION: Handle the image index incrementation for each images contained by m_images.
INPUTS: /
OUTPUTS: Incrementation of mN_spriteIndex.
*/
void cSprite::NextSprite()
{
	if (mN_spriteIndex < GetNbImages()-1)
		mN_spriteIndex++;
	else
		mN_spriteIndex = 1;
}
