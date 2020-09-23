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
//::|сс| FILENAME	   :: Xstring.cpp													  |сс|::
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

#include "XString.h"

//------------------------------------------------------------------------------------------------
//--
//--Xstring(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring::Xstring()
{
	STRING = new Xchar[1];
    STRING[0] = '\0';
}

//------------------------------------------------------------------------------------------------
//--
//--Xstring(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring::Xstring(const Xcrptr STR)
{
	if(!STR || strlen(STR) == 0)
	{
		STRING = new Xchar[1];
		STRING[0] = '\0';
	}
	else
	{
		STRING = new Xchar[strlen(STR) + 1];
		strcpy(STRING, STR);
	}
}

//------------------------------------------------------------------------------------------------
//--
//--Xstring(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring::Xstring(const Xstring& STR)
{
	STRING = NULL;
	*this  = STR;
}

//------------------------------------------------------------------------------------------------
//--
//--~Xstring(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring::~Xstring()
{
	Xdeletea(STRING);
}

//------------------------------------------------------------------------------------------------
//--
//--operator const Xcrptr(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring::operator const Xcrptr(Xvoid) const
{
	return STRING;
}

//------------------------------------------------------------------------------------------------
//--
//--operator Xuint(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring::operator const Xuint(Xvoid) const
{
	return strlen(STRING);
}

//------------------------------------------------------------------------------------------------
//--
//--operator=(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::operator=(const Xcrptr STR)
{
	Xdeletea(STRING);
	STRING = new Xchar[strlen(STR) + 1];
	strcpy(STRING, STR);
	return *this;
}

//------------------------------------------------------------------------------------------------
//--
//--operator=(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::operator=(const Xstring& STR)
{
	Xdeletea(STRING);
	STRING = new Xchar[strlen(STR.AsChar()) + 1];
	strcpy(STRING, STR.AsChar());
	return *this;
}

//------------------------------------------------------------------------------------------------
//--
//--operator==(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xbool Xstring::operator==(const Xcrptr STR) const
{
	return ((strlen(STRING) == strlen(STR)) && (strcmp(STRING, STR) == 0));
}

//------------------------------------------------------------------------------------------------
//--
//--operator==(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xbool Xstring::operator==(const Xstring& STR) const
{
	return ((strlen(STRING) == strlen(STR.AsChar())) && (strcmp(STRING, STR.AsChar()) == 0));
}

//------------------------------------------------------------------------------------------------
//--
//--operator!=(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xbool Xstring::operator!=(const Xcrptr STR) const
{
	return ((strlen(STRING) != strlen(STR)) && (strcmp(STRING, STR) != 0));
}

//------------------------------------------------------------------------------------------------
//--
//--operator!=(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xbool Xstring::operator!=(const Xstring& STR) const
{
	return ((strlen(STRING) != strlen(STR.AsChar())) && (strcmp(STRING, STR.AsChar()) != 0));
}

//------------------------------------------------------------------------------------------------
//--
//--Left(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::Left(Xulong Length)
{
	if(this->Length() >= Length)
	{
		Xchar BUFFER[256];
		Xuint Position = 0;

		for(Xuint ID = 0; ID < Length; ID++)
		{
			BUFFER[Position] = STRING[ID];
			Position++;
		}
		BUFFER[Position] = '\0';
		strcpy(STRING, BUFFER);
	}

	return *this;
}

//------------------------------------------------------------------------------------------------
//--
//--Mid(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::Mid(Xulong Start, Xulong Length)
{
	if(this->Length() >= Length)
	{
		Xchar BUFFER[256];
		Xuint Position = 0;

		for(Xuint ID = Start; ID < Start + Length; ID++)
		{
			BUFFER[Position] = STRING[ID];
			Position++;
		}
		BUFFER[Position] = '\0';
		strcpy(STRING, BUFFER);
	}

	return *this;
}

//------------------------------------------------------------------------------------------------
//--
//--Right(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::Right(Xulong Length)
{
	if(this->Length() >= Length)
	{
		strcpy(STRING, &STRING[strlen(STRING) - Length]);
	}
	STRING[strlen(STRING)] = '\0';

	return *this;
}

