#ifndef _MYRAND_H
#define _MYRAND_H

#include <limits.h>                     // for INT_MAX

// designed for implementation independent randomization
// if all system dependent calls included in this class, then
// other classes can make use of this class in independent manner
//
// all random numbers are uniformly distributed in given range
//
// RandGen() ---      constructor sets seed of random # generator
//                    once per program, not per class/object
//     
// RandInt(int max)
// RandInt(int low,int max) - return random integer in range [0..max)
//                     when one parameter used, [low..max] when
//                     two parameters used
//
//       examples:    rnd.RandInt(6) is random integer [0..5] or [0..6)
//                    rnd.RandInt(3,10) is random integer [3..10]
//                    rnd.RandInt()  is random integer [0..INT_MAX)
//
// RandReal()       -- returns random double in range [0..1)
// RandReal(double low, double max) 
//                  -- returns random double in range [low..max)
// RandBell(double average)  -- returns random double in range [0..high value)

//					--returned values are normall distributed with mean "average"

//					--and standard deviation .25*average
// comment out line below if bool is built-in
// #include "bool.h"

class RandGen
	{
	public:
		RandGen();                          // set seed for all instances
		int RandInt(int max = INT_MAX);     // returns int in [0..max)
		int RandInt(int low, int max);      // returns int in [low..max]
		double RandReal();                  // returns double in [0..1)
		double RandReal(double low, double max); // range [low..max]
		double RandBell(double average);	//returns normal on [0..high value)
		
	private:
		static int ourInitialized;          // for 'per-class' initialization
	};

#endif    // _MYRAND_H not defined