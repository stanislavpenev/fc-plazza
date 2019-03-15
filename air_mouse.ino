int fanPin = 3;
int inPin = 7;
int fanstate = 0;
int buttoncurrentstate = 0;
int buttonprevstate = LOW;
int tresshold = 50;
int waterlevel = A1;

void setup() {
  
  analogRead(waterlevel);
  pinMode(fanPin, OUTPUT);
  pinMode(inPin, INPUT_PULLUP);
  Serial.begin(9600);

}

void setUpFan(){

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
  buttonprevstate = buttoncurrentstate;
  buttoncurrentstate = digitalRead(inPin);
  waterlevel = analogRead(A1);

  
if (buttoncurrentstate == LOW && buttonprevstate == HIGH){   
   fanstate++;
   Serial.println((int)fanstate);
}


switch(fanstate){
  case 0 : 
    digitalWrite(fanPin, LOW);
    break;
  case 1 : 
    setUpFan();
    break;//digitalWrite(fanPin, LOW); 
  case 2 : 
    //Serial.println(tresshold);
    if(waterlevel > tresshold)
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
