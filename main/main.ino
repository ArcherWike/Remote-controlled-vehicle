//Motor connection

      //A
int pwmMotorA=5;
int InMotorA1=4;
int InMotorA2=3;
      //B
int pwmMotorB=6;
int InMotorB1=8;
int InMotorB2=7;

char value = 0;
int Horizontal = 0; // <->
int Vertical = 0; // ^


#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11); //RX | TX
//RX ---> 10
//TX ---> 11

void setup() {
  //---------------------| HC-06 config |------------------------------
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTserial.begin(9600);

  //---------------------| Motor config |------------------------------
  //PWM channel output A
  pinMode(pwmMotorA, OUTPUT); 
  
  //digital channel AIN1
  pinMode(InMotorA1, OUTPUT); 
  //digital channel AIN2
  pinMode(InMotorA2, OUTPUT);   


   //PWM channel output B
  pinMode(pwmMotorB, OUTPUT); 
  
  //digital channel BIN1
  pinMode(InMotorB1, OUTPUT); 
  //digital channel BIN2
  pinMode(InMotorB2, OUTPUT);
}

void loop() {
  

}
