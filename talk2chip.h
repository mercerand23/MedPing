#ifndef _MP_CHIP
#define _MP_CHIP

#include <time.h>
#include "randomBell.h"
#include "mp_normalVitalSigns.h"
#include <math.h>

//using namespace std;


class talk2chip
{

	public: 
		   talk2chip();						//CTOR
		  ~talk2chip();						//DTOR
	
		   double getTemp_F(time_t, double);
		   short  getPulse(time_t, double);
	       short  getRespirationRate(time_t, double);
		   void   getBloodPressure (time_t, short&, short&);
		   short  getGlucoseLevel(time_t,short,bool);
		   
	private:
			RandGen		mp_Random;			// local random number generator
			
};


double const  THREE_HOURS_IN_SECONDS = 10800; //10800; 
double const FIVE_MINUTES_IN_SECONDS = 300;

double const                 POINT_1 = .1;    //.1
double const         NOT_CHECKED_YET = -1;    //-1

double const TWO_BEATS  = 2;
double const ONE_BREATH = 1;
short  const ONE_MM_HG  = 1;
short  const TWO_mg_dL  = 2;
#endif
