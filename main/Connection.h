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



#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11); //RX | TX
//RX ---> 10
//TX ---> 11
