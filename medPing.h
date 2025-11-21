#ifndef _MEDPING_H
#define _MEDPING_H


//===============================================================
// API (Application Programming Interface) for medPing
//===============================================================

//===============================================================
// History:
//
// December 10, 2008	-- ken aspeslagh '2000 mocks up the
//							details needed to do the Obj-C
//
// December 12, 2008	-- mdl and neil kathok '10 modify API
//
// December 15, 2008    -- mdl added bell.h/bell.cpp class to
//                          generate random bell-curve values
//===============================================================

// libraries needed
#include <string>
#include <iostream>
#include <cstdlib>
#include <math.h>

#include "mp_InputOutput.h"
#include "mp_normalVitalSigns.h"
#include "mpPatient.h"
#include "randomBell.h"
#include "talk2chip.h"





// enable access to all names in std
using namespace std;

// entry point for the current student work
//int medPing_Main();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class medPing
{
  public:
	// Constructors (CTOR)
	medPing();		
	medPing(string newFirstName, string newLastName, 
			short newAge, short newWeight,
			char  newGender);
	// Destructor (DTOR)
	~medPing();
	
	
	// --------- Get info on patient -----------------------
	string getFirstName();
	string getLastName();
	short  getAge();
	short  getWeight();
	char   getGender();

	// --------- Get Data FROM medPing chip --------------------
	// (Side Effect: set this latest reading as patient's value)
	
										// NORMAL RANGES
	double  getBodyTemperature_F();		// 97.8 - 99.0 F
	
	short	getPulseRate_BPM();			// 60 - 100 beats per minute
	
	short   getRespirationRate_BPM();	// 15 - 20 breaths per minute
	
	void	getBloodPressure_mmHg(short& systolic, short& diastolic);
										// systolic  < 120 mm Hg (millimeters of Mercury)
										// diastolic <  80 mm Hg
	short	getGlucoseLevel_mgdL();
	
	// --------- Set info on patient -----------------------
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setAge(short newAge);
	void setWeight(short newWeight);
	void setGender(char newGender);
	
	
	// --------- Send message TO cellphone ---------------------
	void    CELL_PrintF(const char* fmt, ...);	// printf-style output 

	
	// --------- Get Data FROM cellphone -----------------------
	void	CELL_fetchTextString(string& textMessage);
	long	CELL_fetchInteger();
	double	CELL_fetchReal();

	

  private:
	// Private setter METHODS (called when chip is pinged for a value)
	void setBodyTemperature_F(double temp);	
	void setPulseRate_BPM(short rate);				
	void setRespirationRate_BPM(short rate);		
	void setBloodPressure_mmHg_systolic(short systolic);
	void setBloodPressure_mmHg_diastolic(short diastolic);
	void setGlucoseLevel_mgdL(short level);

	
	// DATA values
	mpPatient	patient;			// to hold patient's data
	
	talk2chip   chip;
	
}; // end class medPing

#endif
