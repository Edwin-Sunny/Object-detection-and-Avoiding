//THIS CODE IS CREATED BY SIDHARDH VINOD

int trigger= A0;
int echo= A1;
int revleft= 9;
int fwdleft= 8;
int revright= 7;
int fwdright= 6;
long duration,distance;
#include <Servo.h>
Servo myservo;
Servo myservohandleft;
Servo myservohandright;

void setup()
{ Serial.begin(9600);
  myservo.attach(11);
  myservohandright.attach(12);
  myservohandleft.attach(13);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(revleft,OUTPUT);
  pinMode(fwdleft,OUTPUT);
  pinMode(revright,OUTPUT);
  pinMode(fwdright,OUTPUT);
}
void loop()
{ digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration/58.2;
  Serial.println(distance);

if(distance > 30)
{ 
  digitalWrite(fwdright,HIGH);
  digitalWrite(revright,LOW);
  digitalWrite(fwdleft,HIGH);
  digitalWrite(revleft,LOW);

}
if(distance < 30)
{
  digitalWrite(fwdright,LOW); //STOP
  digitalWrite(revright,LOW);
  digitalWrite(fwdleft,LOW);
  digitalWrite(revleft,LOW);
  delay(100);
 
  int pos=0; // position
for(pos=0;pos<=180;pos++)
{
  myservo.write(pos);
  delay(10);
}
  for(pos=180;pos>=90;pos--)
{ myservo.write(pos);
  delay(10);
}

  digitalWrite(fwdright,LOW); //MOVE BACKWARD
  digitalWrite(revright,HIGH);
  digitalWrite(fwdleft,LOW);
  digitalWrite(revleft,HIGH);
  delay(500);
  digitalWrite(fwdright,LOW); //STOP
  digitalWrite(revright,LOW);
  digitalWrite(fwdleft,LOW);
  digitalWrite(revleft,LOW);
  delay(100);
  digitalWrite(fwdright,LOW); //RIGHT
  digitalWrite(revright,LOW);
  digitalWrite(fwdleft,HIGH);
  digitalWrite(revleft,LOW);
  delay(750);
  
 }
if(distance>32)
{
int pos=0; // position
for(pos=0;pos<=90;pos++)
{
  myservohandright.write(pos);
  delay(5);
}
  for(pos=90;pos>=0;pos--)
{ myservohandright.write(pos);
  delay(5);
}
}
if(distance>=32)
{
int pos=0; // position
for(pos=0;pos<=90;pos++)
{
  myservohandleft.write(pos);
  delay(5);
}
  for(pos=90;pos>=0;pos--)
{ myservohandleft.write(pos);
  delay(5);
}
}

}
