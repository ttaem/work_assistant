void setup() {
  log_init();
  presence_init();
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  presence_check();
  delay(1000);
}
