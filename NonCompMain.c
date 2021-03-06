#pragma config(Motor,  port2,           rDrive,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           rTopShooter,   tmotorVex393, openLoop)
#pragma config(Motor,  port4,           rBottomShooter, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           gate,          tmotorVex393, openLoop)
#pragma config(Motor,  port6,           lDrive,        tmotorVex393, openLoop)
#pragma config(Motor,  port8,           lTopShooter,   tmotorVex393, openLoop)
#pragma config(Motor,  port9,           lBottomShooter, tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Robot.h"
#include "Macros.h"

task main()
{

	/* Shooter Definitions */
	bool isAuto = false; //is shooter auto or manual

	while(true){
		/* Drive Code */
		drive(joyLDr,joyRDr);

		/* Gate Code */
		if(joyGateUp > 0){
			liftGate();
		}else if (joyGateDown > 0){
			dropGate();
		}else{
			stopGate();
		}


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
