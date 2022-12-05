//::|����������������������������������������������������������������������������������������|::
//::|�� ---------------------------------------------------------------------------------- ��|::
//::|��|						~ A R I E L   P R O D U C T I O N S ~                     |��|::
//::|��|                               ~ ALL RIGHTS RESERVED ~                            |��|::
//::|�� ---------------------------------------------------------------------------------- ��|::
//::|��| ~ PROGRAM DATA ~													      /-----/ |��|::
//::|��|							            								/-----/ | |��|::
//::|��| PROGRAMMER:: James Dougherty											| |   | | |��|::
//::|��| COPYRIGHT :: �2002-2003 Ariel Productions								| |   | | |��|::
//::|��| TYPE      :: Game Engine												| /---|-/ |��|::
//::|��|																		/-----/   |��|::
//::|�� ---------------------------------------------------------------------------------- ��|::
//::|��| ~ SOURCE DATA ~																  |��|::
//::|��|																				  |��|::
//::|��| FILENAME	   :: XMathBase.h													  |��|::
//::|��| VERSION	   :: 1.0															  |��|::
//::|��| REVISION DATE :: 00.00.00														  |��|::
//::|��|																				  |��|::
//::|��| REVISION DATA ::																  |��|::
//::|��| | 																				  |��|::
//::|��| |-00.00.00																		  |��|::
//::|��| |-																				  |��|::
//::|��| |-N/A																			  |��|::
//::|��| |																				  |��|::
//::|��|																				  |��|::
//::|��| BUGS ::																		  |��|::
//::|��| |																				  |��|::
//::|��| |-N/A																			  |��|::
//::|��| |																				  |��|::
//::|��|																				  |��|::
//::|�� ---------------------------------------------------------------------------------- ��|::
//::|����������������������������������������������������������������������������������������|::

#ifndef XMATHBASE_H
#define XMATHBASE_H
#include "XDefinition.h"

#pragma once
class XMATH
{
public:
	static const Xfloat PI;
    static const Xfloat PIX2;
    static const Xfloat PID2;
	static const Xfloat BGFLT;
	static const Xfloat MAXVAL;
	static const Xfloat RADIANT;
	static const Xfloat EPSILON;
	static const Xfloat INFINITY;

	static Xfloat DTR(Xfloat F);
	static Xfloat RTD(Xfloat F);
    static Xfloat Abs(Xfloat F);
	static Xfloat Cos(Xfloat F);
    static Xfloat Exp(Xfloat F);
	static Xfloat Log(Xfloat F);
	static Xfloat Sin(Xfloat F);
    static Xfloat Sqr(Xfloat F);
    static Xfloat ACos(Xfloat F);
    static Xfloat ASin(Xfloat F);
    static Xfloat Ceil(Xfloat F);
    static Xfloat Sign(Xfloat F);
    static Xfloat Sqrt(Xfloat F);
	static Xfloat ATan(Xfloat F);
	static Xfloat Floor(Xfloat F);
	static Xfloat FFabs(const Xfloat &F);
	static Xfloat Min(Xfloat F1, Xfloat F2);
	static Xfloat Max(Xfloat F1, Xfloat F2);
	static Xfloat Pow(Xfloat F1, Xfloat F2);
    static Xfloat ATan2(Xfloat F1, Xfloat F2);
	static Xvoid  Swap(Xfloat &F1, Xfloat &F2);
    static Xfloat Random(Xfloat Min, Xfloat Max);
	static Xfloat Min3(Xfloat F1, Xfloat F2, Xfloat F3);
	static Xfloat Max3(Xfloat F1, Xfloat F2, Xfloat F3);
};

#endif //--XMATHBASE_H