/* Shooter Definitions */

//Values
#define SHOOT_DEFAULT_SPEED 120
#define KONSTANT 5

//Joystick Buttons
//auto = alwaysOnEnc; manual = whenButtonPressedOnly
#define autoOn vexRT[Btn5U] //turn on auto
#define autoOff vexRT[Btn5D] //turn off auto
#define startR vexRT[Btn8R] //right manually
#define startL vexRT[Btn7L] //left manually
#define startBM vexRT[Btn6U] //both manually

//Encoders
#define shRT nMotorEncoder[rTopShooter] //master
#define shLT nMotorEncoder[lTopShooter]
#define shRB nMotorEncoder[rBottomShooter]
#define shLB nMotorEncoder[lBottomShooter]

#define err(enc) shRT - enc


/* Drive Definitions */

//Joystick
#define joyLDr vexRT[Ch3]
#define joyRDr vexRT[Ch2]


/* Intake Definitions */

//Joystick
#define joyIntakeI vexRT[Btn8L]
#define joyIntakeO vexRT[Btn8R]

//Values
#define INTAKE_SPEED 110
