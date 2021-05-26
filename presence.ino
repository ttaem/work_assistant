
#define TRIG	9
#define ECHO	8

void presence_init(void)
{
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
}

int presence_check(void)
{
	long duration, distance;

	digitalWrite(TRIG, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG, LOW);

	duration = pulseIn(ECHO, HIGH);

	distance = duration * 17 / 1000;

	log_d(distance); log_s("Cm\n");
}
