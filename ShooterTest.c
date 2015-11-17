#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           shooterR,      tmotorVex393, openLoop)
#pragma config(Motor,  port3,           shooterL,      tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define DEFAULT_SPEED 110
#define KONSTANT 5

//auto = alwaysOn; manual = whenButtonPressedOnly
#define autoOn vexRT[Btn5U] //turn on auto
#define autoOff vexRT[Btn5D] //turn off auto
#define startR vexRT[Btn8R] //right manually
#define startL vexRT[Btn7L] //left manually
#define startBM vexRT[Btn6U] //both manually
//#define startBA vexRT[Btn6D] //both manually (with encoders)

//#define shR nMotorEncoder[shooterR]
//#define shL nMotorEncoder[shooterL]

task main()
{
	bool isAuto = false; //is shooter auto or manual

	int masterPow = DEFAULT_SPEED;
	int slavePow = DEFAULT_SPEED;
	int error = 0;

	while(true){
		if(autoOn > 0){ //toggle auto states
			isAuto = true;
		}else if (autoOff > 0){
			isAuto = false;
		}

		if(isAuto || startBA > 0){ //if automatic
			motor[shooterR] = DEFAULT_SPEED;
			motor[shooterL] = DEFAULT_SPEED;
		}else{ //manual
			if(startR > 0 || startBM > 0){
				motor[shooterR] = DEFAULT_SPEED;
			}else{
				motor[shooterR] = 0;
			}
			if(startL > 0 || startBM > 0){
				motor[shooterL] = DEFAULT_SPEED;
			}else{
				motor[shooterL] = 0;
			}
		}
	}
}
