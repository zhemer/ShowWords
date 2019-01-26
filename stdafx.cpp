/*
ShowWord foreign words trainer.
Copyright (C) 2007 Sergey Zhemerdeev <zhseal0@gmail.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "stdafx.h"
using namespace System;
using namespace System::Runtime::InteropServices;

char sBuf[BUF_SIZE], sBufCstr[BUF_SIZE], sBufSprintf1[BUF_SIZE];
CString sLoadString;



//--------------------------------------------------------------------------------------------------
char *cstr0(System::String *s)
{
	*sBufCstr = 0;
	if (s == NULL || StrCmp(s, "") == 0)
		sBufCstr;

	sprintf(sBufCstr, "%s", s);
	return sBufCstr;
}


char *cstr(System::String *s)
{
	char *str = (char *)(void *)Marshal::StringToHGlobalAnsi(s);
	strcpy(sBufCstr, str);
	Marshal::FreeHGlobal(str);
	return sBufCstr;
}



//--------------------------------------------------------------------------------------------------	
void mb1(char *format, ...)
{
	char sBuf[BUF_SIZE];
	va_list arg;

	va_start(arg, format);
    vsprintf(sBuf, format, arg);
    va_end(arg);

	MessageBoxA(NULL, sBuf, PRG_NAME, 0);
}



//--------------------------------------------------------------------------------------------------	
char *sprintf1(char *format, ...)
{
	va_list arg;

	va_start(arg, format);
    vsprintf(sBufSprintf1, format, arg);
    va_end(arg);

	return sBufSprintf1;
}



//--------------------------------------------------------------------------------------------------	
char *LoadString(int iRcId)
{
	sLoadString.LoadString(iRcId);
	return (char *)(LPCTSTR)sLoadString;
}