#define PORT_L port3
#define PORT_R port2
#define SPEED 127

task main()
{
	bMotorReflected[PORT_L];
	while(true){
x		if(vexRT[Btn8R] > 0 || vexRT[Btn6U] > 0){
			motor[PORT_R] = SPEED;
		}else{
			motor[PORT_R] = 0;
		}
		if(vexRT[Btn7L] > 0 || vexRT[Btn6U] > 0){
			motor[PORT_L] = SPEED;
		}else{
			motor[PORT_L] = 0;
		}
	}
}
