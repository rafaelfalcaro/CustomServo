#include "Arduino.h"
#include "CustomServo.h"

//************************************************************************************
// Funções Públicas

// Movimento automático até a posição de Home
void CustomServo::Home() {
    moveServo(HomeOffset);
}

// Movimento incremental do Servo
void CustomServo::MoveInc(int _pos) {
    if ((ActPos + _pos >= MinPos) && (ActPos + _pos <= MaxPos)) {
        moveServo(ActPos + _pos + HomeOffset);
    }
}

// Movimento absoluto do Servo
void CustomServo::MoveTo(int _pos) {
    if ((_pos >= MinPos) && (_pos <= MaxPos)) {
        moveServo(_pos + HomeOffset);
    }
}

// Definição do pino da placa que controle o Servo
void CustomServo::SetPin(byte _pin) {
    servo.attach(_pin);
}


//************************************************************************************
// Funções Privadas

// Move (absoluto) levando em consideração velocidade e aceleração
void CustomServo::moveServo(int _pos) {
    double waitTime = (-0.1919 * JogSpeed) + 20.192;
    while (_pos != Pos) {
        if (_pos > Pos) Pos++;
        else Pos -= 1;
        ActPos = Pos - HomeOffset;
        servo.write(Pos);
        delay(waitTime);
    }
}