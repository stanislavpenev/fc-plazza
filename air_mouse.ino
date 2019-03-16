int fanPin = 3;
int inPin = 7;
int fanState = 0;
int buttonCurrentState = 0;
int buttonPrevState = LOW;
int tresshold = 50;
int waterLevel = A1;
int waterSensor = 0;
int redPin=9;
int greenPin=5;
int bluePin=6;

void setUpFan();
void setColor(int redValue, int greenValue, int blueValue);

void setup() {
  pinMode(inPin, INPUT_PULLUP);
  pinMode(fanPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  waterSensor = analogRead(waterLevel);
  buttonPrevState = buttonCurrentState;
  buttonCurrentState = digitalRead(inPin);
  waterLevel = analogRead(A1);

  /*Checks button state*/
  if (buttonCurrentState == LOW && buttonPrevState == HIGH) {
    fanState++;
  }

  /*Switches working modes*/
  Serial.println((int)fanState);
  switch (fanState) {
    case 0 :
      digitalWrite(fanPin, LOW);
      break;
    case 1 :
      setUpFan();
      setColor(15, 255, 79);
      break;
    case 2 :
      setColor(109, 43, 175);
      if (waterLevel > tresshold)
        setUpFan();
      else
        digitalWrite(Pin, LOW);
      break;
    case 3 :
      fanState = 0;
      break;
  }
}

/*Sets color of RGB*/
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

/*Turns on the fan*/
void setUpFan() {
  digitalWrite(fanPin, HIGH);
}
