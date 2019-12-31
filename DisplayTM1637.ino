#include <SevenSegmentTM1637.h>

const byte CLK = 9;
const byte DIO = 10;
SevenSegmentTM1637 display(CLK,DIO);

void setup() 
{
  Serial.begin(9600);
  display.begin();
  display.setBacklight(100);
}

void loop() 
{
  Serial.print("Good");
  display.print("Good");
  delay(1000);
  display.clear();
  for (int i=0;i<=20;i++)
  {
    Serial.print(i);
    display.print(i);
    delay(200);
  }
  display.print("DONE");
  Serial.println("DONE");
  delay(1000);
  display.clear();
  delay(1000);

}
