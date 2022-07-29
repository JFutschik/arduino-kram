unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int lastButtonState = HIGH;
int buttonState;
int debounceDone;

void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void debounceButton(int buttonPin){
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        Serial.write("HALLO");
      }
    }
  }
  lastButtonState = reading;
}

void loop() {
    debounceButton(2);
  }
