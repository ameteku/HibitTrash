#include <LiquidCrystal.h>
const int trigPin =7,echo = 8, buzzer =13, button =6 ;
 long duration;
 int distance;
  LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(button, INPUT);
 lcd.begin(16,2);
 lcd.print("  CANS ONLY!");

 Serial.begin(9600);
}

void loop() {

   int buttonCount = 0;
   int lastButtonState = 0;
  buttonCount = counting(lastButtonState);
  

   
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(1000);
   digitalWrite(trigPin, LOW);
   
   duration = pulseIn(echo, HIGH);
   distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance); 
  if(distance <=20 && distance >=1)
 {
  Serial.println("CANS ONLY");
  tone(buzzer, 500);
 lcd.display();
 delay(1000);
 noTone(buzzer);
  //digitalWrite(m1, HIGH);
  //delay(100);
 
  }
  else 
  {
    lcd.noDisplay();
   // digitalWrite(m1, LOW);
  }
  delay(100);
}
int counting (int initial )
{
  int count = 0;

  while(int x<=5)
  {
    
  int current =  digitalRead(button);
  
    if (initial != current)
    {
      count++;
      if(count=>3)
      {
        return count;
      };
    };
    x++;
  };
  return count;
}
