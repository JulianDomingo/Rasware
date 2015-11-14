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
    tLinesensor *gls;
    gls = InitializeGPIOLinesesnor(
	PIN_B5,
	PIN_B0,
	PIN_B1,
	PIN_E4,
	PIN_E5,
	PIN_B4,
	PIN_A5,
	PIN_A6,
	PIN_A7
	);
    tADC *adc1;
    adc1 = InitializeADC(PIN_xx);
    tADC *adc2;
    adc2 = InitializeADC(PIN_xx);
    tADC *adc3;
    adc3 = InitializeADC(PIN_XX);
    float line[8];
    int i = 1;   
    while (1) {
     	LineSensorReadArray(gls, line);
	Printf("Hello World!\n");
	float left, right;
	float abs difference;
	left = line[0]+line[1]+line[2];
	right =line[5]+line[6]+line[7];
	middle= line[3]+line[4];
	all= line[0]+ line[1]+line[2]+line[3]+line[4]+line[5]+line[6]+line[7]

    if(all>10){
//If line sesnor reads a line
	if(i&1){
//If sensors detect a line, if i is odd turn left. if i is even turn right.
		SetServo(servo1, .25f);
		SetServo(servo2, .50f);
		void Wait(1.5);
		i=i+1;
		   if(left>1){
			SetServo(servo1, .25f);
			SetServo(servo2, .50f);
}
		   else if (right>1){
			SetServo(servo1, .50f);
			SetServo(servo2, .25f);
}
		   else if(middle>1){
			SetServo(servo1, .25f);
			SetServo(servo2, .75f);
} 	       	   else {
			SetServo(servo1, .25f);
			SetServo(servo2, .75f);
}
}
	else{
		SetServo(servo1, .50f);
		SetServo(servo2, .25f);
		void Wait(1.5);
		i=i+1;
		   if(left>1){
			SetServo(servo1, .25f);
			SetServo(servo2, .50f);
}
		   else if (right>1){
			SetServo(servo1, .50f);
			SetServo(servo2, .25f);
}
		   else if(middle>1){
			SetServo(servo1, .25f);
			SetServo(servo2, .75f);
} 	       	   else {
			SetServo(servo1, .25f);
			SetServo(servo2, .75f);
}
}
}
