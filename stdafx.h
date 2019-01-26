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

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>

// TODO: reference additional headers your program requires here
#include <windows.h>
#include <atlstr.h>
#undef MessageBox
#undef GetObject
#include "resource.h"

#define PRG_NAME "ShowWords"
#define PRG_VER "0.1.2"
#define PRG_AUTHOR "Sergey Zhemerdeev"
#define PRG_EMAIL "zhseal0@gmail.com"
#define PRG_URL "http://hymn.okclub.org/tmp/"

#define BUF_SIZE 1024
#define FN __FUNCTION__"()"
#define mb2 MessageBox::Show
#define mb mb1
#define StrCmp String::Compare
#define RC_OK 0
#define RC_ERR 1

char *cstr(System::String *);
void mb1(char *, ...);
char *sprintf1(char *, ...);
char *LoadString(int);

extern char sBuf[BUF_SIZE];
