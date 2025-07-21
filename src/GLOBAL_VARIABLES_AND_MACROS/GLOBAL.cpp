#include "GLOBAL.h"

// MACROS FOR MATLAB ----------------
 #ifdef MATLAB
 uint8_t MATLAB_COUNTER = 0;
 bool ENTERED = false;
 uint16_t MATLAB_COUNTER_1 = 0;
 uint16_t MAX_COUNTER = 1000;  
 WiFiClient Client;
 #endif
//---------------------------------

// IMPLEMENT THE SAMPLES  ----------------------------
 uint16_t NUMBER_OF_SAMPLES = (1 << POWER);  //SHOULD BE A POWER OF 2
 int ITERATION = 1;
 int FFT_ITERATION = 1;
 struct MAGNITUDE_SAMPLES *MAGNITUDE_SAMPLES = (struct MAGNITUDE_SAMPLES *)calloc((NUMBER_OF_SAMPLES/2) + 1, sizeof(struct MAGNITUDE_SAMPLES));
 struct SAMPLES *FFT_SAMPLES;
 struct SAMPLES *SAMPLE_1 = (struct SAMPLES *)calloc(NUMBER_OF_SAMPLES, sizeof(struct SAMPLES));
 struct SAMPLES *SAMPLE_2 = (struct SAMPLES *)calloc(NUMBER_OF_SAMPLES, sizeof(struct SAMPLES));
 struct SAMPLES *SAMPLE_3 = (struct SAMPLES *)calloc(NUMBER_OF_SAMPLES, sizeof(struct SAMPLES));
 struct SAMPLES *SAMPLE_ARRAY[MAX_ITERATION];

// ---------------------------

//  VARIABLES FOR CALCULATOR --------------------------
struct SAMPLES TWIDDLE_FACTOR;
struct SAMPLES TWIDDLE_PRODUCT;
struct SAMPLES INVERSE_TWIDDLE_PRODUCT;
struct SAMPLES DUMMY;
// --------------------------------

//VARIABLES OF  ARRANGE_SAMPLES  -------------------------------- 
 uint16_t COUNTER = 0;
// -------------------------------




// FUNCTION -------------------------------- 

void INITIALIZE(){
  Serial.begin(115200);  
  Serial.printf("\n\n\n\n\n\n\n\n\nVOICE STARTED ✅\n\n");
  for(int i=0; i<MAX_ITERATION; i++){
    SAMPLE_ARRAY[i] = (struct SAMPLES *)calloc(NUMBER_OF_SAMPLES, sizeof(struct SAMPLES));
  }
}

// -----------------------------