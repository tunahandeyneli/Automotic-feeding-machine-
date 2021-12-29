#include <Servo.h> // including the library for servo
#define echopin 6  //defination of echopin
#define trigpin 7  //defination of trigpin
#define led_pin 8  //defination of ledpin 
#define myservo 10 //defination of servo motor's pin 
Servo motor;       //defination of servo motor
int duration;     //defination of duration
int distance;     //defination of distance



void setup() {
  pinMode(trigpin,OUTPUT);    // initialize digital trigpin as an output
  pinMode(echopin,INPUT);     // initialize digital echopin as an input
  pinMode(led_pin,OUTPUT);    // initialize digital ledpin   as an output
  motor.attach(myservo);      // associating servo with pin 10
  Serial.begin(9600);         // initialize serial communication


  
}

void loop() {
    digitalWrite(led_pin,HIGH); //turn the led on
    digitalWrite(trigpin,HIGH); //turn the trigpin on
    delayMicroseconds(2);       // wait for two microseconds
    digitalWrite(trigpin,LOW);  //turn the trigğin off 

  

  duration = pulseIn(echopin,HIGH);   // assign the duration
  distance = (duration/2) /29.1;          // calculation for distance

   Serial.print(" distance to object = ");   
   Serial.println(distance);                // send the duration
   delay(100);
  
  if( distance>5 && distance<30){       // condition

    motor.attach(myservo);        // attach servo
    motor.write(0);               // turn clockwise
    delay(600);                   // wait 
    motor.detach();               // detach servo
    delay(20000);                  // wait
    motor.attach(myservo);        // attach servo
    motor.write(180);             // turn counterclockwise
    delay(800);                   // wait
    motor.detach();               // detach servo
    delay(100);
    }
  else{
    motor.detach();      // other situation
    
  }
}
