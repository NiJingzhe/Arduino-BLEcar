#pragma once

#include "Motor.h"
#include "Controler.h"

class Robot{
public:
    Motor Lmotor,Rmotor;
    Controler Controler;

    Robot(int lp1,int lp2,int lpe,int rp1,int rp2,int rpe,int stx,int srx,
            blinker_callback_with_int32_arg_t lsc,
            blinker_callback_with_int32_arg_t rsc,
            blinker_callback_with_string_arg_t btnc);
    ~Robot();
    void Initialize();
    void robotMove(float lSpeed,float rSpeed);
    void robotStop();
    void Start();
};

Robot::Robot(int lp1,int lp2,int lpe,int rp1,int rp2,int rpe,int stx,int srx,
            blinker_callback_with_int32_arg_t lsc,
            blinker_callback_with_int32_arg_t rsc,
            blinker_callback_with_string_arg_t btnc):
    Lmotor(lp1,lp2,lpe),Rmotor(rp1,rp2,rpe),Controler(stx,srx,lsc,rsc,btnc)
{
    //do nothing
}

void Robot::Initialize(){
    Controler.Initialize();
    Lmotor.Initialize();
    Rmotor.Initialize();
}

void Robot::robotMove(float lSpeed,float rSpeed){
    Lmotor.Move(lSpeed);
    Rmotor.Move(rSpeed);
}

void Robot::robotStop(){
    Lmotor.Stop();
    Rmotor.Stop();
}

void Robot::Start(){
    Controler.Start();
    if(Blinker.connected())
        if(!Controler.stopState){
            robotMove(Controler.LSpeed,Controler.RSpeed);
        }
        else{
            robotStop();
        }
    else{
        robotStop();
    }
}

Robot::~Robot(){}