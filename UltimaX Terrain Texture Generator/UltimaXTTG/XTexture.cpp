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
//::|сс| FILENAME	   :: XTexture.cpp													  |сс|::
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

#include "XTexture.h"
#include "XMathSystem.h"

//------------------------------------------------------------------------------------------------
//--
//--XTEXTURESYSTEM(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XTEXTURESYSTEM::XTEXTURESYSTEM(Xvoid)
{
	static Xint InitializeOneTime = 0;
	if(!InitializeOneTime)
	{
		InitializeOneTime	 = 1;
		this->m_Textures	 = NULL;
		this->m_TexturesTail = NULL;
	}

	ReleaseAllTextureNodes();
}

//------------------------------------------------------------------------------------------------
//--
//--~XTEXTURESYSTEM(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XTEXTURESYSTEM::~XTEXTURESYSTEM(Xvoid)
{
	try
	{
		//--FIX ME--//
		//--KEEPS TROWING ERROR ON EXIT--//
		ReleaseAllTextureNodes();
	}catch(...){}
}

//------------------------------------------------------------------------------------------------
//--
//--GetGBLI(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XTEXTURESYSTEM *XTEXTURESYSTEM::GetGBLI(Xvoid)
{
	static XTEXTURESYSTEM GBLI;
	return &GBLI;
}

//------------------------------------------------------------------------------------------------
//--
//--AppendTextureNode(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xvoid XTEXTURESYSTEM::AppendTextureNode(Xcrptr TextureName, XTEXTURE* TEXTURE)
{
	XTEXTURENODE* NODE = (XTEXTURENODE*)malloc(sizeof(XTEXTURENODE));
	strcpy(NODE->Name, TextureName);
	NODE->TEXTURE.Data		 = TEXTURE->Data;
	NODE->TEXTURE.Width		 = TEXTURE->Width;
	NODE->TEXTURE.Height     = TEXTURE->Height;
	NODE->TEXTURE.Channels   = TEXTURE->Channels;
	NODE->TEXTURE.GLTexture  = TEXTURE->GLTexture;
	NODE->Next				 = NULL;

	if(this->m_Textures == NULL)
	{
		this->m_Textures = this->m_TexturesTail = NODE;
	}
	else if(this->m_Textures != NULL && this->m_Textures == this->m_TexturesTail)
	{
		this->m_Textures->Next = this->m_TexturesTail = NODE;
	}
	else
	{
		this->m_TexturesTail->Next = NODE;
		this->m_TexturesTail       = NODE;
	}
}

//------------------------------------------------------------------------------------------------
//--
//--FindTextureNode(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xbool XTEXTURESYSTEM::FindTextureNode(Xcrptr TextureName, XTEXTURE& TEXTURE)
{
	while(this->m_Textures != NULL)
    {
		if(strcmp(this->m_Textures->Name, TextureName) == 0)
		{
			TEXTURE.Data	   = this->m_Textures->TEXTURE.Data;
			TEXTURE.Width	   = this->m_Textures->TEXTURE.Width;
			TEXTURE.Height     = this->m_Textures->TEXTURE.Height;
			TEXTURE.Channels   = this->m_Textures->TEXTURE.Channels;
			TEXTURE.GLTexture  = this->m_Textures->TEXTURE.GLTexture;
			return Xtrue;
		}
		this->m_Textures = this->m_Textures->Next;
	}
	return Xfalse;
}

//------------------------------------------------------------------------------------------------
//--
//--DeleteTextureNode(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xint XTEXTURESYSTEM::DeleteTextureNode(Xcrptr TextureName)
{
	if(!TextureName || this->m_Textures == NULL)
	{
		return 0;
	}

	while(this->m_Textures)
    {
		if(strcmp(this->m_Textures->Name, TextureName) == 0)
		{
			if(glIsTexture(this->m_Textures->TEXTURE.GLTexture))
			{
				glDeleteTextures(1, &this->m_Textures->TEXTURE.GLTexture);
			}

			if(this->m_Textures->TEXTURE.Data)
			{
				free(this->m_Textures->TEXTURE.Data);
			}
			return 1;
		}
		this->m_Textures = this->m_Textures->Next;
	}
	return 0;
}

//------------------------------------------------------------------------------------------------
//--
//--ReleaseAllTextureNodes(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xvoid XTEXTURESYSTEM::ReleaseAllTextureNodes(Xvoid)
{
	if(this->m_Textures == NULL)
	{
		return;
	}

	while(this->m_Textures)
	{
		if(glIsTexture(this->m_Textures->TEXTURE.GLTexture))
		{
			glDeleteTextures(1, &this->m_Textures->TEXTURE.GLTexture);
		}

		if(this->m_Textures->TEXTURE.Data)
		{
			free(this->m_Textures->TEXTURE.Data);
		}
		this->m_Textures = this->m_Textures->Next;
	}

	this->m_Textures	 = NULL;
	this->m_TexturesTail = NULL;
}