//------------------------------------------------------------------------------------------------
//--
//--AsChar(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xcrptr Xstring::AsChar(Xvoid) const
{
	return STRING;
}

//------------------------------------------------------------------------------------------------
//--
//--Length(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xuint Xstring::Length(Xvoid) const
{
	return strlen(STRING);
}

//------------------------------------------------------------------------------------------------
//--
//--ConvertToLowerCase(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::ConvertToLowerCase(Xvoid)
{
	for(Xuint ID = 0; ID < this->Length(); ID++)
	{
		STRING[ID] = tolower(STRING[ID]);
	}
	return *this;
}

//------------------------------------------------------------------------------------------------
//--
//--ConvertToUpperCase(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::ConvertToUpperCase(Xvoid)
{
	for(Xuint ID = 0; ID < this->Length(); ID++)
	{
		STRING[ID] = toupper(STRING[ID]);
	}
	return *this;
}

//------------------------------------------------------------------------------------------------
//--
//--FormatSize(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::FormatSize(Xulong Size)
{
	static Xchar BUFFER[30];
	sprintf(BUFFER, "%d", Size);

	if(strlen(BUFFER) > 3)
	{
		memmove(&BUFFER[strlen(BUFFER) - 3], &BUFFER[strlen(BUFFER) - 4], 4);
		BUFFER[strlen(BUFFER) - 4] = ',';
	}

	if(strlen(BUFFER) > 7)
	{
		memmove(&BUFFER[strlen(BUFFER) - 7], &BUFFER[strlen(BUFFER) - 8], 8);
		BUFFER[strlen(BUFFER) - 8] = ',';
	}

	if(strlen(BUFFER) > 11)
	{
		memmove(&BUFFER[strlen(BUFFER) - 11], &BUFFER[strlen(BUFFER) - 12], 12);
		BUFFER[strlen(BUFFER) - 12] = ',';
	}

	Xdeletea(STRING);
	STRING = new Xchar[strlen(BUFFER) + 1];
	strcpy(STRING, BUFFER);
	return *this;
}

//------------------------------------------------------------------------------------------------
//--
//--CorrectMemorySize(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::CorrectMemorySize(XI64 Size)
{
	static Xchar BUFFER[30];
	BUFFER[0] = '\0';

	if(Size >= 0 && Size <= 1023)
	{
		sprintf(BUFFER, "%d bytes", Size);
	}
	else if(Size >= 1024 && Size <= 1048575)
	{
		sprintf(BUFFER, "%4.2f KB", (Xfloat)Size / 1024);
	}
	else if(Size >= 1048576 && Size <= 1073741823)
	{
		sprintf(BUFFER, "%4.2f MB", (Xfloat)Size / 1048576);
	}
	else if(Size >= 1073741824 && Size <= 1099511627775)
	{
		sprintf(BUFFER, "%4.2f GB", (Xfloat)Size / 1073741824);
	}
	else if(Size >= 1099511627776)
	{
		sprintf(BUFFER, "%4.2f TB", (Xfloat)Size / 1099511627776);
	}

	Xdeletea(STRING);
	STRING = new Xchar[strlen(BUFFER) + 1];
	strcpy(STRING, BUFFER);
	return *this;
}

//------------------------------------------------------------------------------------------------
//--
//--StripDirectory(*)
//--Version: 1.0
//--
//------------------------------------------------------------------------------------------------
Xstring& Xstring::StripDirectory(Xvoid)
{
	if(!STRING)
	{
		return *this;
	}

	Xchar BUFFER[256];
	sprintf(BUFFER, "%s", STRING);

	Xcrptr InString = strrchr(BUFFER, '\\');
	if(InString)
	{
		Xdeletea(STRING);
		STRING = new Xchar[strlen((InString + 1)) + 1];
		strcpy(STRING, (InString + 1));
		return *this;
	}

	InString = strrchr(BUFFER, '/');
	if(InString)
	{
		Xdeletea(STRING);
		STRING = new Xchar[strlen((InString + 1)) + 1];
		strcpy(STRING, (InString + 1));
		return *this;
	}

	return *this;
}
