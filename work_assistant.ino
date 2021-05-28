#include <SoftwareSerial.h>

#define BT_RX 6
#define BT_TX 7

SoftwareSerial bt(BT_RX, BT_TX);

void setup() {
  presence_init();
  alarm_init();
  bt.begin(9600);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int incoming;
  int p;
  // put your main code here, to run repeatedly:
  if(bt.available()) {
    //Serial.print("avail\n");
    Serial.write(bt.read());
    
  }
  if(Serial.available()) {
    //Serial.print("serial write\n");
    incoming = Serial.read();
    //bt.write(Serial.read());
    Serial.print("I received: ");
    Serial.println(incoming);
  }
  
  p = presence_check();
  if (p) {
    alarm_green_onoff(1);
    alarm_red_onoff(0);
  }else {
    alarm_green_onoff(0);
    alarm_red_onoff(1);
  }
  
  delay(1000);
  
}
