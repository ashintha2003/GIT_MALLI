#include "MATLAB.h"

// -----------------------
void MATLAB_FUNCTION(String COMMAND, uint8_t AFTER_COMMAND){  //CONNECT TO MATLAB AND PLOT THE GRAPGH
#ifdef MATLAB
    Serial.printf("\n\n------------------------------------------");
    if (MATLAB_COUNTER == 0){
        MATLAB_COUNTER = MATLAB_COUNTER + 1;
        // CONNECT INTO WIFI

        Serial.printf("\n\nCONNECTING TO WIFI.");
        WiFi.begin(VOICE_SSID, VOICE_PASSWORD);
        while (WiFi.status() != WL_CONNECTED){
            delay(900);
            Serial.printf(".");
        }
        Serial.printf("\n\nWIFI CONNECTED ✅");
        //

        // CONNECT TO THE SERVER

        Serial.printf("\n\nCONNECTING TO THE SERVER.");
        Client.connect(SERVER_IP, SERVER_PORT);
        while (!Client.connected()){
            Client.connect(SERVER_IP, SERVER_PORT);
            delay(900);
            Serial.printf(".");
        }
        Serial.printf("\n\nSERVER CONNECTED ✅");
        //
    }

    if(COMMAND == "FREQUENCY"){
        // SEND DATA TO THE MATLAB SERVER
    Serial.printf("\n\nSENDING DATA....");
    // SEND POWER
    delay(2);

    Client.write((uint8_t *)&NUMBER_OF_SAMPLES, sizeof(NUMBER_OF_SAMPLES));
    delay(10);
    //

    for (int16_t i = 0; i < NUMBER_OF_SAMPLES; i++)
    {
        Client.write((uint8_t *)&MAGNITUDE_SAMPLES[i].MAGNITUDE, sizeof(MAGNITUDE_SAMPLES[i].MAGNITUDE));
        delay(2);
        Client.write((uint8_t *)&MAGNITUDE_SAMPLES[i].FREQUENCY, sizeof(MAGNITUDE_SAMPLES[i].FREQUENCY));
        delay(2);
    }

    //
    Serial.printf("\n\nMATLAB DATA SENT ✅");
    // while(1){delay(100);}
    }else if(COMMAND == "TIME"){

    // SEND DATA TO THE MATLAB SERVER
    Serial.printf("\n\nSENDING DATA....");
    // SEND POWER
    delay(2);

    Client.write((uint8_t *)&NUMBER_OF_SAMPLES, sizeof(NUMBER_OF_SAMPLES));
    delay(10);
    //

    for (int16_t i = 0; i < NUMBER_OF_SAMPLES; i++)
    {
        Client.write((uint8_t *)&FFT_SAMPLES[i].REAL_VALUE, sizeof(FFT_SAMPLES[i].REAL_VALUE));
        delay(2);
        float TIME_1 = (float)i * SAMPLING_TIME;
        Client.write((uint8_t *)&TIME_1, sizeof(TIME_1));
        delay(2);
    }

    //
    Serial.printf("\n\nMATLAB DATA SENT ✅");
        
    }
  Client.write((uint8_t *)&AFTER_COMMAND, sizeof(AFTER_COMMAND));
#endif
}



// ------------------------------
void MATLAB_FUNCTION(uint16_t NUMBER, float Y, float X, uint8_t AFTER_COMMAND){  
    #ifdef MATLAB
    
    if (MATLAB_COUNTER == 0){
         Serial.printf("\n\n------------------------------------------");
        MATLAB_COUNTER = MATLAB_COUNTER + 1;
        // CONNECT INTO WIFI

        Serial.printf("\n\nCONNECTING TO WIFI.");
        WiFi.begin(VOICE_SSID, VOICE_PASSWORD);
        while (WiFi.status() != WL_CONNECTED){
            delay(900);
            Serial.printf(".");
        }
        Serial.printf("\n\nWIFI CONNECTED ✅");
        //

        // CONNECT TO THE SERVER

        Serial.printf("\n\nCONNECTING TO THE SERVER.");
        Client.connect(SERVER_IP, SERVER_PORT);
        while (!Client.connected()){
            Client.connect(SERVER_IP, SERVER_PORT);
            delay(900);
            Serial.printf(".");
        }
        Serial.printf("\n\nSERVER CONNECTED ✅");
        //
    }
        if(!ENTERED){
            ENTERED = true;
            MAX_COUNTER = NUMBER;
            Serial.printf("\n\n------------------------------------------");
            Serial.printf("\n\nSENDING DATA..");
            Client.write((uint8_t *)&NUMBER, sizeof(NUMBER));
            delay(10);
        }
         Client.write((uint8_t *)&Y, sizeof(Y));
         delay(2);
         Client.write((uint8_t *)&X, sizeof(X));
         delay(2);
  
    MATLAB_COUNTER_1 = MATLAB_COUNTER_1 + 1;
    if(MATLAB_COUNTER_1 == MAX_COUNTER){
        ENTERED = false;
        Client.write((uint8_t *)&AFTER_COMMAND, sizeof(AFTER_COMMAND));
        Serial.printf("\n\nMATLAB DATA SENT ✅");
    }
    #endif
}