void log_init()
{
	Serial.begin(9600);
}


#define log_s(v)		Serial.print(v)
#define log_b(v)		Serial.print(v, BIN)
#define log_d(v)		Serial.print(v, DEC)
