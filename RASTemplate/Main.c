#include<RASLib/inc/common.h>
#include<RASLib/inc/gpio.h>
#include<RASLib/inc/time.h>
#include<RASLib/inc/servo.h>
#include<RASLib/inc/linesensor.h>

// Blink the LED to show we're on
tBoolean blink_on = true;

// Change these lines to set LED's to blink 
void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}

// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
    CallEvery(blink, 0, 0.5);
// Name servo1 and 2 correlating to left/right.
    tServo *servo1;
    servo1 = InitializeServo(PIN_B2);
    tServo *servo2;
    servo2 = InitializeServo(PIN_F0);
    tservo *gateservo;
    gateservo = InitializeServo(PIN_XX);
    tLinesensor *gls;
    gls = InitializeGPIOLinesesnor(
	PIN_B5,
	PIN_D0,
	PIN_D1,
	PIN_D2,
	PIN_D3,
	PIN_D3,
	PIN_E0,
	PIN_C6,
	PIN_C7
	);
float line[8];
    while (1) {
        // Runtime code can go here
	LineSensorReadArray(gls, line);
	Printf("Hello World!\n");
	float left, right;
	float abs difference;
	left = line[0]+line[1]+line[2]+line[3];
	right =line[4]+line[5]+line[6]+line[7];
	difference = left-right;

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
   else if(difference<1){
	SetServo(servo1, .25f);
	SetServo(servo2, .75f);
}
   else {
	SetServo(servo1, .25f);
	SetServo(servo2, .75f);
}
}
