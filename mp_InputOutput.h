//
//  mp_InputOutput.h
//  TemplateFor115
//
//  Created by mleblanc on 12/16/08.
//  Copyright 2008 medPing. All rights reserved.
//


#include <stdarg.h>
#include <string>

using namespace std;

extern "C" int medPing_Main();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Send message TO cellphone 
void IO_PrintF(const char* fmt, va_list arg_ptr);


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Get Data FROM cellphone
void   IO_loadTextMessage(string& textMessage);

long   IO_getInteger();
double IO_getReal();



