#pragma once

#include <math.h>
#include <string>

typedef enum ENUM_Angle//Enumération définissant le type d'angle
{
	Obtuse, Right, Acute
}ENUM_Angle;

class cVect2D
{
	public:
		//Constructors
		cVect2D();//Constructeur sans paramètre
		cVect2D(cVect2D* ptrVect);//Constructeur avec paramètre obligatoire (copie d'un pointeur de vecteur)
		cVect2D(float x, float y = 1.0);//Constructeur avec un paramètre par défaut
		//Accessors
		float GetX() const;
		float GetY() const;
		//Mutators
		void SetXY(float x, float y);
		void SetX(float x);
		void SetY(float y);
		//Operations
		void Add(cVect2D term);//Addition vectorielle entre ce vecteur et le vecteur term.
		void Sub(cVect2D operand);//Soustraction vectorielle entre ce vecteur et le vecteur operand.
		void Mult(cVect2D factor);//Produit vectoriel entre ce vecteur et le vecteur factor.
		void Mult(float factor);//Multiplication par le scalaire factor.
		float ScalarProduct(cVect2D factor)const;//Produit scalaire de ce vecteur et du vecteur factor.
		float NormProduct(cVect2D factor)const;//Produit des normes de ce vecteur et du vecteur factor.
		ENUM_Angle AngleType(cVect2D other)const;//Retourne le type d'angle entre ce vecteur et le vecteur other (aigu, obtus, ou droit)
		//Conversion
		std::string ToString()const;//Conversion des champs de ce vecteur en string.
	protected:
	private:
		float mFlt_x;
		float mFlt_y;
};