//------------------------------------------------------------------------------------------------
//--
//--LoadBMP(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE XTEXTURE *LoadBMP(Xccrptr Filename, BITMAPINFOHEADER *HeaderInfo)
{
	XTEXTURE         *Image	= NULL;
	FILE             *File  = NULL;
	BITMAPFILEHEADER  Header;
	Xuchar		      Pixel;

	File = fopen(Filename, "rb");
	if(File == NULL)
	{
		Xchar BUFFER[256];
		sprintf(BUFFER, "Unable to load the texture: %s", Filename);
		MessageBox(NULL, BUFFER, "[ERROR]", MB_OK);
		return NULL;
	}

	fread(&Header, sizeof(BITMAPFILEHEADER), 1, File);
	if(Header.bfType != 0x4D42)
	{
		fclose(File);
		return NULL;
	}
	
	Image = (XTEXTURE*)malloc(sizeof(XTEXTURE));
	if(Image == NULL)
	{
		free(Image);
		fclose(File);
		return NULL;
	}

	fread(HeaderInfo, sizeof(BITMAPINFOHEADER), 1, File);
	fseek(File, Header.bfOffBits, SEEK_SET);
	Image->Data = (Xuchar*)malloc(HeaderInfo->biSizeImage * 3);
	if(!Image->Data)
	{
		free(Image->Data);
		fclose(File);
		return NULL;
	}

	fread(Image->Data, 1, HeaderInfo->biSizeImage, File);
	if(Image->Data == NULL)
	{
		fclose(File);
		return NULL;
	}

	for(Xulong PixelID = 0; PixelID < HeaderInfo->biSizeImage; PixelID += 3)
	{
		Pixel = Image->Data[PixelID];
		Image->Data[PixelID + 0] = Image->Data[PixelID + 2];
		Image->Data[PixelID + 2] = Pixel;
	}

	Image->Channels = 3;
	Image->Width    = HeaderInfo->biWidth;
	Image->Height   = HeaderInfo->biHeight;
	fclose(File);
	return Image;
}

//------------------------------------------------------------------------------------------------
//--
//--SaveBMP(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE Xvoid SaveBMP(Xcrptr FileName, Xint Width, Xint Height, Xint Channels, Xuchar *PixelData)
{
	BITMAPINFOHEADER HeaderInformation;
	BITMAPFILEHEADER Header;
	Xuchar		     Pixel;

	FILE *File = fopen(FileName, "wb");
	if(File == NULL)
	{
		return;
	}

	Xint BitDepth = 0;
	if(Channels == 3)
	{
		BitDepth = 24;
	}
	else
	{
		BitDepth = 32;
	}

	Header.bfSize = sizeof(BITMAPFILEHEADER);
	Header.bfType = 0x4D42;
	Header.bfReserved1 = 0;
	Header.bfReserved2 = 0;
	Header.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	HeaderInformation.biSize = sizeof(BITMAPINFOHEADER);
	HeaderInformation.biPlanes = 1;
	HeaderInformation.biClrUsed = 0;
	HeaderInformation.biWidth = Width;
	HeaderInformation.biHeight = Height;
	HeaderInformation.biClrImportant = 0;
	HeaderInformation.biXPelsPerMeter = 0;
	HeaderInformation.biYPelsPerMeter = 0;
	HeaderInformation.biBitCount = BitDepth;
	HeaderInformation.biCompression = BI_RGB;
	HeaderInformation.biSizeImage = Width * Height * Channels;
	
	for(Xulong PixelID = 0; PixelID < HeaderInformation.biSizeImage; PixelID += Channels)
	{
		Pixel = PixelData[PixelID];
		PixelData[PixelID + 0] = PixelData[PixelID + 2];
		PixelData[PixelID + 2] = Pixel;
	}
	
	fwrite(&Header, 1, sizeof(BITMAPFILEHEADER), File);
	fwrite(&HeaderInformation, 1, sizeof(BITMAPINFOHEADER), File);
	fwrite(PixelData, 1, HeaderInformation.biSizeImage, File);
	fclose(File);
}

