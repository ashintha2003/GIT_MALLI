#include "INPUT_SAMPLES.h"

// CALL THIS FUNCTION EACH TIME THE USER TAKES A SAMPLE ------------------

void ARRANGE_SAMPLES(float SAMPLES){ 
    uint16_t INVERTED_VALUE = 0;
    uint16_t DUMMY_1 = COUNTER;
    for (int j = 0; j < POWER; j++){
        INVERTED_VALUE <<= 1;
        INVERTED_VALUE |= (DUMMY_1 & 1);
        DUMMY_1 >>= 1;
    }
    //FFT_SAMPLES[INVERTED_VALUE].REAL_VALUE = SAMPLES;  
    /*if(ITERATION == 1){
       SAMPLE_1[INVERTED_VALUE].REAL_VALUE = SAMPLES;
    }else if(ITERATION == 2){
       SAMPLE_2[INVERTED_VALUE].REAL_VALUE = SAMPLES;
    }else if(ITERATION == 3){
       SAMPLE_3[INVERTED_VALUE].REAL_VALUE = SAMPLES;
    }*/

    for(int i=1; i<=MAX_ITERATION; i++){
        if(i == ITERATION){
            (SAMPLE_ARRAY[i -1] + INVERTED_VALUE)->REAL_VALUE = SAMPLES;
            break;
        }
    }

    #ifdef DEBUG
    Serial.printf("\nCOUNTER: %d\tINVERTED_VALUE: %d", COUNTER, INVERTED_VALUE);
    #endif

  
    COUNTER = COUNTER + 1;

    if(COUNTER == (1 << POWER)){
        COUNTER = 0;
        if(ITERATION == MAX_ITERATION){
            ITERATION = 1;
            
        }else{
            ITERATION = ITERATION + 1;
        }
    }
    
}


void GET_SAMPLES(){
 
}