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
//::|��| FILENAME	   :: XDefinition.h													  |��|::
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

#ifndef XDEFINITION_H
#define XDEFINITION_H

#pragma comment(lib, "winmm.lib")
#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#include <Windows.h>
#include <WindowsX.h>
#include <MMSystem.h>
#include <StdLib.h>
#include <StdIO.h>

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "Glu32.lib")
#include <GL/GLU.h>
#include <GL/GL.h>

#pragma warning (disable : 4172)
#pragma warning (disable : 4786)
#include <Algorithm>
#include <FStream>
#include <String>
#include <Vector>
#include <Map>
#include <Set>
using namespace std;

#ifdef ULTIMAX_VERSION
#	define ULTIMAX_VERSION 0x0001
#endif

#if defined(__cplusplus)
#	define XINLINE inline
#else
#	define XINLINE
#endif

#ifdef ULTIMAXAPI
#	define XAPI __declspec(dllexport)
#	define XAPISTD _stdcall
#	pragma message("|")
#	pragma message("|ULTIMAX API DEFINED")
#	pragma message("|")
#else
#	define XAPI __declspec(dllimport)
#endif

#define Xtrue    (1==1)
#define Xfalse   !Xtrue
#define Xint     int
#define Xvoid    void
#define Xbyte    char
#define Xchar    char
#define Xbool    bool
#define Xlong    long
#define Xcrptr   char*
#define Xshort   short
#define Xfloat   float
#define Xdouble  double
#define XI64     __int64
#define Xlongi   long int
#define Xshorti  short int
#define Xsint    signed int
#define Xccrptr  const char*
#define Xslong   signed long
#define Xschar   signed char
#define Xsbyte   signed char
#define Xsshort  signed short
#define XLI		 LARGE_INTEGER
#define Xslongi  signed long int
#define Xsshorti signed short int
#define Xuint    unsigned int
#define Xulong   unsigned long
#define Xushort  unsigned short
#define Xuchar   unsigned char
#define Xubyte   unsigned char
#define Xulongi  unsigned long int
#define Xushorti unsigned short int

#define Xdelete(X)					\
		{							\
			try						\
			{						\
				if(X)				\
				{					\
					delete(X);		\
					(X)=NULL;		\
				}					\
			}catch(...){}			\
		}

#define Xdeletea(X)					\
		{							\
			try						\
			{						\
				if(X)				\
				{					\
					delete[](X);	\
					(X)=NULL;		\
				}					\
			}catch(...){}			\
		}

#define Xdeleteo(X)					\
		{							\
			try						\
			{						\
				if(X)				\
				{					\
					(X)->Release(); \
					(X)=NULL;		\
				}					\
			}catch(...){}			\
		}


#include "XString.h"
#endif //--XDEFINITION_H