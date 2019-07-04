

/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>
#include <openGLCD.h>

#include "fonts/allFonts.h"         // system and arial14 fonts are used
#include "bitmaps/allBitmaps.h"       // all images in the bitmap dir 

Image_t icon;
Image_t icon2;

boolean v_one,v_two,v_three,v_four,full;

unsigned char temp;

SoftwareSerial mySerial(12, 13); // RX, TX

SoftwareSerial RFid(2,3); // RX, TX
char data[14];
long time1=0;

void setup() {
  v_one=false;
  v_two=false;
  v_three=false;
  v_four=false;
  full=false;
  // Open serial communications and wait for port to open:

  pinMode(3,OUTPUT);
  pinMode(A5,OUTPUT);

  digitalWrite(3,HIGH);
  digitalWrite(A5,HIGH);
 
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


 // Serial.println("Goodnight moon!");
  

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
 // mySerial.println("Hello, world?");
   RFid.begin(9600);

    GLCD.Init();   // initialise the library, non inverted writes pixels onto a clear screen
  //Serial.begin(9600);
 // Serial.print("welcome to GLCD\n");
  icon = startup;  // the 32 pixel high icon
 // icon2= images;
   GLCD.DrawBitmap(icon,0,0);
   delay(2000);
   GLCD.ClearScreen();
}

void loop() { // run over and over

 if(millis()-time1>2000)
   {
    time1=millis();
     mySerial.println("12345");
   mySerial.listen();
  while (mySerial.available()) {
    unsigned char recv;
    recv=mySerial.read();
    if(recv=='$')
    RFid.listen();

    if(recv=='!')
    v_one=true;

    if(recv=='@')
    v_two=true;
    
    if(recv=='%')
    v_three=true;

    if(recv=='^')
    v_four=true;

    if(recv=='&')
    full=true;

    if(recv=='*')
    v_one=false;

    
    if(recv=='(')
    v_two=false;

    if(recv==')')
    v_three=false;

    
    if(recv=='-')
    v_four=false;

    
    if(recv=='+')
    full=false;
    
    
    
  }
   // Serial.write(mySerial.read());
    
  }
    
      if(RFid.available()>=12)
      {
     // data="";
       for(int i=0;i<12;i++)
      data[i]=RFid.read();
      
      //data+=String(" ");
      Serial.println(data);
      }
    
    
  
  if (Serial.available()) {
    unsigned char x=Serial.read();
    //mySerial.write(Serial.read());
    if(x=='#')
    {  
      digitalWrite(3,HIGH);
      digitalWrite(A5,LOW);
      delay(200);

      digitalWrite(3,HIGH);
      digitalWrite(A5,HIGH);
      delay(7000);

      digitalWrite(3,LOW);
      digitalWrite(A5,HIGH);

      delay(200);

      digitalWrite(3,HIGH);
      digitalWrite(A5,HIGH);
      
     // mySerial.println("12345");
     // mySerial.listen();
      
    }
      if(x=='*')
    {  
      digitalWrite(3,HIGH);
      digitalWrite(A5,LOW);
      delay(200);

      digitalWrite(3,HIGH);
      digitalWrite(A5,HIGH);
      delay(7000);

      digitalWrite(3,LOW);
      digitalWrite(A5,HIGH);

      delay(200);

      digitalWrite(3,HIGH);
      digitalWrite(A5,HIGH);
      
     
      
    }
  }

  if(full==false)
  {
   // icon=Nopark;
    //GLCD.DrawBitmap(icon,0,0);

          if((v_four==false)&&(v_three==false)&&(v_two==false)&&(v_one==false))
          {
          icon=zero;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          
          if((v_four==false)&&(v_three==false)&&(v_two==false)&&(v_one==true))
          {
          icon=one;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==false)&&(v_three==false)&&(v_two==true)&&(v_one==false))
          {
          icon=two;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==false)&&(v_three==false)&&(v_two==true)&&(v_one==true))
          {
          icon=three;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==false)&&(v_three==true)&&(v_two==false)&&(v_one==false))
          {
          icon=four;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==false)&&(v_three==true)&&(v_two==false)&&(v_one==true))
          {
          icon=five;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==false)&&(v_three==true)&&(v_two==true)&&(v_one==false))
          {
          icon=six;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==false)&&(v_three==true)&&(v_two==true)&&(v_one==true))
          {
          icon=seven;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==true)&&(v_three==false)&&(v_two==false)&&(v_one==false))
          {
          icon=eight;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==true)&&(v_three==false)&&(v_two==false)&&(v_one==true))
          {
          icon=nine;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==true)&&(v_three==false)&&(v_two==true)&&(v_one==false))
          {
          icon=A;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==true)&&(v_three==false)&&(v_two==true)&&(v_one==true))
          {
          icon=B;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==true)&&(v_three==true)&&(v_two==false)&&(v_one==false))
          {
          icon=C;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==true)&&(v_three==true)&&(v_two==false)&&(v_one==true))
          {
          icon=D;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==true)&&(v_three==true)&&(v_two==true)&&(v_one==false))
          {
          icon=E;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
          if((v_four==true)&&(v_three==true)&&(v_two==true)&&(v_one==true))
          {
          icon=zero;
          GLCD.DrawBitmap(icon,0,0);
          delay(200);
          }
    }
    else
    {
    icon=PF;
    GLCD.DrawBitmap(icon,0,0);
    }
    
    
    
  
}

