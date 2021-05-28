
#define TRIG	9
#define ECHO	8

int g_cnt = 10;
int g_distance = 50;

void presence_init(void)
{
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
}

void presence_set(int cnt, int distance)
{
	g_cnt = cnt;
	g_distance = distance;
}

/*
return 1: presence,
return 0: absense
*/

int presence_check(void)
{
	static int cnt = 0;
	long duration, distance;

	digitalWrite(TRIG, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG, LOW);

	duration = pulseIn(ECHO, HIGH);

	distance = duration * 17 / 1000;

	Serial.print(distance); Serial.print("Cm\n");

	if (distance > g_distance) {
		cnt ++;
	}
	else {
		cnt = 0;
		return 1;
	}

	if (cnt > g_cnt) {
		return 0;
	}
}
