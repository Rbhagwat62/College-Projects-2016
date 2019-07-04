#include <string.h>
#include <SoftwareSerial.h>
#include <glcd.h>
#include <fonts/allFonts.h>
//#include "bitmaps/a1.h"
//#include "bitmaps/a2.h"
//#include "bitmaps/a3.h"
#include "bitmaps/allBitmaps.h" // all images in the bitmap folder

SoftwareSerial mySerial(12, 13); // RX, TX

#define SOP '<'
#define EOP '>'

bool started = false;
bool ended = false;

char inData[10];
byte index;

int i=0,stage=0,disp=1,x=1;
int ch;
char str1[10]="111111",str2[10]="222222",str3[10]="333333",str4[10]="444444",str5[10]="555555",str6[10]="666666",str7[10]="777777",str8[10]="888888",str9[10]="999999",str10[10]="BANANA",str11[10]="ORANGE",str12[10]="CHIKEN",str13[10]="FISHXX",str14[10]="CLDCFE",str15[10]="HOTCFE";
     
void setup()
{
  
Serial.begin(9600);

mySerial.begin(9600);
    
GLCD.Init(); // initialize the library
GLCD.SelectFont(System5x7);
GLCD.CursorTo(0,0);
GLCD.print("Project Guided By");
GLCD.CursorTo(0,1);
GLCD.print("Mrs A.P.Laturkar..");
delay(1000);

  GLCD.ClearScreen();
  GLCD.DrawBitmap(a1,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("BOING 707");
//  delay(500);
  GLCD.CursorTo(2,7);
//  delay(500);
  GLCD.print("WELCOME");
//  delay(500);
  GLCD.CursorTo(56,7);
//  delay(500);
  GLCD.print("---");
//  delay(500);
  GLCD.CursorTo(56,2);
//  delay(500);
  GLCD.print("----");
  delay(10000);
}

void loop()
{
    // Read all serial data available, as fast as possible
  while(mySerial.available() > 0)
  {
    char inChar = mySerial.read();
    if(inChar == SOP)
    {
       index = 0;
       inData[index] = '\0';
       started = true;
       ended = false;
    }
    else if(inChar == EOP)
    {
       ended = true;
       break;
    }
    else
    {
      if(index < 9)
      {
        inData[index] = inChar;
        index++;
        inData[index] = '\0';
      }
    }
  }

  // We are here either because all pending serial
  // data has been read OR because an end of
  // packet marker arrived. Which is it?
  if(started && ended)
  {
    // The end of packet marker arrived. Process the packet
  
  //  Serial.write(inData);
  
   strcpy(str1,inData);     

    // Reset for the next packet
    started = false;
    ended = false;
    index = 0;
    inData[index] = '\0';
  }
  
   if((strcmp(inData,str1)==0))
   {
     Serial.println("qqqq");
      GLCD.DrawBitmap(water,15,12); // draw your bitmap
      delay(500);

      GLCD.CursorTo(2,0);
      GLCD.print("WATER");
   }

   if((strcmp(inData,str2)==0))
   {
     Serial.println("qqqq");        GLCD.DrawBitmap(tea,15,12); // draw your bitmap
        delay(500);
      
        GLCD.CursorTo(2,0);
      //  delay(500);
        GLCD.print("TEA");
   }
   if((strcmp(inData,str3)==0))
   {     Serial.println("qqqq");
  GLCD.DrawBitmap(juice1,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("JUICE");
   }
   if((strcmp(inData,str4)==0))
   {    
  GLCD.DrawBitmap(pillow,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("PILLOW");
   }
   if((strcmp(inData,str5)==0))
   {
  GLCD.DrawBitmap(shhet,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("BED SHEET");
   }
   if((strcmp(inData,str6)==0))
   {
  GLCD.DrawBitmap(medicine,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("MEDICINE");
   }
   if((strcmp(inData,str7)==0))
   {
  GLCD.DrawBitmap(music,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("MUSIC");
   }
   if((strcmp(inData,str8)==0))
   {
  GLCD.DrawBitmap(movie2,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("MOVIE");
   }
   if((strcmp(inData,str9)==0))
   {
  GLCD.DrawBitmap(paper,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("PAPER");
   }
   if((strcmp(inData,str10)==0))
   {
  GLCD.DrawBitmap(banana,15,12); // draw your bitmap
  delay(500);
 Serial.println("BANANA");
  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("BANANA");
   }
   if((strcmp(inData,str11)==0))
   {
  GLCD.DrawBitmap(orange,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("ORANGE");
   }
   if((strcmp(inData,str12)==0))
   {
  GLCD.DrawBitmap(nvv1,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("CHICKEN");
   }
   if((strcmp(inData,str13)==0))
   {
  GLCD.DrawBitmap(fish,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("FISH");
   }
   if((strcmp(inData,str14)==0))
   {
  GLCD.DrawBitmap(coldcoffee,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("COLD COFFEE");
   }
   if((strcmp(inData,str15)==0))
   {
  GLCD.DrawBitmap(hotcoffee,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("HOT COFFEE");
   }
   
   
    delay(500);
}
