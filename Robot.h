/* Shooter Definitions */

//Values
#define SHOOT_DEFAULT_SPEED 127

//Joystick Buttons
//auto = alwaysOnEnc; manual = whenButtonPressedOnly
#define autoOn vexRT[Btn5U] //turn on auto
#define autoOff vexRT[Btn5D] //turn off auto
#define startR vexRT[Btn8R] //right manually
#define startL vexRT[Btn8L] //left manually
#define startBM vexRT[Btn8U] //both manually


/* Drive Definitions */

//Joystick
#define joyLDr vexRT[Ch3]
#define joyRDr vexRT[Ch2]


/* Gate Definitions */

//Joystick
#define joyGateUp vexRT[Btn6U]
#define joyGateDown vexRT[Btn6D]

//Values
#define GATE_SPEED 110
