#include <LiquidCrystal.h>
const int trigPin =7,echo = 8 ;
 long duration;
 int distance;
  LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echo, INPUT);
// pinMode(m1, OUTPUT);
lcd.begin(16,2);
 lcd.print("ONlY CANS ALLOWED");

 Serial.begin(9600);
}

void loop() {
 
   
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(1000);
   digitalWrite(trigPin, LOW);
   
   duration = pulseIn(echo, HIGH);
   distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance); 
  if(distance <=20 && distance >=10)
 {
  Serial.println("ONlY CANS ALLOWED");
 lcd.display();
 delay(1000);
 
  //digitalWrite(m1, HIGH);
  //delay(100);
 
  }
  else 
  {
    lcd.noDisplay();
   // digitalWrite(m1, LOW);
  }
  delay(1000);
}
