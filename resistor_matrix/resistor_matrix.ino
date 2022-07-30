#include <Joystick.h>



int val = 0;
int ref = 0;
int activeButton = 0;
int lastActiveButton = 0;
unsigned long lastDebounceTime = 0;
int debounceDelay = 200;

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
  6, 0,
  false, false, false,
  false, false, false,
  false, false,
  false, false, false);
void setup() {
  analogReference(DEFAULT);
  Joystick.begin();
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void debounceButton() {
  int reading = determineButton();
  if (reading != lastActiveButton && lastActiveButton == 0 && (millis() - lastDebounceTime) > debounceDelay) {
    Serial.println("");
    Serial.print(reading);
    Joystick.pressButton(reading);
    delay(100);
    Joystick.releaseButton(reading);
    Serial.println("0");
    lastDebounceTime = millis();
  }
  lastActiveButton = reading;

}


int determineButton() {
  val = analogRead(A0);
  switch (val){
    case 0 ...100:
    return 1;
    case 500 ...600:
   return 2;
    case 601 ...700:
    return 3;
    case 701 ...800:
    return 4;
    case 801 ...900:
    return 5;
    default:
   return 0;

  }
}

void loop() {
  debounceButton();
  }
  // put your main code here, to run repeatedly:


