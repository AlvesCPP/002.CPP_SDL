#include "cVect2D.h"



	//CONSTRUCTEURS

/*
BUT: Constructeur sans paramètre, assigne les champs à 0.0
ENTREES: /
SORTIES: Initialisation des champs mFlt_x et mFlt_y
*/
cVect2D::cVect2D()
{
	mFlt_x = 0.0;
	mFlt_y = 0.0;
}

/*
BUT: Constructeur avec paramètre obligatoire, pointeur de cVect2D
ENTREES: pointeur de cVect2D
SORTIES: Initialisation des champs mFlt_x et mFlt_y
*/
cVect2D::cVect2D(cVect2D* ptrVect)
{
	if (ptrVect != NULL)
	{
		mFlt_x = ptrVect->mFlt_x;
		mFlt_y = ptrVect->mFlt_y;
	}
}

/*
BUT: Constructeur avec un paramètre obligatoire et un paramètre par défaut.
ENTREES: 2 floats
SORTIES: Initialisation des champs mFlt_x et mFlt_y
*/
cVect2D::cVect2D(float x, float y)
{
	mFlt_x = x;
	mFlt_y = y;
}

	//ACCESSEURS

/*
BUT: Accesseur du champ mFlt_x
ENTREES: /
SORTIES: mFlt_x
*/
float cVect2D::GetX() const
{
	return mFlt_x;
}

/*
BUT: Accesseur du champ mFlt_y
ENTREES: /
SORTIES: mFlt_y
*/
float cVect2D::GetY() const
{
	return mFlt_y;
}

	//MUTATEURS

/*
BUT: Mutateur des champs mFlt_x et mFlt_y
ENTREES: 2 floats x et y
SORTIES: Modification des champs mFlt_x et mFlt_y
*/
void cVect2D::SetXY(float x, float y)
{
	mFlt_x = x;
	mFlt_y = y;
}

/*
BUT: Mutateur du champ mFlt_x
ENTREES: 1 float x
SORTIES: Modification du champ mFlt_x
*/
void cVect2D::SetX(float x)
{
	mFlt_x = x;
}

/*
BUT: Mutateur du champ mFlt_y
ENTREES: 1 float y
SORTIES: Modification du champ mFlt_y
*/
void cVect2D::SetY(float y)
{
	mFlt_y = y;
}

	//OPERATIONS

/*
BUT: Addition avec un autre vecteur
ENTREES: 1 vecteur
SORTIES: Modification des champs mFlt_x et mFlt_y
*/
void cVect2D::Add(cVect2D term)
{
	mFlt_x += term.mFlt_x;
	mFlt_y += term.mFlt_y;
}

/*
BUT: Soustraction avec un autre vecteur
ENTREES: 1 vecteur
SORTIES: Modification des champs mFlt_x et mFlt_y
*/
void cVect2D::Sub(cVect2D operand) 
{
	mFlt_x -= operand.mFlt_x;
	mFlt_y -= operand.mFlt_y;
}

/*
BUT: Multiplication avec un autre vecteur
ENTREES: 1 vecteur
SORTIES: Modification des champs mFlt_x et mFlt_y
*/
void cVect2D::Mult(cVect2D factor)
{
	mFlt_x *= factor.mFlt_x;
	mFlt_y *= factor.mFlt_y;
}

/*
BUT: Multiplication par un scalaire
ENTREES: 1 float
SORTIES: Modification des champs mFlt_x et mFlt_y
*/
void cVect2D::Mult(float factor)
{
	mFlt_x *= factor;
	mFlt_y *= factor;
}

/*
BUT: Retourne le produit scalaire de deux vecteurs
ENTREES: 1 autre vecteur
SORTIES: float (produit scalaire)
*/
float cVect2D::ScalarProduct(cVect2D factor)const
{
	return ((mFlt_x * factor.mFlt_x) + (mFlt_y * factor.mFlt_y));
}

/*
BUT: Retourne le type d'angle entre deux vecteurs
ENTREES: 1 autre vecteur
SORTIES: ENUM_Angle (type d'angle)
*/
ENUM_Angle cVect2D::AngleType(cVect2D other)const
{
	if (this->ScalarProduct(other) > 0.0)
		return Acute;
	if (this->ScalarProduct(other) < 0.0)
		return Obtuse;
	else
		return Right;
}

/*
BUT: Retourne le produit des normes de deux vecteurs
ENTREES: 1 vecteur
SORTIES: float (produit des normes)
*/
float cVect2D::NormProduct(cVect2D other)const
{
	return(sqrt( pow(other.mFlt_x - mFlt_x, 2) + pow(other.mFlt_y - mFlt_y, 2) ));
}

	//CONVERSIONS

/*
BUT: Retourne la conversion en chaine de caractères des champs du vecteur
ENTREES: /
SORTIES: string
*/
std::string cVect2D::ToString()const
{
	return ("x = " + std::to_string(mFlt_x) + " y = " + std::to_string(mFlt_y));
}