//------------------------------------------------------------------------------------------------
//--
//--LoadTGA(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE XTEXTURE *LoadTGA(Xccrptr Filename)
{
	XTEXTURE *Image = NULL;
	FILE *File		= NULL;
	Xuchar BitDepth	= 0;
	Xushort Width	= 0;
	Xushort Height	= 0;
	Xuchar Length	= 0;
	Xint Channels	= 0;
	Xuchar Pixel    = 0;
	Xuchar Type		= 0;
	Xint Stride		= 0;
	Xint i			= 0;

	if((File = fopen(Filename, "rb")) == NULL) 
	{
		Xchar BUFFER[256];
		sprintf(BUFFER, "Unable to load the texture: %s", Filename);
		MessageBox(NULL, BUFFER, "[ERROR]", MB_OK);
		return NULL;
	}

	Image = (XTEXTURE*)malloc(sizeof(XTEXTURE));
	fread(&Length, sizeof(Xuchar), 1, File);
	fseek(File,1,SEEK_CUR);
	fread(&Type, sizeof(Xuchar), 1, File);
	fseek(File, 9, SEEK_CUR);
	fread(&Width,  sizeof(Xushort), 1, File);
	fread(&Height, sizeof(Xushort), 1, File);
	fread(&BitDepth,   sizeof(Xuchar), 1, File);
	fseek(File, Length + 1, SEEK_CUR);

	if(Type != 10)
	{
		if(BitDepth == 24 || BitDepth == 32)
		{
			Channels = BitDepth >> 3;
			Stride = Channels * Width;
			Image->Data = new Xuchar[Stride * Height];

			for(Xint Y = 0; Y < Height; Y++)
			{
				Xuchar *Line = &(Image->Data[Stride * Y]);
				fread(Line, Stride, 1, File);

				for(Xint PixelID = 0; PixelID < Stride; PixelID += Channels)
				{
					Pixel = Line[PixelID];
					Line[PixelID + 0] = Line[PixelID + 2];
					Line[PixelID + 2] = Pixel;
				}
			}
		}
		else if(BitDepth == 16)
		{
			Xushort Pixels = 0;
			Xint Red   = 0,
				 Green = 0,
				 Blue  = 0;

			Channels = 3;
			Stride = Channels * Width;
			Image->Data = new Xuchar[Stride * Height];

			for(Xint PixelID = 0; PixelID < Width * Height; PixelID++)
			{
				fread(&Pixels, sizeof(Xushort), 1, File);
				Blue  = (Pixels         & 0x1f) << 3;
				Green = ((Pixels >> 5)  & 0x1f) << 3;
				Red   = ((Pixels >> 10) & 0x1f) << 3;
				
				Image->Data[PixelID * 3 + 0] = Red;
				Image->Data[PixelID * 3 + 1] = Green;
				Image->Data[PixelID * 3 + 2] = Blue;
			}
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		Xuchar ID       = 0;
		Xint ColorsRead = 0;

		Channels = BitDepth >> 3;
		Stride = Channels * Width;
		Image->Data = new Xuchar[Stride * Height];
		Xuchar *Colors = new Xuchar[Channels];

		while(i < Width * Height)
		{
			fread(&ID, sizeof(Xuchar), 1, File);
			if(ID < 128)
			{
				ID++;
				while(ID)
				{
					fread(Colors, sizeof(Xuchar) * Channels, 1, File);
					
					Image->Data[ColorsRead + 0] = Colors[2];
					Image->Data[ColorsRead + 1] = Colors[1];
					Image->Data[ColorsRead + 2] = Colors[0];

					if(BitDepth == 32){Image->Data[ColorsRead + 3] = Colors[3];}
					i++; ID--;
					ColorsRead += Channels;
				}
			}
			else
			{
				ID -= 127;
				fread(Colors, sizeof(Xuchar) * Channels, 1, File);
				while(ID)
				{
					Image->Data[ColorsRead + 0] = Colors[2];
					Image->Data[ColorsRead + 1] = Colors[1];
					Image->Data[ColorsRead + 2] = Colors[0];

					if(BitDepth == 32){Image->Data[ColorsRead + 3] = Colors[3];}
					i++; ID--;
					ColorsRead += Channels;
				}
			}
		}
	}
	fclose(File);

	Image->Width    = Width;
	Image->Height   = Height;
	Image->Channels = Channels;
	return Image;
}

//------------------------------------------------------------------------------------------------
//--
//--SaveTGA(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE Xvoid SaveTGA(Xcrptr FileName, Xint Width, Xint Height, Xint Channels, Xuchar *PixelData)
{
	Xuchar  BitDepth = 0;
	Xuchar  BSkip    = 0;
	Xshorti SSkip    = 0;
	Xuchar  Type     = 2;

	FILE *File = fopen(FileName, "wb");
	if(File == NULL)
	{
		fclose(File);
		return;
	}

	if(Channels == 3)
	{
		BitDepth = 24;
	}
	else
	{
		BitDepth = 32;
	}

	fwrite(&BSkip,	  sizeof(Xuchar),  1, File);
	fwrite(&BSkip,	  sizeof(Xuchar),  1, File);
	fwrite(&Type,	  sizeof(Xuchar),  1, File);
	fwrite(&SSkip,	  sizeof(Xshorti), 1, File);
	fwrite(&SSkip,	  sizeof(Xshorti), 1, File);
	fwrite(&BSkip,	  sizeof(Xuchar),  1, File);
	fwrite(&SSkip,	  sizeof(Xshorti), 1, File);
	fwrite(&SSkip,	  sizeof(Xshorti), 1, File);
	fwrite(&Width,    sizeof(Xshorti), 1, File);
	fwrite(&Height,   sizeof(Xshorti), 1, File);
	fwrite(&BitDepth, sizeof(Xuchar),  1, File);
	fwrite(&BSkip,	  sizeof(Xuchar),  1, File);
	fwrite(PixelData, sizeof(Xuchar), (Width * Height * Channels), File);
	fclose(File);
}

//------------------------------------------------------------------------------------------------
//--
//--TEXTURESIZEOK(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE Xbool TEXTURESIZEOK(Xuint Size)
{
	if(Size == 2   || Size == 4    || Size == 8    || Size == 16  ||
       Size == 32  || Size == 64   || Size == 128  || Size == 256 ||
	   Size == 512 || Size == 1024 || Size == 2048 || Size == 4096)
	{
		return Xtrue;
	}
	return Xfalse;
}

//------------------------------------------------------------------------------------------------
//--
//--GETNEARESTPOWER(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XINLINE Xuint GETNEARESTPOWER(Xuint Size)
{
	if(TEXTURESIZEOK(Size))
	{
		return Size;
	}

	Xuint Power = 0;
	while(Size)
	{
		Size /= 2;
		Power++;
	}

	return (Xuint)XMATH::Pow(2, Power - 1);
}

//------------------------------------------------------------------------------------------------
//--
//--FixTexture(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XTEXTURE& XTEXTURESYSTEM::FixTexture(XTEXTURE* Texture, Xuint* ErrorID)
{
	XTEXTURE Result;
	Xbool	 Fix = Xfalse;

	if(!TEXTURESIZEOK(Texture->Width))
	{
		Fix	= Xtrue;
		Result.Width = GETNEARESTPOWER(Texture->Width);
	}

	if(!TEXTURESIZEOK(Texture->Height))
	{
		Fix	= Xtrue;
		Result.Height = GETNEARESTPOWER(Texture->Height);
	}

	if(Fix)
	{
		Result.Channels  = Texture->Channels;
		Result.GLTexture = Texture->GLTexture;

		Xuint Format = GL_RGB;
		if(Result.Channels == 4)
		{
			Format = GL_RGBA;
		}

		if(gluScaleImage(Format, Texture->Width, Texture->Height, GL_UNSIGNED_BYTE, &Texture->Data, Result.Width, Result.Height, GL_UNSIGNED_BYTE, &Result.Data) != 0)
		{
			*ErrorID = -1;
			return (XTEXTURE&)*Texture;
		}
		
		*ErrorID = 0;
		return Result;
	}

	*ErrorID = 0;
	return (XTEXTURE&)*Texture;
}

//------------------------------------------------------------------------------------------------
//--
//--CreateTexture(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XTEXTURE& XTEXTURESYSTEM::CreateTexture(Xcrptr FileName)
{
	XTEXTURE *TEXTURE = NULL;
	XTEXTURE  ILTEXTURE;

	if(!FileName)
	{
		return (XTEXTURE&)*TEXTURE;
	}

	if(FindTextureNode(FileName, ILTEXTURE))
	{
		return ILTEXTURE;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	if(_stricmp(FileName + strlen(FileName) - 4, ".tga") == 0)
	{
		TEXTURE = LoadTGA(FileName);
		if(TEXTURE == NULL)
		{
			return (XTEXTURE&)*TEXTURE;
		}

		Xuint Format = GL_RGB;
		if(TEXTURE->Channels == 4)
		{
			Format = GL_RGBA;
		}

		glGenTextures(1, &TEXTURE->GLTexture);
		glBindTexture(GL_TEXTURE_2D, TEXTURE->GLTexture);
		gluBuild2DMipmaps(GL_TEXTURE_2D, TEXTURE->Channels, TEXTURE->Width, TEXTURE->Height, Format, GL_UNSIGNED_BYTE, TEXTURE->Data);
	}
	else if(_stricmp(FileName + strlen(FileName) - 4, ".bmp") == 0)
	{
		BITMAPINFOHEADER BHEADER;
		TEXTURE = LoadBMP(FileName, &BHEADER);
		if(TEXTURE == NULL)
		{
			return (XTEXTURE&)*TEXTURE;
		}

		glGenTextures(1, &TEXTURE->GLTexture);
		glBindTexture(GL_TEXTURE_2D, TEXTURE->GLTexture);
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, TEXTURE->Width, TEXTURE->Height, GL_RGB, GL_UNSIGNED_BYTE, TEXTURE->Data);
	}
	
	Xuint Result;
	XTEXTURE Texture = FixTexture(TEXTURE, &Result);
	if(Result == -1)
	{
		return (XTEXTURE&)*TEXTURE;
	}

	AppendTextureNode(FileName, &Texture);
	return Texture;
}

//------------------------------------------------------------------------------------------------
//--
//--CreateTexture(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
XTEXTURE& XTEXTURESYSTEM::CreateTexture(Xcrptr FileName, XTEXTURE_PARAMETERS *Parameters)
{
	XTEXTURE *TEXTURE = NULL;
	XTEXTURE  ILTEXTURE;

	if(!FileName)
	{
		return (XTEXTURE&)*TEXTURE;
	}

	if(FindTextureNode(FileName, ILTEXTURE))
	{
		return ILTEXTURE;
	}

	switch(Parameters->MinFilter)
	{
		case 0x00:
			break;

		case 0x01:
		case 0x02:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			break;

		case 0x04:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			break;
	};

	switch(Parameters->MaxFilter)
	{
		case 0x00:
			break;

		case 0x01:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			break;

		case 0x02:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
			break;

		case 0x04:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			break;
	};

	switch(Parameters->WrapMethod)
	{
		case 0x00:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
			break;

		case 0x01:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
			break;

		case 0x02:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			break;
	}

	if(_stricmp(FileName + strlen(FileName) - 4, ".tga") == 0)
	{
		TEXTURE = LoadTGA(FileName);
		if(TEXTURE == NULL)
		{
			return (XTEXTURE&)*TEXTURE;
		}

		Xuint Format = GL_RGB;
		if(TEXTURE->Channels == 4)
		{
			Format = GL_RGBA;
		}

		glGenTextures(1, &TEXTURE->GLTexture);
		glBindTexture(GL_TEXTURE_2D, TEXTURE->GLTexture);
		gluBuild2DMipmaps(GL_TEXTURE_2D, TEXTURE->Channels, TEXTURE->Width, TEXTURE->Height, Format, GL_UNSIGNED_BYTE, TEXTURE->Data);
	}
	else if(_stricmp(FileName + strlen(FileName) - 4, ".bmp") == 0)
	{
		BITMAPINFOHEADER BHEADER;
		TEXTURE = LoadBMP(FileName, &BHEADER);
		if(TEXTURE == NULL)
		{
			return (XTEXTURE&)*TEXTURE;
		}

		glGenTextures(1, &TEXTURE->GLTexture);
		glBindTexture(GL_TEXTURE_2D, TEXTURE->GLTexture);
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, TEXTURE->Width, TEXTURE->Height, GL_RGB, GL_UNSIGNED_BYTE, TEXTURE->Data);
	}

	Xuint Result;
	XTEXTURE Texture = FixTexture(TEXTURE, &Result);
	if(Result == -1)
	{
		return (XTEXTURE&)*TEXTURE;
	}

	AppendTextureNode(FileName, &Texture);
	return Texture;
}

//------------------------------------------------------------------------------------------------
//--
//--SaveTexture(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xvoid XTEXTURESYSTEM::SaveTexture(Xcrptr FileName, XTEXTURE &Texture)
{
	if(_stricmp(FileName + strlen(FileName) - 4, ".tga") == 0)
	{
		SaveTGA(FileName, Texture.Width, Texture.Height, Texture.Channels, Texture.Data);
	}
	else
	{
		SaveBMP(FileName, Texture.Width, Texture.Height, Texture.Channels, Texture.Data);
	}
}

//------------------------------------------------------------------------------------------------
//--
//--SaveTexture(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xvoid XTEXTURESYSTEM::SaveTexture(Xcrptr FileName, Xint Width, Xint Height, Xint Channels, Xuchar *PixelData)
{
	if(_stricmp(FileName + strlen(FileName) - 4, ".tga") == 0)
	{
		SaveTGA(FileName, Width, Height, Channels, PixelData);
	}
	else
	{
		SaveBMP(FileName, Width, Height, Channels, PixelData);
	}
}