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
//::|сс| FILENAME	   :: XMathBase.cpp													  |сс|::
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

#include "XMathBase.h"
#include <Math.h>

const Xfloat XMATH::PI       = 3.1415926535897932384626433832795f;
const Xfloat XMATH::PIX2     = XMATH::PI * 2.0f;
const Xfloat XMATH::PID2     = XMATH::PI / 2.0f;
const Xfloat XMATH::BGFLT    = 10e-5f;
const Xfloat XMATH::MAXVAL   = ((Xfloat)(Xuint)(1 << 31));
const Xfloat XMATH::RADIANT  = 1.74532925199433E-02f;
const Xfloat XMATH::EPSILON  = 0.0001f;
const Xfloat XMATH::INFINITY = 3.402823466e+38F;

Xfloat XMATH::DTR(Xfloat F)
{
	return F * 0.017453292519943295769236907684883f;
}

Xfloat XMATH::RTD(Xfloat F)
{
	return F * 57.295779513082320876798154814114f;
}

Xfloat XMATH::Abs(Xfloat F)
{
	return Xfloat(fabs(F));
}

Xfloat XMATH::Cos(Xfloat F)
{
	return Xfloat(cos(F));
}

Xfloat XMATH::Exp(Xfloat F)
{
	return Xfloat(exp(F));
}

Xfloat XMATH::Log(Xfloat F)
{
	return Xfloat(log(F));
}

Xfloat XMATH::Sin(Xfloat F)
{
	return Xfloat(sin(F));
}

Xfloat XMATH::Sqr(Xfloat F)
{
	return F*F;
}

Xfloat XMATH::ACos(Xfloat F)
{
	if(-1.0f < F){if(F < 1.0f){return Xfloat(acos(F));}else{return 0.0f;}}else{return PI;}
}

Xfloat XMATH::ASin(Xfloat F)
{
	if(-1.0f < F){if(F < 1.0f){return Xfloat(acos(F));}else{return -PID2;}}else{return PID2;}
}

Xfloat XMATH::Ceil(Xfloat F)
{
	return Xfloat(ceil(F));
}

Xfloat XMATH::Sign(Xfloat F)
{
	if(F > 0.0f){return  1.0;}
	if(F < 0.0f){return -1.0;}
	return 0.0f;
}

Xfloat XMATH::Sqrt(Xfloat F)
{
	return Xfloat(sqrt(F));
}

Xfloat XMATH::ATan(Xfloat F)
{
	return Xfloat(atan(F));
}

Xfloat XMATH::Floor(Xfloat F)
{
	return Xfloat(floor(F));
}

Xfloat XMATH::FFabs(const Xfloat &F)
{
	Xint* V = (Xint*)&F;
	Xint  R = *V & 0x7FFFFFFF;
	return Xfloat(*(&R));
}

Xfloat XMATH::Min(Xfloat F1, Xfloat F2)
{
	return ((F1) < (F2) ? (F1) : (F2));
}

Xfloat XMATH::Max(Xfloat F1, Xfloat F2)
{
	return ((F1) > (F2) ? (F1) : (F2));
}

Xfloat XMATH::Pow(Xfloat F1, Xfloat F2)
{
	return Xfloat(pow(F1, F2));
}

Xfloat XMATH::ATan2(Xfloat F1, Xfloat F2)
{
	return Xfloat(atan2(F1, F2));
}

Xvoid XMATH::Swap(Xfloat &F1, Xfloat &F2)
{
	Xfloat T = F1;
	F1 = F2;
	F2 = T;
}

Xfloat XMATH::Random(Xfloat Min, Xfloat Max)
{
	return Min + (Max - Min)*((Xfloat)rand() / RAND_MAX);
}

Xfloat XMATH::Min3(Xfloat F1, Xfloat F2, Xfloat F3)
{
	return (F1 < F2 && F1 < F3) ? F1 : (F2 < F3 ? F2 : F3);
}

Xfloat XMATH::Max3(Xfloat F1, Xfloat F2, Xfloat F3)
{
	return (F1 > F2 && F1 > F3) ? F1 : (F2 > F3 ? F2 : F3);
}
