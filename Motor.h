#pragma once

class Motor{
private:
    int enablePin,Pin_1,Pin_2;
public:
    Motor(int p1,int p2,int en);
    ~Motor();
    void Initialize();
    void Move(float speed);
    void Stop();
};

Motor::Motor(int p1,int p2,int en){
    Pin_1 = p1;
    Pin_2 = p2;
    enablePin = en; 
}
void Motor::Initialize(){
    pinMode(Pin_1,OUTPUT);
    pinMode(Pin_2,OUTPUT);
    pinMode(enablePin,OUTPUT);
}

void Motor::Move(float speed){
    if(speed < 0){
        digitalWrite(Pin_1,LOW);
        digitalWrite(Pin_2,HIGH);
    }
    if(speed == 0){
        this->Stop();
    }
    if(speed > 0){
        digitalWrite(Pin_1,HIGH);
        digitalWrite(Pin_2,LOW);        
    }
    analogWrite(enablePin,map(abs(speed),0,100,0,255));
}

void Motor::Stop(){
   analogWrite(enablePin,0);
}

Motor::~Motor(){}