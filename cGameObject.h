#pragma once

#include "SDL.h"
#include "cVect2D.h"
#include "cSprite.h"

/*
cGameObject class :

It is an object supposed to contain geometric properties of a representation on a plane.
It has a visual representation defined a cSprite variable member.


*/

class cGameObject
{
public:
		//CONSTS
	static const int DEFAULT_SCALE = 1;//Default scale of the GameObject
		//Constructors
	cGameObject();//Default constructor
	cGameObject(std::string imgPath, cVect2D pos, cVect2D scale, SDL_Renderer* renderer, bool inputSensitive);//Constructor with specified parameters
		//Accessors
	cSprite* GetSprite();//Returning the address of the GameObject sprite
	cVect2D GetPosition();//Returning the current position of the GameObject
	cVect2D GetScale();//Returning the current scale of the GameObject
	float GetSpeed();//Returning the current speed of the GameObject
	bool InputSensitive();//Returning the boolean defining if the GameObject is influenced by the user input
		//Mutators
	void AddToX_Position(float x);//Incrementing the X value of the GameObject position
	void SetScale(cVect2D newScale);//Setting the GameObject scale
	void SetSpeed(float newSpeed);//Setting the GameObject speed
private:
	cSprite m_sprite;//Sprite object, contains all the images
	float mFlt_speed;//Movement speed
	bool mB_inputSensitive;//Sensitivity to inputs, if false the GameObject will not natively react to inputs
	cVect2D m_position;//Position on screen
	cVect2D m_scale;//Multiplication of the base scale
};

