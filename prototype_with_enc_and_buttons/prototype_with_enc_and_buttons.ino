// Robust Rotary encoder reading
//
// Copyright John Main - best-microcontroller-projects.com
//
#define CLK1 8
#define CLK2 9
#define CLK3 10
#define CLK4 11
#define CLK5 12
#define DATA1 0
#define DATA2 1
#define DATA3 2
#define DATA4 3
#define DATA5 7
#define button1 A0
#define button2 A1
#define button3 A2
#define button4 A3
#define button5 A4

volatile int pos = 0;
volatile int posB = 0;
volatile int posC = 0;
volatile int posD = 0;
volatile int posE = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int lastButtonState = HIGH;
int buttonState;
int debounceDone;

int buttonArray[] = {button1, button2, button3, button4, button5};

void interruptA(){
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 5){
  Serial.println("Signal from Data");
  if(digitalRead(CLK1) == LOW){
    pos ++;
    Serial.println(pos);
    Serial.write("A");
    }else{
      pos--;
      Serial.println(pos);
   Serial.write("A");
      }
     lastInterruptTime = interruptTime; 
  }
  
  }

void interruptB(){
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 5){
  Serial.println("Signal from Data");
  if(digitalRead(CLK2) == LOW){
    posB ++;
    Serial.println(posB);
    Serial.write("B");
    }else{
      posB--;
      Serial.println(posB);
   Serial.write("B");
      }
     lastInterruptTime = interruptTime; 
  }
  
  }

void interruptC(){
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 5){
  Serial.println("Signal from Data");
  if(digitalRead(CLK3) == LOW){
    posC ++;
    Serial.println(posC);
    Serial.write("C");
    }else{
      posC --;
      Serial.println(posC);
      Serial.write("C");
   
      }
     lastInterruptTime = interruptTime; 
  }
  
  }

  void interruptD(){
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 5){
  Serial.println("Signal from Data");
  if(digitalRead(CLK4) == LOW){
    posD ++;
    Serial.println(posD);
    Serial.write("D");
    }else{
      posD--;
      Serial.println(posD);
      Serial.write("D");
   
      }
     lastInterruptTime = interruptTime; 
  }
  
  }

void interruptE(){
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 5){
  Serial.println("Signal from Data");
  if(digitalRead(CLK5) == LOW){
    posE ++;
    Serial.println(posE);
    Serial.write("E");
    }else{
      posE--;
      Serial.println(posE);
      Serial.write("E");
   
      }
     lastInterruptTime = interruptTime; 
  }
  
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

void setup() {
  pinMode(DATA1, INPUT_PULLUP);
  pinMode(CLK1, INPUT_PULLUP);
  pinMode (DATA2, INPUT_PULLUP);
  pinMode(CLK2, INPUT_PULLUP);
  pinMode (DATA3, INPUT_PULLUP);
  pinMode(CLK3, INPUT_PULLUP);
  pinMode (DATA4, INPUT_PULLUP);
  pinMode(CLK4, INPUT_PULLUP);
  pinMode (DATA5, INPUT_PULLUP);
  pinMode(CLK5, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(DATA1), interruptA, LOW);
  attachInterrupt(digitalPinToInterrupt(DATA2), interruptB, LOW);
  attachInterrupt(digitalPinToInterrupt(DATA3), interruptC, LOW);
  attachInterrupt(digitalPinToInterrupt(DATA4), interruptD, LOW);
  attachInterrupt(digitalPinToInterrupt(DATA5), interruptE, LOW);
};

void loop(){
    
    debounceButton(button1);

  }
