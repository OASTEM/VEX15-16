#define min(x,y) ((x > y) ? (y) : (x))
#define max(x,y) ((x > y) ? (x) : (y))
#define safeSet(power) (max(-MAX_POWER, min(MAX_POWER, power)))
