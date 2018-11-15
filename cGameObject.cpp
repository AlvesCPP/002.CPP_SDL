#include "cGameObject.h"


	//CONSTRUCTORS
/*
FUNCTION: Constructor with no parameter, sets default values.
INPUTS: /
OUTPUTS: Sprite member value set to NULL, Scale member value set to the default scale value.
*/
cGameObject::cGameObject()
{
	m_sprite = NULL;
	m_scale = new cVect2D((float)DEFAULT_SCALE, (float)DEFAULT_SCALE);
}

/*
FUNCTION: Constructor with parameters, initialize more specific GameObjects.
INPUTS: String of the image path, 2D vectors for the scale and position, Renderer address to associate the loaded images to, Boolean for the sensitivity to user input.
OUTPUTS: Calls cSprite and cVect2D constructors considering the input values, sets mB_inputSensitive.
*/
cGameObject::cGameObject(std::string imgPath, cVect2D pos, cVect2D scale, SDL_Renderer* renderer, bool inputSensitive) : m_position(pos), m_scale(scale), m_sprite(imgPath, renderer)
{
	mB_inputSensitive = inputSensitive;
}

	//ACCESSORS
/*
FUNCTION: Accessor returning the address of the sprite member variable.
INPUTS: /
OUTPUTS: Returns a cSprite pointer.
*/
cSprite* cGameObject::GetSprite()
{
	return &m_sprite;
}

/*
FUNCTION: Accessor returning the position member variable.
INPUTS: /
OUTPUTS: Returns a cVect2D value.
*/
cVect2D cGameObject::GetPosition()
{
	return m_position;
}

/*
FUNCTION: Accessor returning the scale member variable.
INPUTS: /
OUTPUTS: Returns a cVect2D value.
*/
cVect2D cGameObject::GetScale()
{
	return m_scale;
}

/*
FUNCTION: Accessor returning the speed member variable.
INPUTS: /
OUTPUTS: Returns a Float value.
*/
float cGameObject::GetSpeed()
{
	return mFlt_speed;
}

/*
FUNCTION: Accessor returning the inputSensitive member variable.
INPUTS: /
OUTPUTS: Returns a Boolean value.
*/
bool cGameObject::InputSensitive()
{
	return mB_inputSensitive;
}

	//MUTATORS
/*
FUNCTION: Mutator adding a float value to the x of the cVect2D position attribute.
INPUTS: Float value to add to the x cVect2D position attribute.
OUTPUTS: Addition to the Float value of m_position x attribute by calling the cVect2D Add function.
*/
void cGameObject::AddToX_Position(float x)
{
	m_position.Add(cVect2D(x, 0));
}

/*
FUNCTION: Mutator setting the scale of the GameObject.
INPUTS: cVect2D the new scale to be set to.
OUTPUTS: Setting of m_scale member variable.
*/
void cGameObject::SetScale(cVect2D newScale)
{
	m_scale = newScale;
}

/*
FUNCTION: Mutator setting the movement speed of the GameObject.
INPUTS: Float new speed value.
OUTPUTS: Setting of mFlt_speed member variable.
*/
void cGameObject::SetSpeed(float newSpeed)
{
	mFlt_speed = newSpeed;
}

