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
//::|��| FILENAME	   :: XHeightMap.h													  |��|::
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