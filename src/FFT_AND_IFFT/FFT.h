#ifndef FFT_H
#define FFT_H

#include "GLOBAL.h"
#include "MATLAB.h"
#include "MAGNITUDE_SPECTRUM.h"

void FFT();
void CALCULATOR(uint16_t LEFT_POINTER, uint16_t RIGHT_POINTER, uint16_t K, uint16_t N);
void INVERSE_FFT();

#endif