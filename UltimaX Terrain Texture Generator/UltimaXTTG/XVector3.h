//::|сссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссс|::
//::|сс ---------------------------------------------------------------------------------- сс|::
//::|сс|						~ A R I E L   P R O D U C T I O N S ~                     |сс|::
//::|сс|                               ~ ALL RIGHTS RESERVED ~                            |сс|::
//::|сс ---------------------------------------------------------------------------------- сс|::
//::|сс| ~ PROGRAM DATA ~													      /-----/ |сс|::
//::|сс|							            								/-----/ | |сс|::
//::|сс| PROGRAMMER:: James Dougherty											| |   | | |сс|::
//::|сс| COPYRIGHT :: ©2002-2003 Ariel Productions								| |   | | |сс|::
//::|сс| TYPE      :: Game Engine												| /---|-/ |сс|::
//::|сс|																		/-----/   |сс|::
//::|сс ---------------------------------------------------------------------------------- сс|::
//::|сс| ~ SOURCE DATA ~																  |сс|::
//::|сс|																				  |сс|::
//::|сс| FILENAME	   :: XVector3.h													  |сс|::
//::|сс| VERSION	   :: 1.0															  |сс|::
//::|сс| REVISION DATE :: 00.00.00														  |сс|::
//::|сс|																				  |сс|::
//::|сс| REVISION DATA ::																  |сс|::
//::|сс| | 																				  |сс|::
//::|сс| |-00.00.00																		  |сс|::
//::|сс| |-																				  |сс|::
//::|сс| |-N/A																			  |сс|::
//::|сс| |																				  |сс|::
//::|сс|																				  |сс|::
//::|сс| BUGS ::																		  |сс|::
//::|сс| |																				  |сс|::
//::|сс| |-N/A																			  |сс|::
//::|сс| |																				  |сс|::
//::|сс|																				  |сс|::
//::|сс ---------------------------------------------------------------------------------- сс|::
//::|сссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссссс|::

#ifndef XVECTOR3_H
#define XVECTOR3_H
#include "XMathBase.h"

class XVECTOR3
{
public:
	XVECTOR3(Xvoid);
	XVECTOR3(const Xfloat);
    XVECTOR3(const Xfloat *);
	XVECTOR3(const XVECTOR3 &);
    XVECTOR3(Xfloat, Xfloat, Xfloat);

	Xfloat X;
	Xfloat Y;
	Xfloat Z;

public: //--Operators
	operator Xfloat* (Xvoid);
    operator const Xfloat* (Xvoid) const;
	
	XVECTOR3  operator *  (const XVECTOR3 &) const;
	XVECTOR3  operator /  (const XVECTOR3 &) const;
	XVECTOR3  operator ^  (const XVECTOR3 &) const;
	XVECTOR3  operator <  (const XVECTOR3 &) const;
	XVECTOR3  operator >  (const XVECTOR3 &) const;
	XVECTOR3  operator +  (const XVECTOR3 &) const;
    XVECTOR3  operator -  (const XVECTOR3 &) const;
    Xbool     operator == (const XVECTOR3 &) const;
    Xbool     operator != (const XVECTOR3 &) const;
	Xfloat    operator %  (const XVECTOR3 &) const;
    XVECTOR3& operator += (const XVECTOR3 &);
    XVECTOR3& operator -= (const XVECTOR3 &);
    XVECTOR3& operator *= (Xfloat);
    XVECTOR3& operator /= (Xfloat);
	XVECTOR3  operator *  (Xfloat)const;
	XVECTOR3  operator /  (Xfloat)const;
    XVECTOR3  operator +  (Xvoid) const;
    XVECTOR3  operator -  (Xvoid) const;

public: //--Modifiers
	XVECTOR3  Add(const XVECTOR3 *, const XVECTOR3 *);
	XVECTOR3  Subtract(const XVECTOR3 *, const XVECTOR3 *);
	XVECTOR3  Average(const XVECTOR3 *, const XVECTOR3 *);
	XVECTOR3  Divide(Xfloat, const XVECTOR3 *);
	XVECTOR3  Divide(const XVECTOR3 *, Xfloat);
	XVECTOR3  Divide(const XVECTOR3 *, const XVECTOR3 *);
	XVECTOR3  Multiply(Xfloat, const XVECTOR3 *);
	XVECTOR3  Multiply(const XVECTOR3 *, Xfloat);
	XVECTOR3  Multiply(const XVECTOR3 *, const XVECTOR3 *);
	Xfloat    DotProduct(const XVECTOR3 *);
	Xvoid     Copy(XVECTOR3 *);
	Xvoid	  Zero(Xvoid);
	Xbool	  IsZero(Xvoid);
	Xvoid	  Negate(Xvoid);
	Xfloat	  Magnitude(Xvoid);
	Xfloat	  MagnitudeSQ(Xvoid);
	Xvoid	  Normalize(Xvoid);
	Xvoid	  NormalizeEX(Xvoid);
	Xint      Sign(Xvoid);
	Xvoid     CrossProduct(const XVECTOR3 *, const XVECTOR3 *);
	Xvoid     CrossProductEX(const XVECTOR3 *, const XVECTOR3 *);
	Xfloat    ScalarProduct(const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *);
	Xvoid     Power(const XVECTOR3 *, const XVECTOR3 *);
	Xvoid     Spherical(Xfloat, Xfloat, Xfloat);
	Xvoid	  Scale(XVECTOR3 *, const XVECTOR3 *, Xfloat);
	Xvoid     Minimize(const XVECTOR3 *, const XVECTOR3 *);
	Xvoid	  Maximize(const XVECTOR3 *, const XVECTOR3 *);
	Xfloat	  Distance(const XVECTOR3 *);
	Xfloat	  DistanceEX(const XVECTOR3 *, const XVECTOR3 *);
	Xint	  FastDistance(Xint, Xint);
	Xbool	  NearlyEqual(const XVECTOR3 *);
	//Xvoid	  InterpLinear(XVECTOR3 *, Xfloat, const XVECTOR3 *, const XVECTOR3 *);
	//Xvoid	  InterpLinearEX(XVECTOR3 *, Xlong, Xfloat, const XVECTOR3 *, const XVECTOR3 *);
	//Xvoid	  InterpHermitSpline(XVECTOR3 *, Xfloat, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *);
	//Xvoid	  InterpHermitSplineEX(XVECTOR3 *, Xlong, Xfloat, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *);
	//Xvoid	  InterpBSpline(XVECTOR3 *, Xfloat, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *);
	//Xvoid	  InterpBSplineT(XVECTOR3 *, Xfloat, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *);
	//Xvoid	  InterpCatmulRom(XVECTOR3 *, Xfloat, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *);
	//Xvoid	  InterpCatmulRomT(XVECTOR3 *, Xfloat, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *, const XVECTOR3 *);
};

#endif //--XVECTOR3_H