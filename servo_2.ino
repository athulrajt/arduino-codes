    #include <Servo.h> 
     
    Servo myservo1; 
    Servo myservo2;
    int pos1 = 90;
    int pos2 = 90;     // initial position
    int sens1 = A0; // LRD 1 pin
    int sens2 = A1; //LDR 2 pin
    int tolerance = 9;
     
    void setup() 
    { 
      Serial.begin(9600);
      myservo1.attach(9);  // attaches the servo on pin 9 to the servo object 
      myservo2.attach(7);  // attaches the servo on pin 8 to the servo object  
      pinMode(sens1, INPUT);
      pinMode(sens2, INPUT);
      myservo1.write(pos1);
      myservo2.write(pos2);
      delay(2000); // a 2 seconds delay while we position the solar panel
    }  
     
    void loop() 
    { 
      int val1 = analogRead(sens1); // read the value of sensor 1
      int val2 = analogRead(sens2); // read the value of sensor 2
      Serial.println(val1);
      Serial.println(val2);
      
      
     
      if((abs(val1 - val2) <= tolerance) || (abs(val2 - val1) <= tolerance)) {
        //do nothing if the difference between values is within the tolerance limit
      } else {    
        if(val1 > val2)
        {
          pos1 = --pos1;
          pos2 = ++pos2;
        }
        if(val1 < val2) 
        {
          
          pos1 = ++pos1;
          pos2 = --pos2;
         
        }
      }
     
      if(pos1 > 180) { pos1 = 180; } // reset to 180 if it goes higher
      if(pos1 < 0) { pos1 = 0; } // reset to 0 if it goes lower\
      
      if(pos2 < 0) { pos2 = 0; } // reset to 0 if it goes lower
      if(pos2 > 180) { pos2 = 180; } // reset to 180 if it goes higher
      
      
      myservo1.write(pos1); 
      myservo2.write(pos2);
     // write the position to servo
      delay(45);
    }
