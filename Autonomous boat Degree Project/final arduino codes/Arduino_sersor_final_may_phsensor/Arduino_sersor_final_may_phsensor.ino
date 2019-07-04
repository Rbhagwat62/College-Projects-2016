//connect 3.3v to AREF

#include <SoftwareSerial.h>
#include <TinyGPS.h>

#include <Wire.h>
#include <HMC5883L.h>
#include<String.h>

SoftwareSerial ss(4, 3);
TinyGPS gps;

float flat, flon;
boolean newData = false;
 
    
HMC5883L compass;

float headingDegrees;
float speed_gps;

String final_str;

const int ap1 = A0; 
const int ap2 = A1;
const int ap3 = A2;
const int ph_sen=A3;

int sv1 = 0;        
int ov1 = 0;    
int sv2 = 0;      
int ov2= 0;      
int sv3 = 0;       
int ov3= 0;    

float ph;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(115200);
  ss.begin(9600);
  com_init();
  
}

void loop() {
 newData = false;
  ACC();
  comp_read();
  GPS_data();
  ph_read();
  
  
  final_str="";
  final_str=String("12345");
  final_str+=String(",");
    

  if(newData)
  {
   // Serial.println("getting logn lat");
  final_str+=String(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
  final_str+=String(",");
  final_str+=String(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
  final_str+=String(",");
  final_str+=String(speed_gps);
  final_str+=String(",");
    
  }

  else
  {
    final_str+=String("0");
    final_str+=String(",");
    final_str+=String("0");
    final_str+=String(",");
    final_str+=String("0");
    final_str+=String(",");
    
  }
  
  final_str+=String(ov1,DEC);
  final_str+=String(",");
  final_str+=String(ov2,DEC);
  final_str+=String(",");
  final_str+=String(ov3,DEC);
  final_str+=String(",");
  final_str+=String(headingDegrees,DEC);
  final_str+=String(",");
  final_str+=String(ph);
 
  Serial.println(final_str); 

  delay(500);                     
  
}

