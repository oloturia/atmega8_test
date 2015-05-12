void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(5,OUTPUT); //fw motor 1
  pinMode(6,OUTPUT); //bk motor 1
  pinMode(7,OUTPUT); //fw motor 2
  pinMode(8,OUTPUT); //bk motor 2
  pinMode(9,OUTPUT); //analog motor 1
  pinMode(10,OUTPUT);//analog motor 2
}

void motorAction(int fwm, int bkm,int anm,int motspeed) {
      if (motspeed > 0 ) {
        digitalWrite(fwm,HIGH);
        digitalWrite(bkm,LOW);
      } else if (motspeed < 0) {
        digitalWrite(fwm,LOW);
        digitalWrite(bkm,HIGH);
      } else {
        digitalWrite(fwm,LOW);
        digitalWrite(bkm,LOW);
      }
      analogWrite(anm,abs(motspeed));
}

void loop() {
  int x;
  int y;
  while (Serial.available() >0) {
    int x = Serial.parseInt();
    int y = Serial.parseInt();
    if (Serial.read() == *"q") {
      motorAction(5,6,9,x);
      motorAction(7,8,10,y);
      Serial.print(x);
      Serial.print(" ");
      Serial.println(y);
    }
  }
}
