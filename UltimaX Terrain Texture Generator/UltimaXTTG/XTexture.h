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
//::|сс| FILENAME	   :: XTexture.h													  |сс|::
//::|сс| VERSION	   :: 1.1															  |сс|::
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

#ifndef XTEXTURE_H
#define XTEXTURE_H
#include "XDefinition.h"

enum XTEXTUREFILTER
{
	XTEXF_NONE     = 0x00,
	XTEXF_POINT    = 0x01,
	XTEXF_LINEAR   = 0x02,
	XTEXF_NEAREST  = 0x04
};

enum XTEXTUREWRAPMODE
{
	XTEXW_CLAMP        = 0x00,
	XTEXW_CLAMPTOEDGE  = 0x01,
	XTEXW_REPEAT       = 0x02
};

struct XTEXTURE
{
	XTEXTURE() : Data(NULL),
				 Width(256),
				 Height(256),
				 Channels(3),
				 GLTexture(0){}

	Xuchar *Data;
	Xint    Width;
	Xint    Height;
	Xint    Channels;
	Xuint   GLTexture;
};

struct XTEXTURE_PARAMETERS
{
	XTEXTURE_PARAMETERS() : MinFilter(XTEXF_LINEAR),
							MaxFilter(XTEXF_LINEAR),
							WrapMethod(XTEXW_REPEAT){}

	XTEXTUREFILTER	    MinFilter;
	XTEXTUREFILTER	    MaxFilter;
	XTEXTUREWRAPMODE    WrapMethod;
};

class XTEXTURESYSTEM
{
private:

	struct XTEXTURENODE
	{
		Xchar Name[256];
		XTEXTURE TEXTURE;
		XTEXTURENODE* Next;
	};

private:
	XTEXTURENODE* m_Textures;
	XTEXTURENODE* m_TexturesTail;

protected:
	Xvoid AppendTextureNode(Xcrptr TextureName, XTEXTURE* TEXTURE);
	Xbool FindTextureNode(Xcrptr TextureName, XTEXTURE& TEXTURE);
	Xint  DeleteTextureNode(Xcrptr TextureName);
	Xvoid ReleaseAllTextureNodes(Xvoid);

public:
	XTEXTURESYSTEM();
	virtual ~XTEXTURESYSTEM();
	static XTEXTURESYSTEM *GetGBLI(Xvoid);

	XTEXTURE& CreateTexture(Xcrptr FileName);
	XTEXTURE& CreateTexture(Xcrptr FileName, XTEXTURE_PARAMETERS *Parameters);
	XTEXTURE& FixTexture(XTEXTURE* Texture, Xuint* ErrorID);
	Xvoid	  SaveTexture(Xcrptr FileName, XTEXTURE &Texture);
	Xvoid	  SaveTexture(Xcrptr FileName, Xint Width, Xint Height, Xint Channels, Xuchar *PixelData);
};

#define GTEXTURESYS XTEXTURESYSTEM::GetGBLI()

#endif //--XTEXTURE_H
