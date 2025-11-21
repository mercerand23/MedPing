
#include "mp_InputOutput.h"

#include "medPing.h"




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructors (CTOR)
medPing::medPing()
{
	// The DEFAULT patient
	// (see default CTOR for mpPatient)
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
medPing::medPing(string newFirstName, string newLastName, 
				 short newAge, short newWeight,
				 char  newGender)
{
	
	patient.setFirstName(newFirstName);
	patient.setFirstName(newLastName);
	patient.setAge(newAge);
	patient.setWeight(newWeight);
	patient.setGender(newGender);
	
	
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Destructor (DTOR)
medPing::~medPing()
{
	
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// GETTERS
string medPing::getFirstName()
{
	return patient.getFirstName();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string medPing::getLastName()
{
	return patient.getLastName();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
short medPing::getAge()
{
	return patient.getAge();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
short medPing::getWeight()
{
	return patient.getWeight();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
char medPing::getGender()
{
	return patient.getGender();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Get Data FROM medPing chip

double  medPing::getBodyTemperature_F()
{
	// NORMAL RANGE:   97.8 - 99.0F	
	// (1) determine range of temps to emulate
	// (2) assume mp_NORMALTEMP_F is center of bell-curve of 
	//            randomly generated values; offset appropriately
	// (3) shift up "slightly" to simulate more high temps
	
	// (1)
	//double range = mp_SIM_HIGH_TEMP_F - mp_SIM_LOW_TEMP_F;
	// (2)
	//double temp = mp_SIM_LOW_TEMP_F + mp_Random.RandBell(range/2);
	// (3)
	//temp += 0.25;
	

	double temp = chip.getTemp_F (  
							
							patient.getDateLastCheck_bodyTemp_F(), patient.getBodyTemperature_F()  );
	
	time_t now;
	time(&now);
	// when did we get this temp?
	(this->patient).setTimeBodyTemp(now);

	// set patient's new value
	(this->patient).setBodyTemperature_F(temp);
	
	return temp;
	
} // getBodyTemperature()


short medPing::getPulseRate_BPM()			
{
	// NORMAL RANGE:   60 - 100 beats per minute
	// (1) determine range of beats to emulate
	// (2) simulate more values near center of range; offset appropriately
	
	// (1)
	// (2)
	time_t now;
	time(&now);

	short beats = chip.getPulse(patient.getDateLastCheck_pulseRate(), patient.getPulseRate_BPM() );  
								
	// set patient's new value
	(this->patient).setPulseRate_BPM(beats);
	(this->patient).setTimePulseRate(now);
	
	return beats;
	
} // getPulseRate()


short medPing::getRespirationRate_BPM()	
{
	// NORMAL RANGE:   15 - 20 breaths per minute (bpm)
	// (1) determine range of breaths to emulate
	// (2) simulate more values near center of range; offset appropriately
	time_t now;
	time(&now);
	
	
	short breaths = chip.getRespirationRate(patient.getDateLastCheck_respirationRate(), patient.getRespirationRate_BPM() );  
	
	// set patient's new value
	(this->patient).setRespirationRate_BPM(breaths);
	(this->patient).setTimeRespirationRate(now);
	
	

	
	
	return breaths;
	
} // getRespirationRate()


void	medPing::getBloodPressure_mmHg(short& systolic, short& diastolic)
{
	// NORMAL RANGE:  systolic  90 - 140 mm Hg (millimeters of Mercury)
	//                diastolic 60 -  90 mm Hg
	
	// for both systolic and diastolic
	// (1) determine range of blood pressure to emulate
	// (2) simulate more values near center of range; offset appropriately
	
	// systolic
	// (1)
	time_t now;
	time(&now);
	
	systolic = patient.getBloodPressure_mmHg_systolic();
	diastolic = patient.getBloodPressure_mmHg_diastolic();	
	chip.getBloodPressure(patient.getDateLastCheck_BloodPressure(), systolic , diastolic);
	
	// set patient's new values
	patient.setBloodPressure_mmHg_systolic(systolic);
	patient.setBloodPressure_mmHg_diastolic(diastolic);
	(this->patient).setTimeBloodPressure(now);
	
} // getBloodPressure()


short medPing::getGlucoseLevel_mgdL()
{
	
			
	
	time_t now;
	time(&now);
	
	short level = chip.getGlucoseLevel(patient.getDateLastCheck_GlucoseLevel(), patient.getGlucoseLevel_mgdL(), patient.getIS_A_DIABETIC() );  
	
	
	(this->patient).setGlucoseLevel_mgdL(level);
	(this->patient).setTimeGlucoseLevel(now);
	
	
	return level;
	
	
	
}
 


// getGlucoseLevel()
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SETTERS
void medPing::setFirstName(string newFirstName)
{
	patient.setFirstName(newFirstName);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setLastName(string newLastName)
{
	patient.setLastName(newLastName);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setAge(short newAge)
{
	patient.setAge(newAge);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setWeight(short newWeight)
{
	patient.setWeight(newWeight);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setGender(char newGender)
{
	patient.setGender(newGender);
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// PRIVATE -- only set internally by latest reading from chip
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setBodyTemperature_F(double temp)
{
	patient.setBodyTemperature_F(temp);
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setPulseRate_BPM(short rate)
{
	patient.setPulseRate_BPM(rate);
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setRespirationRate_BPM(short rate)
{
	patient.setRespirationRate_BPM(rate);
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setBloodPressure_mmHg_systolic(short systolic)
{
	patient.setBloodPressure_mmHg_systolic(systolic);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setBloodPressure_mmHg_diastolic(short dia)
{
	patient.setBloodPressure_mmHg_diastolic(dia);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void medPing::setGlucoseLevel_mgdL(short level)
{
	patient.setGlucoseLevel_mgdL(level);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Send message TO cellphone 
void medPing::CELL_PrintF(const char* fmt, ...)
{
	va_list arg_ptr;
	va_start(arg_ptr, fmt);
	IO_PrintF(fmt, arg_ptr);
	va_end(arg_ptr);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Get Data FROM cellphone
void medPing::CELL_fetchTextString(string& textMessage)
{
	IO_loadTextMessage(textMessage);
}


long medPing::CELL_fetchInteger()
{
	long value;
	value = IO_getInteger();
	return value;
}


double medPing::CELL_fetchReal()
{
	double value;
	value = IO_getReal();
	return value;
}

