#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rDrive,        tmotorVex393, openLoop)
#pragma config(Motor,  port2,           lDrive,        tmotorVex393, openLoop)
#pragma config(Motor,  port3,           rTopShooter,   tmotorVex393, openLoop)
#pragma config(Motor,  port4,           lTopShooter,   tmotorVex393, openLoop)
#pragma config(Motor,  port5,           rBottomShooter, tmotorVex393, openLoop, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port6,           lBottomShooter, tmotorVex393, openLoop, encoder, encoderPort, I2C_4, 1000)
#pragma config(Motor,  port7,           intake,        tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Robot.h"

task main()
{
	/* Shooter Definitions */
	bool isAuto = false; //is shooter auto or manual

	int masterPow = SHOOT_DEFAULT_SPEED;
	int slaveLT = SHOOT_DEFAULT_SPEED;
	int slaveRB = SHOOT_DEFAULT_SPEED;
	int slaveLB = SHOOT_DEFAULT_SPEED;
	int error = 0;

	while(true){
		/* Drive Code */
		motor[rDrive] = joyRDr;
		motor[lDrive] = joyLDr;

		
		/* Intake Code */
		if(joyIntakeI > 0){
			motor[intake] = INTAKE_SPEED;
		}else if(joyIntakeO){
			motor[intake] = -INTAKE_SPEED;
		}else{
			motor[intake] = 0;
		}


		/* Shooter Code */
		if(autoOn > 0){ //toggle auto states
			isAuto = true;
		}else if (autoOff > 0){
			isAuto = false;
		}

		if(isAuto){ //if automatic
			motor[rTopShooter] = masterPow;
			motor[lTopShooter] = slaveLT;
			motor[rBottomShooter] = slaveRB;
			motor[lBottomShooter] = slaveLB;

			slaveLT += err(shLT)/KONSTANT;
			slaveRB += err(shRB)/KONSTANT;
			slaveLB += err(shLB)/KONSTANT;

			shRT = 0;
			shLT = 0;
			shRB = 0;
			shLB = 0;

			wait1Msec(100);
		}else{ //manual
			if(startR > 0 || startBM > 0){
				motor[shooterR] = SHOOT_DEFAULT_SPEED;
			}else{
				motor[shooterR] = 0;
			}
			if(startL > 0 || startBM > 0){
				motor[shooterL] = SHOOT_DEFAULT_SPEED;
			}else{
				motor[shooterL] = 0;
			}
		}
	}

}
