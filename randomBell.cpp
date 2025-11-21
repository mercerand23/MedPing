#include <time.h>                // for time()
#include <stdlib.h>              // for rand/srand
//#include <iostream>

#include <math.h>				 // for log
#include "randomBell.h"

int RandGen::ourInitialized = 0;

RandGen::RandGen()
// postcondition: system srand() used to initialize seed
//                once per program     
{
    if (0 == ourInitialized)
    {
        ourInitialized = 1;      // only call srand once
        srand(static_cast<unsigned>(time(0)));       // randomize
		rand();
    }
}

int RandGen::RandInt(int max)
// precondition: max > 0
// postcondition: returns int in [0..max)     
{  
    return static_cast<int>(RandReal() * max);
}

int RandGen::RandInt(int low, int max)
// precondition: low <= max     
// postcondition: returns int in [low..max]     
{ 
    return low + RandInt(max-low+1);
}

double RandGen::RandReal()
// postcondition: returns double in [0..1)     
{     
    return rand() / (static_cast<double>(RAND_MAX) + 1); 
}


double RandGen::RandBell(double average)

//precondition: average<0

//postcondition: returns double in [0..high value)

//				return values are normall distributed

{
	
	double fac,r,v1,v2,value;
	
	
	
	do{
		
		v1=2.0*RandReal()-1.0;
		
		v2=2.0*RandReal()-1.0;
		
		r=v1*v1+v2*v2;
		
	}while(r>=1.0 || r==0.0);
	
	
	
	fac=sqrt(-2.0*log(r)/r);
	
	value=(average+(v1*fac)*(average*.25));
	
	if(value<0)
		
		return 0;
	
	else
		
		return value;
	
}