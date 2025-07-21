
#include "TRIAL.h"


void TRIAL(){  //THIS FUCNTION WILL GENERATE SAMPLES OF SINE FUNCTION AND PLOT THE FFT

    Serial.printf("ENTER ANY KEY TO START THE PROCESS: \n\n");
    while(Serial.available() == 0){delay(1);}
   for(uint16_t i=0; i<NUMBER_OF_SAMPLES; i++){
     float SAMPLES = 10.0 * (float)sin(2.0*PI*100.0*SAMPLING_TIME*(double)i) + 0.5 * (float)sin(2.0*PI*70.0*SAMPLING_TIME*(double)i);// + 2.0 * (float)sin(2.0*PI*50.0*SAMPLING_TIME*(double)i) + 0.5 * (float)sin(2.0*PI*70.0*SAMPLING_TIME*(double)i);
     //if(i > 250 && i < 360){SAMPLES = SAMPLES + 9.5;}
     //SAMPLES = SAMPLES + random(1, 8);
     MATLAB_FUNCTION(NUMBER_OF_SAMPLES, SAMPLES, (float)i * SAMPLING_TIME, 0);
     ARRANGE_SAMPLES(SAMPLES);
     #ifdef DEBUG
     Serial.printf("\n%.3f", SAMPLES);
     #endif

   }
   
    
    FFT(); // CALL THE FUNCTION
    OMIT_NOISE();
    INVERSE_FFT();
    
     
   
    while(1){delay(100);}
}