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
    int i = 0;   
    while (1) {
     	LineSensorReadArray(gls, line);
	Printf("Hello World!\n");
	float left, right;
	float abs difference;
	left = line[0]+line[1]+line[2];
	right =line[5]+line[6]+line[7];
	middle= line[3]+line[4];

//If sensors detect line on left side, turn gradually right to align.
//Converse for right.

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
}   else {
	SetServo(servo1, .25f);
	SetServo(servo2, .75f);
}
}
