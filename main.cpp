#include "mp_InputOutput.h"
#include "medPing.h"

//================================================================
// Programmer: Andrew Mercer
//
// Summary: 
//
// Modification History:
//    12/15/08 -- (mdl) medPing lives ...
//    02/14/16 -- (mdl) fresh paint ...
//
//================================================================

// entry point for the current student work
int medPing_Main();

int main (int argc, char * const argv[])
{
    // console app just calls another main() for this app
	int result;
	result = medPing_Main();
	
	return 0;
}
