
#include "MAGNITUDE_SPECTRUM.h"

void MAGNITUDE_SPECTRUM(){
 #ifdef DEBUG
 Serial.printf("\n\n------------------------------------------");
 Serial.printf("\n\nNUMBER OF SAMPLES: %d", NUMBER_OF_SAMPLES);
    Serial.printf("\n\nFREQUENCY(Hz)\t\tMAGNITUDE\t\tVECTOR");
    for (uint16_t i = 0; i < NUMBER_OF_SAMPLES; i++){
        Serial.printf("\n%.3f\t\t\t%.3f\t\t\t%.3f%+.3fj", MAGNITUDE_SAMPLES[i].FREQUENCY, MAGNITUDE_SAMPLES[i].MAGNITUDE, FFT_SAMPLES[i].REAL_VALUE, FFT_SAMPLES[i].IMAGINARY_VALUE);
    }
  #endif  
}