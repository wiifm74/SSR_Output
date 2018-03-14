#define PUMP_WIRE_PWR 5						// Use GPIO pins for power/ground to simplify the wiring
#define PUMP_WIRE_GND 6						// Use GPIO pins for power/ground to simplify the wiring

#define BLINK_PUMP_EVERY 1000

unsigned long lastPumpBlink = 0;

int pumpState = 0;

void setup() {
	
  initPump();
  
}

void doFunctionAtInterval(void (*callBackFunction)(), unsigned long *lastEvent, unsigned long Interval) {

  unsigned long now = millis();

  if ((now - *lastEvent) >= Interval)
  {

    callBackFunction();
    *lastEvent = now;

  }

}

void loop() {

doFunctionAtInterval(blinkPump, &lastPumpBlink, BLINK_PUMP_EVERY);

}

void initPump() {
  pinMode(PUMP_WIRE_PWR, OUTPUT);
  pinMode(PUMP_WIRE_GND, OUTPUT);
}

void blinkPump() {

  digitalWrite(PUMP_WIRE_PWR, 1 - pumpState);
  pumpState = 1 - pumpState;

}
