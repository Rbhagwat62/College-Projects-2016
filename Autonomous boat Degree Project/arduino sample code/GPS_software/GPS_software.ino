#include <SoftwareSerial.h>

//#include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 6);  //RX, TX
String GPS_data;

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  
  Serial.println("reading data from GPS");
}

void loop()
{
  
  if(mySerial.available()>0)
  {
    //GPS_data=mySerial.readString();
    //if(GPS_data.startsWith("$GPRMC"))
    
  }
}
