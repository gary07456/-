#include "SevSeg.h"
SevSeg sevseg;

void setup()
{
  Serial.begin(9600);
  Serial.print("group : 21\n"); 
  Serial.print("04050325\n"); 
 Serial.println("04050902");
 
  byte numDigits = 4;
  byte digitPins[] = {5,4,3,2};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);


}
void loop()
{
  int val;
    if(Serial.available())
    {
      val = Serial.parseInt();
      Serial.println(val);    
      if(val>=0 && val<10000)
      {
        sevseg.setNumber(val);
          sevseg.refreshDisplay();
        }
      else
        Serial.println("range error");  
      
      
    }
    else
            sevseg.refreshDisplay();

    
}
