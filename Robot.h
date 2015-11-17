/* Shooter Definitions */

//Values
#define SHOOT_DEFAULT_SPEED 110
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
#define joyLDr vexRT[Ch4]
#define joyRDr vexRT[Ch1]


/* Intake Definitions */

//Joystick
#define joyIntakeI vexRT[Ch9U]
#define joyIntakeO vexRT[Ch9D]

//Values
#define INTAKE_SPEED 110