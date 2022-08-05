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
  if (BTserial.available()){
    value = BTserial.read();
    Serial.write(value);
    
    if (value == 'R'){
       Horizontal = 1;
    }
    else if(value == 'L'){
       Horizontal = -1;
    }
   else if (value == 'U'){
       Vertical = 1;
    }
    else if(value == 'D'){
       Vertical = -1;
    }
    else if(value == '0'){
      Horizontal = 0;
      Vertical = 0;
    }
  }

  digitalWrite(InMotorA2, HIGH);
  

  if (Vertical == 1){
    analogWrite(pwmMotorA,128);   
  }
  else if (Vertical == -1){
    analogWrite(pwmMotorA,0);   
  }
  else if (Vertical == 0){
    analogWrite(pwmMotorA,0);
  //Ustawienie prędkości obrotowej na 50% (zakres PWM: 8bitów czyli 0-255)
  }



}
