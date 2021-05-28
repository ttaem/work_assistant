
#define GREEN_LED			13
#define RED_LED				12

void alarm_init()
{
	pinMode(GREEN_LED, OUTPUT);
	pinMode(RED_LED, OUTPUT);
}


void alarm_green_onoff(int onoff)
{
	digitalWrite(GREEN_LED, onoff);
}

void alarm_red_onoff(int onoff)
{
	digitalWrite(RED_LED, onoff);
}
