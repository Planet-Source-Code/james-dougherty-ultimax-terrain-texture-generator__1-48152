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
//::|сс| FILENAME	   :: XHeightMap.h													  |сс|::
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

#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H
#include "XDefinition.h"
#include "XMathSystem.h"
#include "ComUtil.h"

struct LightParamerters
{
	XVECTOR3 Positon;
	Xfloat	 Intensity;
};

XAPI Xvoid XAPISTD HeightMap_PreLoad(BSTR Filename);
XAPI Xvoid XAPISTD HeightMap_FinalizeLoad(HDC hDC);
XAPI Xint  XAPISTD HeightMap_GetExtent(Xvoid);
XAPI Xvoid XAPISTD HeightMap_CreateRoughMap(Xint SmoothIterations, Xint ExportExtension);
XAPI Xvoid XAPISTD HeightMap_CreateShadeMap(LightParamerters* LightParam, Xint SmoothIterations, Xint ExportExtension);
XAPI Xvoid XAPISTD HeightMap_RenderMap(BSTR LowerAltitudeMap, BSTR HigherAltitudeMap, Xint MaxLowerAltitude, Xint MaxHeightAltitude, Xint ExportExtension);
XAPI Xvoid XAPISTD HeightMap_BlendWithShadeMap(Xfloat Amount, Xint ExportExtension);
XAPI Xvoid XAPISTD HeightMap_Cleanup(Xvoid);

#endif //--HEIGHTMAP_H