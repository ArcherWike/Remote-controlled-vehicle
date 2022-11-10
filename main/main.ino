//Motor connection

      //A
int pwmMotorA=9;
int InMotorA1=12;
int InMotorA2=13;
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

  

  if (Vertical == 1){
    digitalWrite(InMotorA1, LOW);
    digitalWrite(InMotorA2, HIGH);
    analogWrite(pwmMotorA,128); 

    digitalWrite(InMotorB1, LOW);
    digitalWrite(InMotorB2, HIGH);
    analogWrite(pwmMotorB,128);

  }
  else if (Vertical == -1){
    digitalWrite(InMotorA1, HIGH);
    digitalWrite(InMotorA2, LOW); 
    analogWrite(pwmMotorA,128);

    digitalWrite(InMotorB1, HIGH);
    digitalWrite(InMotorB2, LOW); 
    analogWrite(pwmMotorB,128);      
  }
  else if (Horizontal == -1){
    analogWrite(pwmMotorA,64);
    analogWrite(pwmMotorB,128);    
  }
  else if (Horizontal == 1){
    analogWrite(pwmMotorA,128);
    analogWrite(pwmMotorB,64);
  }
  else if (Vertical == 0){
    analogWrite(pwmMotorA,0);
    analogWrite(pwmMotorB,0);
  }

}
