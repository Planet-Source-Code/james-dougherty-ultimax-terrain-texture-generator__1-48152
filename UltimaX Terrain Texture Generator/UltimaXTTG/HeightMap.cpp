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
//::|сс| FILENAME	   :: XHeightMap.cpp												  |сс|::
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

#include "HeightMap.h"
#include "XTexture.h"

XTEXTURE g_BlendMap;
XTEXTURE g_RoughMap;
XTEXTURE g_ShadeMap;
XTEXTURE g_HeightMap;
Xbool	 g_BlendCalculated = Xfalse;
Xbool	 g_ShadeCalculated = Xfalse;
Xuchar*  g_CanvasData      = NULL;
Xuchar*  g_ShadeField      = NULL;
Xuchar*  g_RoughField      = NULL;
Xuchar*  g_HeightField     = NULL;
Xuint    g_HeightmapSize   = 0;

//------------------------------------------------------------------------------------------------
//--
//--HValidIndex(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE Xuint ValidIndex(Xuint X, Xuint Z)
{
	if(X < 0 || X >= g_HeightmapSize || Z < 0 || Z >= g_HeightmapSize)
	{
        return 0;
    }

	return (Z % (g_HeightmapSize - 1)) * g_HeightmapSize + (X % (g_HeightmapSize - 1));
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_PreLoad(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XAPI Xvoid XAPISTD HeightMap_PreLoad(BSTR Filename)
{
	Xchar  StringConversion[512];
	Xuchar Shade = 0;
	Xuint  DID = 0,
		   SID = 0;

	sprintf(StringConversion, "%s", Filename);
	g_HeightMap = GTEXTURESYS->CreateTexture(StringConversion);
	g_HeightmapSize = g_HeightMap.Width;

	g_CanvasData    = new Xuchar[g_HeightmapSize * g_HeightmapSize * 4];
	g_ShadeField    = new Xuchar[g_HeightMap.Width * g_HeightMap.Width];
	g_RoughField    = new Xuchar[g_HeightMap.Width * g_HeightMap.Width];
	g_HeightField   = new Xuchar[g_HeightMap.Width * g_HeightMap.Width];
	g_BlendMap.Data = (Xuchar*)malloc(g_HeightmapSize * g_HeightmapSize * 4);
	g_RoughMap.Data	= (Xuchar*)malloc(g_HeightmapSize * g_HeightmapSize * 3);
	g_ShadeMap.Data	= (Xuchar*)malloc(g_HeightmapSize * g_HeightmapSize * 3);

	if(g_CanvasData == NULL || g_HeightField == NULL   || g_ShadeField == NULL    ||
	   g_RoughField == NULL || g_RoughMap.Data == NULL || g_ShadeMap.Data == NULL || g_BlendMap.Data == NULL)
	{
		return;
	}

	ZeroMemory(g_RoughField,  g_HeightmapSize * g_HeightmapSize * sizeof(Xuchar));
	ZeroMemory(g_ShadeField,  g_HeightmapSize * g_HeightmapSize * sizeof(Xuchar));
	ZeroMemory(g_HeightField, g_HeightmapSize * g_HeightmapSize * sizeof(Xuchar));
	ZeroMemory(g_BlendMap.Data, g_HeightmapSize * g_HeightmapSize * 4 * sizeof(Xuchar));
	ZeroMemory(g_RoughMap.Data, g_HeightmapSize * g_HeightmapSize * 3 * sizeof(Xuchar));
	ZeroMemory(g_ShadeMap.Data, g_HeightmapSize * g_HeightmapSize * 3 * sizeof(Xuchar));

	for(Xuint X = 0; X < g_HeightmapSize; X++)
	{
		for(Xuint Z = 0; Z < g_HeightmapSize; Z++)
		{
			DID   = (4 * ValidIndex(X, Z));
			SID   = (g_HeightMap.Channels * ValidIndex(X, Z));
			Shade = (g_HeightMap.Data[SID + 0] + g_HeightMap.Data[SID + 1] + g_HeightMap.Data[SID + 2]) / 3;

			g_HeightField[ValidIndex(X, Z)] = Shade;
			g_CanvasData[DID + 0] = Shade;
			g_CanvasData[DID + 1] = Shade;
			g_CanvasData[DID + 2] = Shade;
			g_CanvasData[DID + 3] = 255;
		}
	}
	GTEXTURESYS->SaveTexture("HeightMap_C.bmp", g_HeightMap);
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_FinalizeLoad(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XAPI Xvoid XAPISTD HeightMap_FinalizeLoad(HDC hDC)
{
	BITMAPINFO BitmapInfo;
	ZeroMemory(&BitmapInfo.bmiHeader, sizeof(BITMAPINFOHEADER));
	BitmapInfo.bmiHeader.biSize		   = sizeof(BITMAPINFOHEADER);
	BitmapInfo.bmiHeader.biHeight	   = -(Xint)g_HeightmapSize;
    BitmapInfo.bmiHeader.biWidth	   =  (Xint)g_HeightmapSize;
	BitmapInfo.bmiHeader.biSizeImage   = g_HeightmapSize * g_HeightmapSize * 4;
	BitmapInfo.bmiHeader.biCompression = BI_RGB;
	BitmapInfo.bmiHeader.biBitCount	   = 32;
    BitmapInfo.bmiHeader.biPlanes	   = 1;
	StretchDIBits(hDC, 0, 0, g_HeightmapSize, g_HeightmapSize, 0, 0, g_HeightmapSize, g_HeightmapSize, g_CanvasData, &BitmapInfo, 0, SRCCOPY);
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_Cleanup(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XAPI Xvoid XAPISTD HeightMap_Cleanup(Xvoid)
{
	free(g_BlendMap.Data);
	free(g_RoughMap.Data);
	free(g_ShadeMap.Data);
	free(g_HeightMap.Data);
	Xdeletea(g_CanvasData);
	Xdeletea(g_ShadeField);
	Xdeletea(g_HeightField);
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_GetExtent(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XAPI Xint XAPISTD HeightMap_GetExtent(Xvoid)
{
	return g_HeightmapSize;
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_GetHeightPoint(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE Xfloat HeightMap_GetHeightPoint(Xuint X, Xuint Z)
{
    return g_HeightField[ValidIndex(X, Z)];
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_SmoothRoughMap(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xvoid HeightMap_SmoothRoughMap(Xuint SmoothIterations)
{
	Xuchar* SmoothField = NULL;

	for(Xuint ID = 0; ID < SmoothIterations; ID++)
	{
		SmoothField = (Xuchar*)malloc(g_HeightmapSize * g_HeightmapSize);
		if(SmoothField == NULL)
		{
			return;
		}

		for(Xfloat Z = 0.0f; Z < g_HeightmapSize; Z++)
		{
			for(Xfloat X = 0.0f; X < g_HeightmapSize; X++)
			{
				if(X == 0.0f || X == (g_HeightmapSize - 1) || Z == 0.0f || Z == (g_HeightmapSize - 1))
				{
					SmoothField[ValidIndex(X, Z)] = 255 * g_RoughField[ValidIndex(X, Z)];
				}
				else
				{
					Xfloat m11 = g_RoughField[ValidIndex(X - 1, Z - 1)];
					Xfloat m12 = g_RoughField[ValidIndex(X - 1, Z - 0)];
					Xfloat m13 = g_RoughField[ValidIndex(X - 1, Z + 1)];
					Xfloat m21 = g_RoughField[ValidIndex(X - 0, Z - 1)];
					Xfloat m22 = g_RoughField[ValidIndex(X - 0, Z - 0)];
					Xfloat m23 = g_RoughField[ValidIndex(X - 0, Z + 1)];
					Xfloat m31 = g_RoughField[ValidIndex(X + 1, Z - 1)];
					Xfloat m32 = g_RoughField[ValidIndex(X + 1, Z - 0)];
					Xfloat m33 = g_RoughField[ValidIndex(X + 1, Z + 1)];
					SmoothField[ValidIndex(X, Z)] = (m22 + m12 + m21 + m23 + m32 + m11 + m13 + m31 + m33) / 9.0f;
				}
			}
		}

		Xdeletea(g_RoughField);
		g_RoughField = new Xuchar[g_HeightmapSize * g_HeightmapSize * sizeof(Xuchar)];
		memcpy(g_RoughField, SmoothField, (g_HeightmapSize * g_HeightmapSize * sizeof(Xuchar)));

		if(SmoothField)
		{
			free(SmoothField);
		}
	}
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_ComputeMidPointError(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
#define HeightIndex(X, Z) g_HeightField[(Z & (TExtent - 1)) * TExtent + (X & (TExtent - 1))]
XINLINE static Xvoid HeightMap_ComputeMidPointError(Xuchar* HeightData, Xuint TExtent, Xuint X0, Xuint Z0, Xuint X1, Xuint Z1, Xfloat* Error)
{
	Xfloat MidPoint = HeightIndex((X0 + X1) / 2, (Z0 + Z1) / 2),
		   HError   = MidPoint - (HeightIndex(X0, Z0) + HeightIndex(X1, Z1)) / 2.0f;

	if(HError > *Error)
	{
		*Error = HError;
	}
}

//------------------------------------------------------------------------------------------------
//--
//--CalculateRoughnessField(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE Xvoid HeightMap_CalculateRoughnessField(Xint SmoothIterations)
{
	Xint	Level  = 1,
	     	Length = 2;
	Xfloat	Error  = 0.0f;

	Xfloat Extent = -1.0f;
	Xfloat* Data = (Xfloat*)malloc(g_HeightmapSize * g_HeightmapSize * sizeof(Xfloat));
    if(Data == NULL)
    {
		return;
    }

	while(Length <= g_HeightmapSize)
	{
		for(Xuint X = Level; X < g_HeightmapSize; X += Length)
		{
			for(Xuint Z = Level; Z < g_HeightmapSize; Z += Length)
			{
				Error = 0.0f;
				HeightMap_ComputeMidPointError(g_HeightField, g_HeightmapSize, X - Level, Z - Level, X - Level, Z + Level, &Error);
				HeightMap_ComputeMidPointError(g_HeightField, g_HeightmapSize, X + Level, Z - Level, X + Level, Z + Level, &Error);
				HeightMap_ComputeMidPointError(g_HeightField, g_HeightmapSize, X - Level, Z - Level, X + Level, Z - Level, &Error);
				HeightMap_ComputeMidPointError(g_HeightField, g_HeightmapSize, X - Level, Z + Level, X + Level, Z + Level, &Error);
				HeightMap_ComputeMidPointError(g_HeightField, g_HeightmapSize, X - Level, Z - Level, X + Level, Z + Level, &Error);
				HeightMap_ComputeMidPointError(g_HeightField, g_HeightmapSize, X - Level, Z + Level, X + Level, Z - Level, &Error);

				Error /= (Xfloat)Length;
				if(Level > 1)
				{
					Error = XMATH::Max(Error, 0.56f * Data[ValidIndex(X, Z - Level)]);
					Error = XMATH::Max(Error, 0.56f * Data[ValidIndex(X, Z + Level)]);
					Error = XMATH::Max(Error, 0.56f * Data[ValidIndex(X - Level, Z)]);
					Error = XMATH::Max(Error, 0.56f * Data[ValidIndex(X + Level, Z)]);
				}

				Data[ValidIndex(X, Z)] = Error; 
				Data[ValidIndex(X - Level, Z - Level)] = XMATH::Max(Error, Data[ValidIndex(X - Level, Z - Level)]); 
				Data[ValidIndex(X - Level, Z + Level)] = XMATH::Max(Error, Data[ValidIndex(X - Level, Z + Level)]); 
				Data[ValidIndex(X + Level, Z + Level)] = XMATH::Max(Error, Data[ValidIndex(X + Level, Z + Level)]); 
				Data[ValidIndex(X + Level, Z - Level)] = XMATH::Max(Error, Data[ValidIndex(X + Level, Z - Level)]);
			
				if(Extent < Error)
				{
					Extent = Error;
				}
			}
		}

		Level  <<= 1;
		Length <<= 1;
	}

	for(Xuint X = 0; X < g_HeightmapSize; X++)
	{
		for(Xuint Z = 0; Z < g_HeightmapSize; Z++)
		{
			g_RoughField[ValidIndex(X, Z)] = (Xuchar)(Data[ValidIndex(X, Z)] * (255.0f / Extent));
		}
	}

	if(SmoothIterations != 0)
	{
		HeightMap_SmoothRoughMap(SmoothIterations);
	}
	free(Data);
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_CreateRoughMap(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XAPI Xvoid XAPISTD HeightMap_CreateRoughMap(Xint SmoothIterations, Xint ExportExtension)
{
	HeightMap_CalculateRoughnessField(SmoothIterations);

	g_RoughMap.Channels = 3;
	g_RoughMap.Width    = g_HeightmapSize;
	g_RoughMap.Height   = g_HeightmapSize;

	for(Xuint X = 0; X < g_HeightmapSize; X++)
	{
		for(Xuint Z = 0; Z < g_HeightmapSize; Z++)
		{
			g_RoughMap.Data [(3 * ValidIndex(X, Z)) + 0] = 
			g_RoughMap.Data [(3 * ValidIndex(X, Z)) + 1] = 
			g_RoughMap.Data [(3 * ValidIndex(X, Z)) + 2] = g_RoughField[ValidIndex(X, Z)];
		}
	}

	if(ExportExtension == 0)
	{
		GTEXTURESYS->SaveTexture("RoughMap_C.bmp",  g_RoughMap);
	}
	else
	{
		GTEXTURESYS->SaveTexture("RoughMap_C.tga",  g_RoughMap);
	}
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_SmoothShadeMap(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE Xvoid HeightMap_SmoothShadeMap(Xuint Iterationis)
{
	Xuchar* SmoothField = NULL;

	for(Xuint ID = 0; ID < Iterationis; ID++)
	{
		SmoothField = (Xuchar*)malloc(g_HeightmapSize * g_HeightmapSize);
		if(SmoothField == NULL)
		{
			return;
		}

		for(Xfloat Z = 0.0f; Z < g_HeightmapSize; Z++)
		{
			for(Xfloat X = 0.0f; X < g_HeightmapSize; X++)
			{
				if(X == 0.0f || X == (g_HeightmapSize - 1) || Z == 0.0f || Z == (g_HeightmapSize - 1))
				{
					SmoothField[ValidIndex(X, Z)] = 255 * g_ShadeField[ValidIndex(X, Z)];
				}
				else
				{
					Xfloat m11 = g_ShadeField[ValidIndex(X - 1, Z - 1)];
					Xfloat m12 = g_ShadeField[ValidIndex(X - 1, Z - 0)];
					Xfloat m13 = g_ShadeField[ValidIndex(X - 1, Z + 1)];
					Xfloat m21 = g_ShadeField[ValidIndex(X - 0, Z - 1)];
					Xfloat m22 = g_ShadeField[ValidIndex(X - 0, Z - 0)];
					Xfloat m23 = g_ShadeField[ValidIndex(X - 0, Z + 1)];
					Xfloat m31 = g_ShadeField[ValidIndex(X + 1, Z - 1)];
					Xfloat m32 = g_ShadeField[ValidIndex(X + 1, Z - 0)];
					Xfloat m33 = g_ShadeField[ValidIndex(X + 1, Z + 1)];
					SmoothField[ValidIndex(X, Z)] = (m22 + m12 + m21 + m23 + m32 + m11 + m13 + m31 + m33) / 9.0f;
				}
			}
		}

		Xdeletea(g_ShadeField);
		g_ShadeField = new Xuchar[g_HeightmapSize * g_HeightmapSize * sizeof(Xuchar)];
		memcpy(g_ShadeField, SmoothField, (g_HeightmapSize * g_HeightmapSize * sizeof(Xuchar)));

		if(SmoothField)
		{
			free(SmoothField);
		}
	}
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_CalculateShadeField(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE Xvoid HeightMap_CalculateShadeField(LightParamerters* LightParam, Xint SmoothIterations)
{
	XVECTOR3 Normal  = XVECTOR3(0.0f);
	Xfloat   Vertex0 = 0.0f,
		     Vertex1 = 0.0f,
		     Vertex2 = 0.0f;
	Xuint    Shade   = 0;

	for(Xuint X = 0; X < g_HeightmapSize; X++)
	{
		for(Xuint Z = 0; Z < g_HeightmapSize; Z++)
		{
			Vertex0 = HeightMap_GetHeightPoint(X + 0, Z + 1);
			Vertex1 = HeightMap_GetHeightPoint(X + 1, Z + 0);
			Vertex2 = HeightMap_GetHeightPoint(X + 0, Z + 0);

			Normal.CrossProduct(&XVECTOR3(LightParam->Intensity, Vertex1 - Vertex2, 0.0f), &XVECTOR3(0.0f, Vertex0 - Vertex2, LightParam->Intensity));
			Normal.Normalize();

			Shade = (Xuint)(Normal.DotProduct(&LightParam->Positon) * 255.0f);
			if(Shade > 255){Shade = 255;}
			if(Shade < 0)  {Shade = 0;}

			g_ShadeField[ValidIndex(X, Z)] = Shade;
		}
	}

	if(SmoothIterations != 0)
	{
		HeightMap_SmoothShadeMap(SmoothIterations);
	}
	g_ShadeCalculated = Xtrue;
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_CreateShadeMap(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XAPI Xvoid XAPISTD HeightMap_CreateShadeMap(LightParamerters* LightParam, Xint SmoothIterations, Xint ExportExtension)
{
	HeightMap_CalculateShadeField(LightParam, SmoothIterations);

	g_ShadeMap.Channels = 3;
	g_ShadeMap.Width    = g_HeightmapSize;
	g_ShadeMap.Height   = g_HeightmapSize;

	for(Xuint X = 0; X < g_HeightmapSize; X++)
	{
		for(Xuint Z = 0; Z < g_HeightmapSize; Z++)
		{
			g_ShadeMap.Data [(3 * ValidIndex(X, Z)) + 0] = 
			g_ShadeMap.Data [(3 * ValidIndex(X, Z)) + 1] = 
			g_ShadeMap.Data [(3 * ValidIndex(X, Z)) + 2] = g_ShadeField[ValidIndex(X, Z)];
		}
	}

	if(ExportExtension == 0)
	{
		GTEXTURESYS->SaveTexture("ShadeMap_C.bmp",  g_ShadeMap);
	}
	else
	{
		GTEXTURESYS->SaveTexture("ShadeMap_C.tga",  g_ShadeMap);
	}
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_RenderMap(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XAPI Xvoid XAPISTD HeightMap_RenderMap(BSTR LowerAltitudeMap, BSTR HigherAltitudeMap, Xint MaxLowerAltitude, Xint MaxHeightAltitude, Xint ExportExtension)
{
	Xchar    LFilename[512];
	Xchar    HFilename[512];
	Xuint    PixelID1 = 0;
	Xuint    PixelID2 = 0;
	Xfloat   Height   = 0;
	Xuchar   PixelR   = 0;
	Xuchar   PixelG   = 0;
	Xuchar   PixelB   = 0;
	Xuchar   Shade    = 0;
	Xuchar   HF0      = 0;
	Xuchar   HF1      = 0;
	Xfloat   T        = 0;

	g_BlendMap.Channels = 4;
	g_BlendMap.Width    = g_HeightmapSize;
	g_BlendMap.Height   = g_HeightmapSize;

	sprintf(LFilename, "%s", LowerAltitudeMap);
	sprintf(HFilename, "%s", HigherAltitudeMap);
	XTEXTURE LAltitude = GTEXTURESYS->CreateTexture(LFilename);
	XTEXTURE HAltitude = GTEXTURESYS->CreateTexture(HFilename);

	if(LAltitude.Width != g_HeightmapSize || HAltitude.Width != g_HeightmapSize)
	{
		MessageBox(NULL, "Textures must be the same size as the height map.", "[ERROR]", MB_OK);
		return;
	}

	for(Xuint X = 0; X < g_HeightmapSize; X++)
	{
		for(Xuint Z = 0; Z < g_HeightmapSize; Z++)
		{
			PixelID1 = 3 * ValidIndex(X, Z);
			PixelID2 = 4 * ValidIndex(X, Z);
			Height	 = HeightMap_GetHeightPoint(X, Z);

			if(Height > 0 && Height < MaxLowerAltitude)
			{
				PixelR = LAltitude.Data[PixelID1 + 0];
				PixelG = LAltitude.Data[PixelID1 + 1];
				PixelB = LAltitude.Data[PixelID1 + 2];
			}
			else if(Height > MaxLowerAltitude && Height < (MaxHeightAltitude - 1))
			{
				HF0    = LAltitude.Data[PixelID1 + 0];
				HF1    = HAltitude.Data[PixelID1 + 0];
				PixelR = HF0 + 0.3f * (HF1 - HF0);

				HF0    = LAltitude.Data[PixelID1 + 1];
				HF1    = HAltitude.Data[PixelID1 + 1];
				PixelG = HF0 + 0.3f * (HF1 - HF0);

				HF0    = LAltitude.Data[PixelID1 + 2];
				HF1    = HAltitude.Data[PixelID1 + 2];
				PixelB = HF0 + 0.3f * (HF1 - HF0);
			}
			else if(Height > (MaxHeightAltitude - 1) && Height < MaxHeightAltitude)
			{
				HF0    = HAltitude.Data[PixelID1 + 0];
				HF1    = LAltitude.Data[PixelID1 + 0];
				PixelR = HF0 + 0.5f * (HF1 - HF0);

				HF0    = HAltitude.Data[PixelID1 + 1];
				HF1    = LAltitude.Data[PixelID1 + 1];
				PixelG = HF0 + 0.5f * (HF1 - HF0);

				HF0    = HAltitude.Data[PixelID1 + 2];
				HF1    = LAltitude.Data[PixelID1 + 2];
				PixelB = HF0 + 0.5f * (HF1 - HF0);
			}
			else
			{
				PixelR = HAltitude.Data[PixelID1 + 0];
				PixelG = HAltitude.Data[PixelID1 + 1];
				PixelB = HAltitude.Data[PixelID1 + 2];
			}

			g_BlendMap.Data[PixelID2 + 0] = PixelR;
			g_BlendMap.Data[PixelID2 + 1] = PixelG;
			g_BlendMap.Data[PixelID2 + 2] = PixelB;
			g_BlendMap.Data[PixelID2 + 3] = 255;
		}
	}

	if(ExportExtension == 0)
	{
		GTEXTURESYS->SaveTexture("BlendMap_C.bmp", g_BlendMap);
	}
	else
	{
		GTEXTURESYS->SaveTexture("BlendMap_C.tga", g_BlendMap);
	}

	g_BlendCalculated = Xtrue;
}

//------------------------------------------------------------------------------------------------
//--
//--HeightMap_BlendWithShadeMap(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XAPI Xvoid XAPISTD HeightMap_BlendWithShadeMap(Xfloat Amount, Xint ExportExtension)
{
	if(!g_BlendCalculated || !g_ShadeCalculated)
	{
		return;
	}

	Xuchar* BlendField = (Xuchar*)malloc(g_HeightmapSize * g_HeightmapSize * 4);
	if(BlendField == NULL)
	{
		return;
	}

	Xuchar PixelR = 0;
	Xuchar PixelG = 0;
	Xuchar PixelB = 0;
	Xuchar HF0    = 0;
	Xuchar HF1    = 0;

	Amount = (Amount < 0.0f ? 0.0f : Amount);
	Amount = (Amount > 1.0f ? 1.0f : Amount);

	for(Xfloat Z = 0.0f; Z < g_HeightmapSize; Z++)
	{
		for(Xfloat X = 0.0f; X < g_HeightmapSize; X++)
		{
			HF0    = g_ShadeMap.Data [(3 * ValidIndex(X, Z)) + 0];
			HF1    = g_BlendMap.Data[(4 * ValidIndex(X, Z)) + 0];
			PixelR = HF0 + Amount * (HF1 - HF0);

			HF0    = g_ShadeMap.Data [(3 * ValidIndex(X, Z)) + 1];
			HF1    = g_BlendMap.Data[(4 * ValidIndex(X, Z)) + 1];
			PixelG = HF0 + Amount * (HF1 - HF0);

			HF0    = g_ShadeMap.Data [(3 * ValidIndex(X, Z)) + 2];
			HF1    = g_BlendMap.Data[(4 * ValidIndex(X, Z)) + 2];
			PixelB = HF0 + Amount * (HF1 - HF0);

			BlendField[4 * ValidIndex(X, Z) + 0] = PixelB;
			BlendField[4 * ValidIndex(X, Z) + 1] = PixelG;
			BlendField[4 * ValidIndex(X, Z) + 2] = PixelR;
			BlendField[4 * ValidIndex(X, Z) + 3] = 255;
		}
	}

	free(g_BlendMap.Data);
	g_BlendMap.Data = (Xuchar*)malloc(g_HeightmapSize * g_HeightmapSize * 4 * sizeof(Xuchar));
	memcpy(g_BlendMap.Data, BlendField, (g_HeightmapSize * g_HeightmapSize * 4 * sizeof(Xuchar)));

	if(BlendField)
	{
		free(BlendField);
	}

	if(ExportExtension == 0)
	{
		GTEXTURESYS->SaveTexture("ShadedBlendMap_C.bmp", g_BlendMap);
	}
	else
	{
		GTEXTURESYS->SaveTexture("ShadedBlendMap_C.tga", g_BlendMap);
	}
}