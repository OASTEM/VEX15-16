#define min(x,y) ((x > y) ? (y) : (x))
#define max(x,y) ((x > y) ? (x) : (y))
#define safeSet(power) (max(-MAX_POWER, min(MAX_POWER, power)))

#define drive(l,r) motor[lDrive] = l; motor[rDrive] = r

/**
#define liftGate() motor[gate] = GATE_SPEED
#define dropGate() motor[gate] = -GATE_SPEED
#define stopGate() motor[gate] = 0
*/

#define startRight() motor[rTopShooter] = SHOOT_DEFAULT_SPEED; motor[rBottomShooter] = SHOOT_DEFAULT_SPEED
#define stopRight() motor[rTopShooter] = 0;	motor[rBottomShooter] = 0
#define startLeft() motor[lTopShooter] = SHOOT_DEFAULT_SPEED; motor[lBottomShooter] = SHOOT_DEFAULT_SPEED
#define stopLeft() motor[lTopShooter] = 0;	motor[lBottomShooter] = 0

#define startBoth() startLeft(); startRight()
#define stopBoth() stopLeft(); stopRight()
