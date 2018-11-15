#pragma once

#include <SDL_image.h>
#include <SDL.h>
#include <string>
#include <iostream>

/*
cSprite class :

It is an object containing an array of SDL_Texture pointers defining the images within this sprite.
It's supposed to handle multiple images in a unique object to visually animate them.

*/
class cSprite
{
public:
		//Constructors
	cSprite();//Constructor without parameter.
	cSprite(SDL_Texture** img);//Constructor with an array of SDL_Texture pointers.
	cSprite(std::string imgPath, SDL_Renderer* renderer);//Constructor with the images path folder and the renderer to link the textures to.
		//Destructors
	~cSprite();//Destructor by default.
		//Accessors
	SDL_Texture** GetIMG();//Returns all the SDL_Texture pointers in m_images
	SDL_Texture* GetCurrentSprite();//Returns the current SDL_Texture pointer defined by the sprite index
	int GetSpriteIndex();//Returns the index of the current image (sprite) of m_images
	int GetNbImages();//Returns the number of images contained in m_images
	bool IsFlipped();//Returns the boolean defining if the sprite is flipped
		//Mutators
	void SetIMG(SDL_Texture** img);//Defines the SDL_Texture pointers array 
	void Flip(bool value);//Flips the sprites
		//Initialization
	void Initialization();//Initializes common variables such as : Sprite index
		//Other
	void NextSprite();
private:
	SDL_Texture** m_images;//All the images contained in the sprite
	int mN_spriteIndex;//Index of the current image
	bool mB_flipped;//Is the sprite flipped
	std::string m_imgPath;//Images path to load the images from
};

