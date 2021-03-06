#pragma config(Motor,  port2,           rDrive,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           rTopShooter,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           rBottomShooter, tmotorVex393, openLoop)
#pragma config(Motor,  port5,           gate,          tmotorVex393, openLoop)
#pragma config(Motor,  port6,           lTopShooter,   tmotorVex393, openLoop)
#pragma config(Motor,  port7,           lDrive,        tmotorVex393, openLoop)
#pragma config(Motor,  port9,           lBottomShooter, tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Durati..on Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

#include "Robot.h"
#include "Macros.h"

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  /**startBoth();
  drive(100,100);

  wait1Msec(2000);//wait for arrival
  drive(0,0);
  liftGate();

  wait1Msec(1000); //wait for gate to open
  stopGate();

  wait1Msec(4000); //wait for balls to shoot
  drive(-100,-100); //go back

  wait1Msec(2000);
  drive(0,0);
  dropGate();

  wait1Msec(1000); //wait for gate to close
  stopGate();*/

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{

	/* Shooter Definitions */
	bool isAuto = false; //is shooter auto or manual

	while(true){
		/* Drive Code */
		drive(joyLDr,joyRDr);

		/* Gate Code */
		/**if(joyGateUp > 0){
			liftGate();
		}else if (joyGateDown > 0){
			dropGate();
		}else{
			stopGate();
		}

		if(vexRT[Btn7U] > 0) motor[port5] = 100;
		else if (vexRT[Btn7D] > 0) motor[port5] = -100;
		else motor[port5] = 0;

		*/


		/* Shooter Code */
		if(autoOn > 0){ //toggle auto states
			isAuto = true;
		}else if (autoOff > 0){
			isAuto = false;
		}

		if(isAuto){ //if automatic
				startBoth();
		}else{ //manual
			if(startR > 0 || startBM > 0){
				startRight();
			}else{
				stopRight();
			}
			if(startL > 0 || startBM > 0){
				startLeft();
			}else{
				stopLeft();
			}
		}
	}

}
