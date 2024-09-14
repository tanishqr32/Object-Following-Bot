int PWM1= 2;
int PWM2= 5;
int SLEEP1=3;
int SLEEP2=7;
int DIR1=4;
int DIR2=6;
void setup() {
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(SLEEP1,OUTPUT);
  pinMode(SLEEP2,OUTPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(DIR2,OUTPUT);
  digitalWrite(SLEEP1,LOW);
  digitalWrite(SLEEP2,LOW);
  Serial.begin(9600);
  Serial.setTimeout(1);
}

void forward(int speed){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,speed);
     analogWrite(PWM2,speed);
}
//2
void right(int speed){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,0);
     analogWrite(PWM2,speed);
}
//3
void left(int speed){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,speed);
     analogWrite(PWM2,0);
}
//4
void stop(){
     digitalWrite(DIR1,HIGH);
     digitalWrite(DIR2,HIGH);
     analogWrite(PWM1,0);
     analogWrite(PWM2,0);
}
void loop() {
  //here we will write the code for communication with python
  if(Serial.available()>0){
   String data = Serial.readString();
   Serial.println(data);
   data.trim();
   if(data=="A"){left(100);}
   if(data=="B"){left(75);}
   if(data=="C"){right(75);}
   if(data=="D"){right(100);}
   if(data=="S"){stop();}
   if(data=="f"){forward(80);}
   if(data=="F"){forward(150);}
  }
  delay(50);

}