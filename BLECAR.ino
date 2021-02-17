#include "Robot.h"

#define LPin1 2
#define LPin2 3
#define LEnable 5
#define RPin1 8
#define RPin2 9
#define REnable 10
#define ServTx 12
#define ServRx 13

void stopButton_callback(const String & state);
void LSlider_callback(int32_t value);
void RSlider_callback(int32_t value);


Robot BLEcar(LPin1,LPin2,LEnable,RPin1,RPin2,REnable,ServTx,ServRx,
            LSlider_callback,
            RSlider_callback,
            stopButton_callback);

void setup() {
  // put your setup code here, to run once:
  BLEcar.Initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  BLEcar.Start();
}

void stopButton_callback(const String & state){
    BLEcar.Controler.stopState = !BLEcar.Controler.stopState;
}

void LSlider_callback(int32_t value){
    BLEcar.Controler.LSpeed = value;
}

void RSlider_callback(int32_t value){
    BLEcar.Controler.RSpeed = value;
} 