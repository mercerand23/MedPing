//
//  mp_InputOutput.mm
//  TemplateFor115
//
//  Created by mleblanc on 12/16/08.
//  Copyright 2008 medPing. All rights reserved.
//


#include "mp_InputOutput.h"

//---------------------------------------------------
//  =========== standard console ==================
//---------------------------------------------------

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


void IO_PrintF(const char* fmt, va_list arg_ptr)
{
	// just printf to the console
	vprintf(fmt, arg_ptr);
}


void IO_loadTextMessage(string& textMessage)
{
	getline(cin, textMessage);
}


long IO_getInteger()
{
	long l;
	cin >> l;
	
	return l;	
}

double IO_getReal()
{
	double d;
	cin >> d;
	
	return d;
}

