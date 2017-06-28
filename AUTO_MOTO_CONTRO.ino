
 
#define trigger 10
#define echo 11
#define motor 8
#define buzzer 12
 

 
float time=0,distance=0;
int temp=0; 
long duration;
void setup()
{
 Serial.begin(9600);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(motor, OUTPUT);
 pinMode(buzzer, OUTPUT);
 digitalWrite(motor,HIGH);
 delay(2000);
}
 
void loop()
{
// Clears the trigPin
digitalWrite(trigger, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

 delay(2000);
 if(distance<18 && temp==0)
 {
     digitalWrite(motor,HIGH );
     digitalWrite(buzzer, HIGH);
     
     delay(2000);
     digitalWrite(buzzer, LOW);
     delay(3000);
     temp=1;
 }
 
 
 
 else if(distance>60)
 {
   digitalWrite(motor, LOW);
  
   delay(5000);
   temp=0;
 }
}
