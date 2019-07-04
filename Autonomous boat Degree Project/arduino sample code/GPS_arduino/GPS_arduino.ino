#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);  //RX, TX
char GPS_data[100];

void Setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  Serial.println("reading data from GPS");
}

void loop()
{
  
  if(mySerial.available()>1)
  {
    GPS_data=mySerial.readString();
    if(GPS_data.startsWith("$GPRMC")
    Serial.print(GPS_data);
  }
}
