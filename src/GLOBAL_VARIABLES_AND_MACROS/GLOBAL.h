#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>
#include <math.h>

//--------------------------
//#define DEBUG
#define TRIAL_0
#define MATLAB 
//---------------------------




 struct SAMPLES{
  float REAL_VALUE;
  float IMAGINARY_VALUE;
};

 struct MAGNITUDE_SAMPLES{
  float MAGNITUDE;
  float POSITION;
  float FREQUENCY;
};

// MACROS FOR MATLAB ----------------
#ifdef MATLAB
#include <WiFi.h>
#include <WiFiClient.h>
#define VOICE_SSID "M300"
#define VOICE_PASSWORD "Prasanna1972"
#define SERVER_IP "192.168.8.100"
#define SERVER_PORT 12345
extern uint8_t MATLAB_COUNTER;
extern bool ENTERED;
extern uint16_t MATLAB_COUNTER_1;
extern uint16_t MAX_COUNTER;
extern WiFiClient Client;
#endif
//  ---------------------------------


// IMPLEMENT THE SAMPLES  ----------------------------
#define POWER 10
#define SAMPLING_FREQUENCY 950
#define SAMPLING_TIME 1.0/SAMPLING_FREQUENCY
#define MAX_ITERATION 3
extern uint16_t NUMBER_OF_SAMPLES;// = (1 << POWER);  //SHOULD BE A POWER OF 2
extern int ITERATION;
extern int FFT_ITERATION;
extern struct MAGNITUDE_SAMPLES *MAGNITUDE_SAMPLES;// = (struct MAGNITUDE_SAMPLES *)calloc((NUMBER_OF_SAMPLES/2) + 1, sizeof(struct MAGNITUDE_SAMPLES));
extern struct SAMPLES *FFT_SAMPLES;// = (struct SAMPLES *)calloc(NUMBER_OF_SAMPLES, sizeof(struct SAMPLES));
 extern struct SAMPLES *SAMPLE_1;
 extern struct SAMPLES *SAMPLE_2;
 extern struct SAMPLES *SAMPLE_3; 
 extern struct SAMPLES *SAMPLE_ARRAY[MAX_ITERATION];
// ---------------------------

//  VARIABLES FOR CALCULATOR --------------------------
extern struct SAMPLES TWIDDLE_FACTOR;
extern struct SAMPLES TWIDDLE_PRODUCT;
extern struct SAMPLES INVERSE_TWIDDLE_PRODUCT;
extern struct SAMPLES DUMMY;
// ---------------------------------

//VARIABLES OF  ARRANGE_SAMPLES  -------------------------------- 
extern uint16_t COUNTER;
// -------------------------------


// FUNCTION 

void INITIALIZE();




#endif