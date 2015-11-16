#include<RASLib/inc/common.h>
#include<RASLib/inc/gpio.h>
#include<RASLib/inc/time.h>
#include<RASLib/inc/servo.h>
#include<RASLib/inc/linesensor.h>
#include<RASLib/inc/adc.h>


tBoolean blink_on = true;

void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
		 }

int main(void) {
   
    CallEvery(blink, 0, 0.5);
    tServo *servo1;
    servo1 = InitializeServo(PIN_B2);
    tServo *servo2;
    servo2 = InitializeServo(PIN_F0);
    tLineSensor *gls;
    gls = InitializeGPIOLineSensor(
	PIN_B3,
	PIN_C4,
	PIN_C5,
	PIN_C6,
	PIN_C7,
	PIN_D6,
	PIN_D7,
	PIN_F4
	);
    tADC *adc1;
    adc1 = InitializeADC(PIN_E1);
    tADC *adc2;
    adc2 = InitializeADC(PIN_E2);
    tADC *adc3;
    adc3 = InitializeADC(PIN_E3);
    float line[8];
    float left, right, middle, all;
    float wallleft, wallright, wallfront;
    int i = 1;
    while (1) {

	LineSensorReadArray(gls, line);
	left = line[0]+line[1]+line[2];
	right =line[5]+line[6]+line[7];
	middle= line[3]+line[4];
	all= line[0]+ line[1]+line[2]+line[3]+line[4]+line[5]+line[6]+line[7];
 	wallleft = ADCRead(adc1);
	wallright = ADCRead(adc2);
	wallfront = ADCRead(adc3);
	Printf(wallleft"\n");
	enum State {linee, walll, wallr, turnll, turnlr, turnwl, turnwr};
	enum State s = wallr;

	switch (s){
	case linee:
		if(left>1){
			SetServo(servo1, .25f);
			SetServo(servo2, .50f);
			}
		else if(right>1){
			SetServo(servo1, .50f);
			SetServo(servo2, .25f);
			}
		else if(middle>1){
			SetServo(servo1, .25f);
			SetServo(servo2, .75f);
			}
 	       	else if(wallfront>10){
			if(i&1){
				s = turnwr;
				}
			else {
				s = turnwl;
				}
					}
		else {
			SetServo(servo1, .25f);
			SetServo(servo2, .75f);
			}
		break;
		
	case walll:
 
		if(wallleft>1){
			SetServo(servo1, .25f);
			SetServo(servo2, .50f);
			}		
		else if(wallleft<1){
			SetServo(servo1, .50f);
			SetServo(servo2, .25f);
			}	
		else if(all>100){
			s= turnlr;
			}
		break;
	
	case wallr:	

       		if(wallright>1){
			SetServo(servo1, .25f);
			SetServo(servo2, .50f);
			}
		else if(wallright<1){
			SetServo(servo1, .50f);
			SetServo(servo2, .25f);
			}
		else if(all>100){
			s= turnll;
			}
		break;
		
	case turnll:
		SetServo(servo1, .25f);
		SetServo(servo2, .50f);
		Wait(1.5f);
		i=i+1;
		s = linee; 			
		break;

	case turnlr:
		SetServo(servo1, .25f);
		SetServo(servo2, .50f);
		i=i+1;	
		Wait(1.5f);
		s= linee;
		break;

	case turnwl:
		SetServo(servo1, .25f);
		SetServo(servo2, .50f);
		Wait(1.5f);
		s = wallr;
		break;

	case turnwr:
		SetServo(servo1, .25f);
		SetServo(servo2, .50f);
		Wait(1.5f);
		s=walll;
		break;		
 
}
}
}
