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
//::|сс| FILENAME	   :: Xstring.h														  |сс|::
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

#ifndef  XSTRING_H
#define  XSTRING_H
#include "XDefinition.h"

class Xstring
{
private:
	//--Used to hold the main string
	Xcrptr STRING;

public:
	Xstring();
	Xstring(const Xcrptr STR);
	Xstring(const Xstring& STR);
	~Xstring();

	operator const Xuint(Xvoid)  const;			   //--The length of the string
	operator const Xcrptr(Xvoid) const;			   //--The string array
	Xstring& operator=(const Xcrptr STR);		   //--Copys an array of characters
	Xstring& operator=(const Xstring& STR);		   //--Copys another string
	Xbool    operator==(const Xcrptr STR)   const; //--Checks if the string is equal to another array of characters
	Xbool    operator==(const Xstring& STR) const; //--Checks if the string is equal to another string
	Xbool    operator!=(const Xcrptr STR)   const; //--Checks if the string is not equal to another array of characters
	Xbool    operator!=(const Xstring& STR) const; //--Checks if the string is not equal to another string

	Xcrptr   AsChar(Xvoid) const;			   //--Returns the string array
	Xuint    Length(Xvoid) const;			   //--Returns the length of the string
	Xstring& Left(Xulong Length);			   //--Returns a sub string left of the origional string
											   //--EXAMPLE: "UltimaX" Left(2) will return "Ul"
	Xstring& Right(Xulong Length);			   //--Returns a sub string right of the origional string
											   //--EXAMPLE: "UltimaX" Right(2) will return "aX"
	Xstring& StripDirectory(Xvoid);			   //--Strips the directory off of a path name
											   //--EXAMPLE: "Engine/Readme.txt" will return "Readme.txt"
	Xstring& FormatSize(Xulong Size);		   //--Formats a size to a string. Adds commas to the number.
											   //--EXAMPLE: 1800 will return "1,800"
	Xstring& ConvertToLowerCase(Xvoid);		   //--Converts the string to lower case letters
	Xstring& ConvertToUpperCase(Xvoid);		   //--Converts the string to upper case letters
	Xstring& CorrectMemorySize(XI64 Size);     //--Pass in a size and it converts it to string 
											   //--with the correct size
											   //--EXAMPLE: 1800 will return "1.76 KB"
	Xstring& Mid(Xulong Start, Xulong Length); //--Returns a sub string from the specified start and length values.
											   //--EXAMPLE: "UltimaX" Mid(2, 2) will return "tima"
};

#endif //--XSTRING_H