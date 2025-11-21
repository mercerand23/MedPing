
#ifndef _PATIENT_H
#define _PATIENT_H
/*
 *  mp_Patient.h
 *  TemplateFor115
 *
 *  Created by mleblanc on 12/17/08.
 *  Copyright 2008 medPing. All rights reserved.
 *
 */

// libraries needed
#include <string>
#include <iostream>
#include "randomBell.h"

// enable access to all names in std
using namespace std;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class mpPatient
{
  public:
	// Constructors (CTOR)
	mpPatient();		
	mpPatient(string newFirstName, string newLastName, 
			  short newAge, short newWeight,
			  char  newGender);
	mpPatient(const mpPatient& newPatient);
	
	// Destructor (DTOR)
	~mpPatient();
	
	// --------- Get info on patient -----------------------
	string  getFirstName();
	string  getLastName();
	short   getAge();
	short   getWeight();
	char    getGender();
	
	// vitals
	double	getBodyTemperature_F();
	short	getPulseRate_BPM();
	short	getRespirationRate_BPM();
	short	getBloodPressure_mmHg_systolic();
	short	getBloodPressure_mmHg_diastolic();
	short	getGlucoseLevel_mgdL();
	bool    getIS_A_DIABETIC();
	
	time_t  getDateLastCheck_bodyTemp_F();
	time_t  getDateLastCheck_pulseRate();
	time_t  getDateLastCheck_respirationRate();
	time_t  getDateLastCheck_BloodPressure();
	time_t  getDateLastCheck_GlucoseLevel();
	
	
	// --------- Set info on patient -----------------------
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setAge(short newAge);
	void setWeight(short newWeight);
	void setGender(char newGender);
	void setTimeBodyTemp(time_t);
	void setTimePulseRate(time_t);
	void setTimeRespirationRate(time_t);
	void setTimeBloodPressure(time_t);
	void setTimeGlucoseLevel(time_t);
	
	// vitals
	void setBodyTemperature_F(double temp);
	void setPulseRate_BPM(short rate);
	void setRespirationRate_BPM(short rate);
	void setBloodPressure_mmHg_systolic(short sys);
	void setBloodPressure_mmHg_diastolic(short dia);
	void setGlucoseLevel_mgdL(short level);
	
	
  private:
	string		mp_firstName;
	string		mp_lastName; 
	short		mp_age;
	short		mp_weight;
	char		mp_gender;
	
	// vitals
	double		mp_bodyTemp_F;
	time_t		mp_dateLastCheck_bodyTemp_F;
	
	short		mp_pulseRate;
	time_t		mp_dateLastCheck_pulseRate;

	short		mp_respiratoryRate;
	time_t		mp_dateLastCheck_RespirationRate;
	
	
	
	short		mp_BP_systolic;
	short		mp_BP_diastolic;
	time_t		mp_dateLastCheck_BloodPressure;
	
	short		mp_Glucose_Level;
	short		mp_dateLastCheck_GlucoseLevel;
	bool		IS_A_DIABETIC;
	
}; // class myPatient
	
	
	
#endif	
