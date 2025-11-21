/*
 *  mp_Patient.cpp
 *  TemplateFor115
 *
 *  Created by mleblanc on 12/17/08.
 *  Copyright 2008 medPing. All rights reserved.
 *
 */

#include "mpPatient.h"


mpPatient::mpPatient()
{
	// The DEFAULT patient
	setFirstName("Foo");
	setLastName("Bar");
	setAge(20);
	setWeight(165);
	setGender('f');
	
	// vitals
	setBodyTemperature_F(0.0);
	setPulseRate_BPM(0);
	setRespirationRate_BPM(0);
	setBloodPressure_mmHg_systolic(0);
	setBloodPressure_mmHg_diastolic(0);
	setGlucoseLevel_mgdL(0);
	mp_dateLastCheck_bodyTemp_F = -1;
	mp_dateLastCheck_RespirationRate = -1;
	mp_dateLastCheck_pulseRate = -1;
	mp_dateLastCheck_BloodPressure = -1;
	mp_dateLastCheck_GlucoseLevel = -1;
	
	RandGen R;
	
	int ten_percent = 10;

	int rand = R.RandInt(99);
	
	if(rand < ten_percent) 
	{// one in 10 adults have diabetes*/
		IS_A_DIABETIC = true;
	}
	else
	{
		IS_A_DIABETIC = false;
	}

	
	
	
	
	
}

mpPatient::mpPatient(string newFirstName, string newLastName, 
		  short newAge, short newWeight,
		  char  newGender)
{
	setFirstName(newFirstName);
	setLastName(newLastName);
	setAge(newAge);
	setWeight(newWeight);
	setGender(newGender);
	
	// vitals
	setBodyTemperature_F(0.0);
	setPulseRate_BPM(0);
	setRespirationRate_BPM(0);
	setBloodPressure_mmHg_systolic(0);
	setBloodPressure_mmHg_diastolic(0);
	setGlucoseLevel_mgdL(0);
	mp_dateLastCheck_bodyTemp_F = -1;
}

mpPatient::mpPatient(const mpPatient& newPatient)
{
	*this = newPatient;
	mp_dateLastCheck_bodyTemp_F = -1;
}

// Destructor (DTOR)
mpPatient::~mpPatient()
{
	// nothing to do ...
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string mpPatient::getFirstName()
{
	return mp_firstName;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string mpPatient::getLastName()
{
	return mp_lastName;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
short mpPatient::getAge()
{
	return mp_age;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
short mpPatient::getWeight()
{
	return mp_weight;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
char mpPatient::getGender()
{
	return mp_gender;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vitals
double mpPatient::getBodyTemperature_F()
{
	return mp_bodyTemp_F;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
short mpPatient::getPulseRate_BPM()
{
	return mp_pulseRate;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
short mpPatient::getRespirationRate_BPM()
{
	return mp_respiratoryRate;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
short mpPatient::getBloodPressure_mmHg_systolic()
{
	return mp_BP_systolic;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
short mpPatient::getBloodPressure_mmHg_diastolic()
{
	return mp_BP_diastolic;
}
short mpPatient::getGlucoseLevel_mgdL()
{
	return mp_Glucose_Level;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SETTERS
void mpPatient::setFirstName(string newFirstName)
{
	mp_firstName = newFirstName;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mpPatient::setLastName(string newLastName)
{
	mp_lastName = newLastName;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mpPatient::setAge(short newAge)
{
	mp_age = newAge;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mpPatient::setWeight(short newWeight)
{
	mp_weight = newWeight;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mpPatient::setGender(char newGender)
{
	mp_gender = newGender;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vitals
void mpPatient::setBodyTemperature_F(double temp)
{
	mp_bodyTemp_F = temp;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mpPatient::setPulseRate_BPM(short rate)
{
	mp_pulseRate = rate;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mpPatient::setRespirationRate_BPM(short rate)
{
	mp_respiratoryRate = rate;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mpPatient::setBloodPressure_mmHg_systolic(short sys)
{
	mp_BP_systolic = sys;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mpPatient::setBloodPressure_mmHg_diastolic(short dia)
{
	mp_BP_diastolic = dia;
}

void mpPatient::setGlucoseLevel_mgdL(short level)
{
	mp_Glucose_Level = level;
}

void mpPatient::setTimeBodyTemp(time_t now)
{
	mp_dateLastCheck_bodyTemp_F = now;
}

time_t mpPatient::getDateLastCheck_bodyTemp_F()
{
	return mp_dateLastCheck_bodyTemp_F;
}

time_t mpPatient::getDateLastCheck_pulseRate()
{
	return mp_dateLastCheck_pulseRate;
}

void mpPatient::setTimePulseRate(time_t now)
{
	mp_dateLastCheck_pulseRate = now;
}

time_t mpPatient::getDateLastCheck_respirationRate()
{
	return mp_dateLastCheck_RespirationRate;
}

void mpPatient::setTimeRespirationRate(time_t now)
{
	mp_dateLastCheck_RespirationRate = now;
}

time_t mpPatient::getDateLastCheck_BloodPressure()
{
	return mp_dateLastCheck_BloodPressure;
}

void mpPatient::setTimeBloodPressure(time_t now)
{
	mp_dateLastCheck_BloodPressure = now;
}

time_t mpPatient::getDateLastCheck_GlucoseLevel()
{
	return mp_dateLastCheck_GlucoseLevel;
}

void mpPatient::setTimeGlucoseLevel(time_t now)
{
	mp_dateLastCheck_GlucoseLevel = now;
}
bool mpPatient::getIS_A_DIABETIC()
{
	return IS_A_DIABETIC;
}

