/*--------------------------------------------------------------
Programmer:		Andrew Mercer
 
Summary: Medping takes multiple shorts of vitals and places them in a struct which is then placed in an array.
Then after recieving a new record (struct) after already having 5 it will remove the oldest one
 
Date last modified: 
 08/02/2025 (mdl) - Set up StarterKit
 09/03/2025 - Set up VitalHistory Struct and AddHistory Function
 09/04/2025 - Created Find and Delete Function and fixed print function
----------------------------------------------------------------*/

/*--------------------------------------------------------------
INPUT: multiple short/long values from medping class
 
OUTPUT: an array of records (structs) with the data outputted to the phone screen
 
WINDOWS specific (if compiler C11 or earlier)
   #include <windows.h>
   // then use Sleep() function in code
   Sleep(waitThisLongSEC*1000);
---------------------------------------------------------------*/

#include "medPing.h"

#include <cassert>
#include <chrono>
#include <thread>

//-----------------------------------------------------------------------
#include <time.h>

// WINDOWS users: uncomment next line
// #include <windows.h>

const long MAX_HISTORY  = 5;	// can store upto (last) MAX_HISTORY sets of vital signs

const long MAX_WAIT_SEC = 4;	// will random pause from 1 to MAX_WAIT_SEC 

//========================================
struct oneVitalHistoryRecord
{
	long secs;
	double	bodyTemp_F;
	short	pulseRate;
	short	respiration;
	short	diastolic;
	short	systolic;
	short	glucose;

	
};
//========================================

// function prototypes for keeping track of HISTORY
// (see bottom of this file where you'll write the definitions)

void AddHistoryRecord(long nSecs,
					  double new_mp_bodyTemp_F, 
					  short  new_mp_pulseRate,

					  short new_mp_respiration,
					  short new_mp_diastolic,
					  short new_mp_systolic,
					  short new_mp_glucose,
					  
					  oneVitalHistoryRecord vitalHistory[ ],
					  long& hmr
					  );


long FindVitalRecord(long Time, oneVitalHistoryRecord vitalHistory[], long hmr);
void DeleteHistoryRecord(oneVitalHistoryRecord vitalHistory[], long recordID, long& hmr);

/*
const long NOT_FOUND = -1;  // used to indicate failure on linear search
long FindVitalRecord(...);

void DeleteHistoryRecord(oneVitalHistoryRecord vitalHistory[]);
*/

void printAllVitalRecords(medPing& mP, const oneVitalHistoryRecord vitalHistory[ ], long hmr);
// end function prototypes



//-----------------------------------------------------------------------
//create a medPing object (mP object has global file scope)
medPing mP;

//int medPing_Main();

//--------------
// medPing_Main \
//----------------------------------------------------------------------
// called from iPhone runSim-tab
int medPing_Main()
{
	// print a message to the cell phone
	mP.CELL_PrintF("Hello medPing patient ...\n\n");


	//======= DATA STRUCTURE ======================================
	// to hold patient's history of vital signs
	oneVitalHistoryRecord	vitalHistory[MAX_HISTORY];	
	
	// hmr (how many really) vital signs  0 <= hmr < MAX_HISTORY
	long hmr = 0;  
	//=============================================================
	
	RandGen		randGenerator;	// i need a random number generator
	time_t		start, now;		// keep track of time in simulation

	
	// ask user at CELL to input length of simulation
	mP.CELL_PrintF("How many SECONDS would you like to simulate? \n");
	double simulationTime = mP.CELL_fetchReal();
	time(&start);
	
	// (1) simulation loop ....
	time(&now);
	while ( difftime(now,start) < simulationTime )		// while still time to simulate ...
	{
		long waitThisLongSEC = randGenerator.RandInt(1, MAX_WAIT_SEC);
		mP.CELL_PrintF("\n--------------------------\n");
		mP.CELL_PrintF("\n[PAUSE ... (%d seconds) ]\n", waitThisLongSEC);
		std::this_thread::sleep_for(std::chrono::milliseconds(waitThisLongSEC*1000));
		// sleep(waitThisLongSEC);	// ZZzzzz.....
		// WINDOWS uses the function called: Sleep( milliseconds ) 
		// Sleep(waitThisLongSEC*1000);	// ZZzzzz.....

		
		
		// check our watch ...
		long nSecs = time(&now);


		// fetch vital signs from the medPing chip HERE (use mP object)

		double newTemp;
		short newPulseRate;
		short newRespirationRate;
		short new_systolic;
		short new_diastolic;
		short newGlucoseLevel;
		newTemp = mP.getBodyTemperature_F();
		newPulseRate = mP.getPulseRate_BPM();
		newRespirationRate = mP.getRespirationRate_BPM();
		mP.getBloodPressure_mmHg( new_systolic,  new_diastolic);
		newGlucoseLevel = mP.getGlucoseLevel_mgdL();

		AddHistoryRecord(nSecs, newTemp, newPulseRate, newRespirationRate, new_diastolic, new_systolic, newGlucoseLevel, vitalHistory, hmr);

		// :
		
		
		// once medPing has given you all the vital signs (see above)
		// now ADD these new vital signs to our history DATA STRUCTURE
		//AddHistoryRecord(nSecs, newTemp, /* ... more here ... ,*/ vitalHistory, hmr);
		
		// PRINT ALL of the series of vital signs so far
		printAllVitalRecords(mP, vitalHistory, hmr);
		

		
	} // while still more to simulate ...
		
		
	mP.CELL_PrintF("\n\nSIMULATION OVER.\n\n");

	// YOU only have to find/delete one record below

	if (hmr > 0) {
		long recordIndex = -5;
		while (recordIndex == -5) {
			mP.CELL_PrintF("Enter Record Time which you would like to delete: ");
			long RecordTime = mP.CELL_fetchReal();
			recordIndex = FindVitalRecord(RecordTime, vitalHistory, hmr);
		}

		DeleteHistoryRecord(vitalHistory, recordIndex, hmr);

		printAllVitalRecords(mP, vitalHistory, hmr);
	}
	
	
	mP.CELL_PrintF("\n\nDONE.\n");
	
	return 0;
} // end medPing_Main()


