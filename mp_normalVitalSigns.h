
#ifndef MYrand
#define MYrand


/*
 *  mp_normalVitalSigns.h
 *  TemplateFor115
 *
 *  Created by mleblanc on 12/15/08.
 *  Copyright 2008 medPing. All rights reserved.
 *
 */

// These values represent "normal" values for the entire population,
// not those of a specific individual.

// =====================  BODY TEMPERATURE =================
// NORMAL RANGE:   97.8 - 99.0F
const double mp_LOW_NORMAL_TEMP_F			=  97.8;   // low-end of normal temperature
const double mp_HIGH_NORMAL_TEMP_F			=  99.0;   // high-end of normal temperature
const double mp_NORMAL_TEMP_F				=  98.6;   // normal body temperature

											           // NOTE: 98.6 is midpoint of simulated low-high
const double mp_SIM_LOW_TEMP_F				=  93.6;   // low-end of simulated temp values
const double mp_SIM_HIGH_TEMP_F				= 103.6;   // high-end of simulated temp values


// =====================  PULSE RATE =======================
// NORMAL RANGE:   60 - 100 beats per minute
const short mp_LOW_NORMAL_PULSE_RATE_BPM	=  60;   // low-end of "normal" beats per minute (bpm)
const short mp_HIGH_NORMAL_PULSE_RATE_BPM	= 100;   // high-end "      "

													 // NOTE: 80 is midpoint of simulated low-high
const short mp_SIM_LOW_PULSE_RATE_BPM		=  30;   // low-end of simulated beats per minute (bpm)
const short mp_SIM_HIGH_PULSE_RATE_BPM		= 130;   // high-end "      "         "


// ==================  RESPIRATORY RATE ====================
// NORMAL RANGE:   15 - 20 breaths per minute (bpm)
const short mp_LOW_NORMAL_RESPIRATORY_RATE_BPM	=  15;   // low-end of "normal" breaths per minute (bpm)
const short mp_HIGH_NORMAL_RESPIRATORY_RATE_BPM	=  20;   // high-end "      "

												         // NOTE: 17.5 is midpoint of simulated low-high
const short mp_SIM_LOW_RESPIRATORY_RATE_BPM		=   5;   // low-end of simulated breaths per minute (bpm)
const short mp_SIM_HIGH_RESPIRATORY_RATE_BPM	=  30;   // high-end "      "         "


// ==================  BLOOD PRESSURE ======================
// NORMAL RANGE:  systolic  90 - 140 mm Hg (millimeters of Mercury)
//                diastolic 60 -  90 mm Hg

// ----- SYSTOLIC (upper value) -------
const short mp_LOW_NORMAL_SYSTOLIC_mmHg			=  90;   // low-end of "normal" systolic blood pressure
const short mp_HIGH_NORMAL_SYSTOLIC_mmHg		= 140;   // high-end of "normal" systolic blood pressure
const short mp_NORMAL_SYSTOLIC_mmHg				= 120;	 // normal systolic blood pressure

												         // NOTE: 120 is midpoint of simulated low-high
const short mp_SIM_LOW_SYSTOLIC_mmHg			=  50;   // low-end of simulated systolic
const short mp_SIM_HIGH_SYSTOLIC_mmHg			= 190;   // high-end "      "         "

// ----- DIASTOLIC (lower value) -------
const short mp_LOW_NORMAL_DIASTOLIC_mmHg		=  60;   // low-end of "normal" diastolic blood pressure
const short mp_HIGH_NORMAL_DIASTOLIC_mmHg		=  90;   // high-end of "normal" diastolic blood pressure
const short mp_NORMAL_DIASTOLIC_mmHg			=  80;	 // normal diastolic blood pressure

												         // NOTE: 80 is midpoint of simulated low-high
const short mp_SIM_LOW_DIASTOLIC_mmHg			=  35;   // low-end of simulated diastolic blood pressure
const short mp_SIM_HIGH_DIASTOLIC_mmHg			= 125;   // high-end "      "         "

// =================  GLUCOSE LEVELS  ===================

const short mp_Low_NonDiabetic					=  70;
const short mp_High_NonDiabetic					= 140;


const short mp_Low_Diabetic						= 125;
const short mp_High_Diabetic					= 360;


const short mp_SIM_Low_NonDiabetic				=  60; //guess know for sure
const short mp_SIM_High_NonDiabetic				= 150; // guess

const short mp_SIM_Low_Diabetic					= 115; //same
const short mp_SIM_High_Diabetic				= 370; //same


#endif