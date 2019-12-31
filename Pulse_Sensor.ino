#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h> 
#include <SevenSegmentTM1637.h>  
PulseSensorPlayground pulseSensor; 

const byte CLK = 9;
const byte DIO = 10;
SevenSegmentTM1637 display(CLK,DIO);

const int Pulse= A0;      
const int Led = 13;          
int Threshold = 150;            
                               
void setup()
{ 
  pinMode (Pulse,INPUT);  
  Serial.begin(9600); 
  display.begin();
  display.print("H bt");
  delay(1000);      
  pulseSensor.analogInput(Pulse);   
  pulseSensor.blinkOnPulse(Led);
  pulseSensor.setThreshold(Threshold);   
  if (pulseSensor.begin()) 
  {
    Serial.println("Pulse Sensor is ready to measure your Heart Beat....!"); 
  }
} 

void loop() 
{

 int myBPM = pulseSensor.getBeatsPerMinute();  
 if (pulseSensor.sawStartOfBeat()) 
 {            
 Serial.println("♥  A HeartBeat Happened ! "); 
 Serial.print("BPM:");                        
 Serial.println(myBPM);
 display.clear();
 display.print(myBPM);
                          
}
  delay(20);                 
}

  