// helpful HISTORY functions below

//Pre: long nSecs, double new_mp_bodyTemp_F, short new_mp_pulseRate, short new_mp_respiration, short new_mp_diastolic,
//short new_mp_systolic, short new_mp_glucose.
//Post: Record is added to VitalHistory [].
//hmr is increased by one unless it goes beyond the Maximum
//Return: None
void AddHistoryRecord(long nSecs, double new_mp_bodyTemp_F, short new_mp_pulseRate, short new_mp_respiration, short new_mp_diastolic,
	short new_mp_systolic, short new_mp_glucose, oneVitalHistoryRecord vitalHistory[], long &hmr) {

	if (hmr >= MAX_HISTORY) {
		for (short i = 1 ; i <= MAX_HISTORY ; i++) {
			vitalHistory[i-1] = vitalHistory[i];
		}
		hmr = MAX_HISTORY - 1;
	}
	vitalHistory[hmr].secs = nSecs;
	vitalHistory[hmr].bodyTemp_F = new_mp_bodyTemp_F;
	vitalHistory[hmr].pulseRate = new_mp_pulseRate;
	vitalHistory[hmr].respiration = new_mp_respiration;
	vitalHistory[hmr].diastolic = new_mp_diastolic;
	vitalHistory[hmr].systolic = new_mp_systolic;
	vitalHistory[hmr].glucose = new_mp_glucose;

	hmr++;
}

//Pre: Long Time (used to determine specific record), VitalHistory (array of records), hmr (determines how long function
// should run for
//Post: No Changes
//Return: returns index value i (Location of Specific Record) or -5 if record could not be found
long FindVitalRecord(long Time, oneVitalHistoryRecord vitalHistory[], long hmr)
{
	long i = 0;
	short STOP = 0;
	while (STOP == 0) {
		if (i >= hmr) {
			STOP = 2;
		}
		if (vitalHistory[i].secs == Time) {
			STOP = 1;
		}
		if (STOP != 1) {
			i++;
		}
	}
	if (STOP == 1) {
		return i;
	}
	if (STOP == 2) {
		mP.CELL_PrintF("\nINVALID TIME.\n");
		return -5;
	}
}


//Pre: VitalHistory (array of records), recordID (index value of record being deleted)
//Post: hmr - 1
//Return: None
void DeleteHistoryRecord(oneVitalHistoryRecord vitalHistory[], long recordID, long& hmr)
{
 for (long i = recordID; i < hmr; i++) {
	 vitalHistory[i] = vitalHistory[i+1];
 }
	hmr--;
}


//---------------------\
// printAllVitalRecords \
//---------------------------------------------------------------------------------------------
// Prints history (last set of) hmr vital signs (to medPing output)
// PRE: 0 < hmr < MAX_HISTORY; vitalHistory [0 ... hmr-1]
// POST: No Changes
// SIDE EFFECTS: Prints Vital History Records
//---------------------------------------------------------------------------------------------
void printAllVitalRecords(medPing& mP, const oneVitalHistoryRecord vitalHistory[ ], long hmr)
{
	if (hmr > 0)
	{
		mP.CELL_PrintF("\n---- Records (so far) ----");
		for(long i=0; i < hmr; i++)
		{
			mP.CELL_PrintF("\nRECORD [%02d]\n", i);
			mP.CELL_PrintF("\t Time:    \t%ld\n", vitalHistory[i].secs);
			mP.CELL_PrintF("\t temp(F):    \t%4.1f\n", vitalHistory[i].bodyTemp_F);
			mP.CELL_PrintF("\t pulse(BPM): \t%4d\n",   vitalHistory[i].pulseRate);
			mP.CELL_PrintF("\t Resp(BPM): \t%4d\n",   vitalHistory[i].respiration);
			mP.CELL_PrintF("\t BP(Dia): \t%4d\n",   vitalHistory[i].diastolic);
			mP.CELL_PrintF("\t BP(Sys): \t%4d\n",   vitalHistory[i].systolic);
			mP.CELL_PrintF("\t Gluc(mgdL): \t%4d\n",   vitalHistory[i].glucose);

            
            
		} // for all records so far
		mP.CELL_PrintF("\n---- end History ----\n\n");

	} // if any records
	else 
		mP.CELL_PrintF("\nNo History so far ...\n\n");
	
} // printAllVitalRecords()


