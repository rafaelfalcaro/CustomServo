#ifndef CustomServo_h
#define CustomServo_h

#include "Arduino.h"
#include "Servo.h"

// Definições das constantes
#define MAXVEL 1                            // Velocidade máxima do Servo [ms]
#define MINVEL 20                           // Velocidade mínima do Servo [ms]

// Classe Principal
class CustomServo {
    public:
        // Funções
        void Home();                        // Movimento automático até a posição de Home
        void MoveInc(int _pos);             // Movimento incremental
        void MoveTo(int _pos);              // Movimento absoluto
        void SetPin(byte _pin);             // Definição do pino da placa que controle o Servo

        // Objeto da biblioteca Servo
        Servo servo;

        // Parametrização do Servo Motor
        byte Dir;                           // Sentido de Giro: 0->CW / 1->CCW
        byte HomeOffset;                    // Offset de posição do Servo [°]
        byte JogSpeed;                      // Setpoint de velocidade de movimento do Servo [1-100%]
        byte JogTa;                         // Tempo de aceleração do Servo [s]
        byte JogTd;                         // Tempo de desaceleração do Servo [s]
        int MaxPos;                         // Posição Máxima permitida do Servo [°]
        int MinPos;                         // Posição Mínima permitida do Servo [°]
        
        // Status do Servo Motor
        int ActPos;                         // Posição atual processada do Servo [°]
        byte Pos;                           // Posição atual não processada do Servo [°]
        byte Velocity;                      // Velocidade atual de movimento do Servo [°/s]

    private:
        // Funções
        void moveServo(int _pos);           // Função para movimentação do Servo
};

#endif