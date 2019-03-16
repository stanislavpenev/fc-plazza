int fanPin = 3;
int inPin = 7;
int fanstate = 0;
int buttoncurrentstate = 0;
int buttonprevstate = LOW;
int tresshold = 0;
int waterlevel = A1;
int waterSensor = 0;



void setup() {
  pinMode(inPin, INPUT_PULLUP);
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);

}

void setUpFan() {

  digitalWrite(fanPin, HIGH);
  //delay(5000);
  //digitalWrite(fanPin, LOW);

}

void loop() {



  /*
    val = digitalRead(inPin);
    if (val == HIGH){
    digitalWrite(fanPin, LOW);
    } else {
    digitalWrite(fanPin, HIGH);
    }
  */
  waterSensor = analogRead(waterlevel);
  buttonprevstate = buttoncurrentstate;
  buttoncurrentstate = digitalRead(inPin);
  waterlevel = analogRead(A1);
 // Serial.println(waterSensor);

  if (buttoncurrentstate == LOW && buttonprevstate == HIGH) {
    fanstate++;
//    Serial.println((int)fanstate);
  }

  Serial.println((int)fanstate);
  switch (fanstate) {
    case 0 :
      digitalWrite(fanPin, LOW);
      break;
    case 1 :
      setUpFan();
      break;//digitalWrite(fanPin, LOW);
    case 2 :
      //Serial.println(tresshold);
      if (waterlevel > tresshold)
        setUpFan();
      //digitalWrite(fanPin, HIGH);
      else
        digitalWrite(fanPin, LOW);

      break;
    case 3 :
      fanstate = 0;
      break;
  }

  /*if(fanstate == 0){

    }

    if(fanstate == 1){

    }
    if(fanstate == 2){

    }

    if(fanstate == 4){

    }*/
  //Serial.println((int)waterlevel);
}
