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
tServo *servo1;
servo1 = InitializeServo(PIN_B2);
tServo *servo2;
servo2 = InitializeServo(PIN_F0);
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
	SetServo(servo1, .25f);
	SetServo(servo2, .75f);
	Printf("Hello World!\n");
        
    }
}
