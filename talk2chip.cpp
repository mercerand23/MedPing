#include "talk2chip.h"
#include <stdio.h>

/* Date Last Modified:
   Fall 2010 - (tim, tyle) - updated simulations values
   02/03/2011 - (mdl)      - changed constants so more likely to change each time
 */

//using namespace std;

talk2chip::talk2chip()
{
//default ctor
}

talk2chip::~talk2chip()
{
//default dtor
}

double talk2chip::getTemp_F(time_t last_checked, double last_temp)
{
	time_t now;
	time(&now);
	/*double const three_hours_in_seconds = 10800; //three hours in seconds
	double const point_1 = .1; //talk2chip.h and all caps*/
	double temp = 0;
	
	
	if (last_checked == NOT_CHECKED_YET || difftime(now, last_checked) > THREE_HOURS_IN_SECONDS)
	{
		double range = mp_SIM_HIGH_TEMP_F - mp_SIM_LOW_TEMP_F;
		temp = mp_SIM_LOW_TEMP_F + mp_Random.RandBell(range/2);
		
		return temp;
	}
	else
	{
		int choice = mp_Random.RandInt(2); //choose a random number 0-2, 2 should be a const in all caps
		
		if (choice == 0) // 1/3 chances it will go up .1
		{
			//go up .1
			temp = last_temp + POINT_1;
		}
		else if (choice == 1) // 1/3 chances it will go down .1
		{
			//go down .1
			temp = last_temp - POINT_1; 
		}
		//else, temperature will not change (1/3 chance)
		//cout <<"returning..."<<temp<<endl;
		else
		{
			temp = last_temp;
		}
		return temp;
		
	}
	
	
}

short talk2chip::getPulse(time_t last_checked, double last_pulse)
{
	time_t now;
	time(&now);
	short beats = 0;
	
	
	if (last_checked == NOT_CHECKED_YET || difftime(now, last_checked) > FIVE_MINUTES_IN_SECONDS)
	{
		short range = mp_SIM_HIGH_PULSE_RATE_BPM - mp_SIM_LOW_PULSE_RATE_BPM;// (2)
		beats = (short) round( mp_SIM_LOW_PULSE_RATE_BPM + mp_Random.RandBell(range/2.0) );		
	    return beats;
	}
	else if(last_pulse < 35)
	{
		beats = last_pulse + TWO_BEATS;
		return beats;
	}
	else if(last_pulse >190)
	{
		beats = last_pulse - TWO_BEATS;
		return beats;
	}
	else
	{
		int choice = mp_Random.RandInt(2); 
		if (choice == 0)
		{
			beats = last_pulse + TWO_BEATS;
		}
		else if (choice == 1)
		{
			beats = last_pulse - TWO_BEATS; 
		}
		else
		{
			beats = last_pulse; //don't do anything
		}
		return beats;
			
		
	}

}


short talk2chip::getRespirationRate(time_t last_checked, double last_rate)
{
	time_t now;
	time(&now);
	short rate = 0;
	
	
	if (last_checked == NOT_CHECKED_YET || difftime(now, last_checked) > FIVE_MINUTES_IN_SECONDS)
	{
		// (1)
		short range = mp_SIM_HIGH_RESPIRATORY_RATE_BPM - mp_SIM_LOW_RESPIRATORY_RATE_BPM;
		// (2)
		rate = (short) round( mp_SIM_LOW_RESPIRATORY_RATE_BPM + mp_Random.RandBell(range/2.0) );
		
		
	    return rate;
	}
	else if(last_rate < 7)
	{
		rate = last_rate + ONE_BREATH;
		return rate;
	}
	else if(last_rate >27)
	{
		rate = last_rate - ONE_BREATH;
		return rate;
	}
	else
	{
		int choice = mp_Random.RandInt(3); 
		if (choice == 0)
		{
			rate = last_rate + ONE_BREATH;
		}
		else if (choice == 1)
		{
			rate = last_rate - ONE_BREATH; 
		}
		else
		{
			rate = last_rate; //don't do anything
		}
		return rate;
		
		
	}
	
	
	
}

void talk2chip::getBloodPressure(time_t last_checked, short& last_systolic, short& last_diastolic)
{
	time_t now;
	time(&now);
	short systolic = 0;
	short diastolic = 0;
	
	if (last_checked == NOT_CHECKED_YET || difftime(now, last_checked) > FIVE_MINUTES_IN_SECONDS)
	{
		short range = mp_SIM_HIGH_SYSTOLIC_mmHg - mp_SIM_LOW_SYSTOLIC_mmHg;
		// (2)
		systolic = (short) round( mp_SIM_LOW_SYSTOLIC_mmHg + mp_Random.RandBell(range/2.0) );
		
		// diastolic
		// (1)
		range = mp_SIM_HIGH_DIASTOLIC_mmHg - mp_SIM_LOW_DIASTOLIC_mmHg;
		// (2)
		diastolic = (short) round( mp_SIM_LOW_DIASTOLIC_mmHg + mp_Random.RandBell(range/2.0) );
		
		last_systolic = systolic;
		last_diastolic = diastolic;
		
	}
	else
	{
		int choice = mp_Random.RandInt(1); 
		if (choice == 0)
		{
			last_systolic = last_systolic + ONE_MM_HG;
			last_diastolic = last_diastolic + ONE_MM_HG;
		}
		else if (choice == 1)
		{
			last_systolic = last_systolic - ONE_MM_HG;
			last_diastolic = last_diastolic - ONE_MM_HG;
		}
		
		
	}
	
	
	
}


short talk2chip::getGlucoseLevel(time_t last_checked, short last_level, bool IS_A_DIABETIC)
{
	time_t now;
	time(&now);
	short glucose = 0;
	
	if(IS_A_DIABETIC)
	{
		if (last_checked == NOT_CHECKED_YET )//|| difftime(now, last_checked) > FIVE_MINUTES_IN_SECONDS
		{
			int range = mp_High_Diabetic - mp_Low_Diabetic;
		
			//all other good stuff
			glucose = (short) round( mp_SIM_Low_NonDiabetic + mp_Random.RandBell(range/2.0) );
			return glucose;
		
		}
		else
		{
			int choice = mp_Random.RandInt(2); 
			if (choice == 0)
			{
				glucose = last_level + TWO_mg_dL;
			}
			else if (choice == 1)
			{
				glucose = last_level - TWO_mg_dL; 
			}
			else
			{
				glucose = last_level; //don't do anything
			}
			return glucose;
		
		}
	}//if diabetic
	else // not a diabetic
	{
		if (last_checked == NOT_CHECKED_YET ) //|| difftime(now, last_checked) > FIVE_MINUTES_IN_SECONDS
			
		{
			int range = mp_High_NonDiabetic - mp_Low_NonDiabetic;
			
			// all other good stuff
			glucose = (short) round( mp_SIM_Low_NonDiabetic + mp_Random.RandBell(range/2.0) );
			return glucose;
			
			
		}
		else
		{
			int choice = mp_Random.RandInt(2); 
			if (choice == 0)
			{
				glucose = last_level + TWO_mg_dL;
			}
			else if (choice == 1)
			{
				glucose = last_level - TWO_mg_dL; 
			}
			else
			{
				glucose = last_level; //don't do anything
			}
			return glucose;
			
			
		}
		
		
	}

	
}

