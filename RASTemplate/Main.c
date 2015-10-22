#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include<RASLib/inc/servo.h>

// Blink the LED to show we're on
tBoolean blink_on = true;

// Change these lines to set LED's to blink 
void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}

tServo *servo1 = InitializeServo(pin);
tServo *servo2 = InitializeServo(pin);

// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
    CallEvery(blink, 0, 0.5);
   
    while (1) {
        // Runtime code can go here
	SetServo(servo1, .75f);
	SetServo(servo2, .75f);
	Printf("Hello World!\n");
        
    }
}
