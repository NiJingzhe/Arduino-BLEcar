#pragma once

#define BLINKER_BLE

#include <Blinker.h>

class Controler{
private:
    BlinkerSlider LSlider; 
    BlinkerSlider RSlider;
    BlinkerButton stopButton;
    blinker_callback_with_int32_arg_t LSlider_func,RSlider_func;
    blinker_callback_with_string_arg_t stopButton_func;
    uint8_t servantTx,servantRx;
public:
    bool stopState;
    float LSpeed,RSpeed;

    Controler(uint8_t stx,uint8_t srx,
            blinker_callback_with_int32_arg_t lsc,
            blinker_callback_with_int32_arg_t rsc,
            blinker_callback_with_string_arg_t btnc);
    ~Controler();
    void Initialize();
    void Start();
};

Controler::Controler(uint8_t stx,uint8_t srx,
                    blinker_callback_with_int32_arg_t lsc,
                    blinker_callback_with_int32_arg_t rsc,
                    blinker_callback_with_string_arg_t btnc):
    LSlider("L"),RSlider("R"),stopButton("Stop")
{
    servantTx = stx;
    servantRx = srx;
    LSlider_func = lsc;
    RSlider_func = rsc;
    stopButton_func = btnc;
}

void Controler::Initialize(){
    LSlider.attach(LSlider_func);
    RSlider.attach(RSlider_func);
    stopButton.attach(stopButton_func);
    Blinker.begin(servantTx,servantRx,115200);
    stopState = true;
}

void Controler::Start(){
    Blinker.run();
}

Controler::~Controler(){}