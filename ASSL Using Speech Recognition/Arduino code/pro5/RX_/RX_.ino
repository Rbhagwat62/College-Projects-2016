#include <string.h>
#include <SoftwareSerial.h>
#include <glcd.h>
#include <fonts/allFonts.h>
#include "bitmaps/allBitmaps.h" // all images in the bitmap folder

SoftwareSerial mySerial(0, 1); // RX, TX

#define SOP '<'
#define EOP '>'

bool started = false;
bool ended = false;

char inData[10];
byte index;

int i=0,stage=0,disp=1,x=1;
int ch;
char str1[10]="WATER";
char str2[10]="TEA";
char str3[10]="JUICE";
char str4[10]="PILLOW";
char str5[10]="BDSHET";
char str6[10]="MDCINE";
char str7[10]="MUSIC"; 
char str8[10]="MOVIE"; 
char str9[10]="NWSPPR";
char str10[10]="BANANA";
char str11[10]="ORANGE";
char str12[10]="CHICKEN";
char str13[10]="FISH";
char str14[10]="CLDCOFE";
char str15[10]="HTCOFE";
     
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
  GLCD.print("----");
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
  
  Serial.write(inData);
  
  
   strcpy(str1,inData);     

    // Reset for the next packet
    started = false;
    ended = false;
    index = 0;
    inData[index] = '\0';
  }
  
   if((strcmp(inData,str1)==0))
   {GLCD.ClearScreen();
     Serial.println("WATER");
     
      GLCD.DrawBitmap(water,15,12); // draw your bitmap
      delay(500);
      GLCD.CursorTo(2,0);
      GLCD.print("WATER");
      break;
   }

   if((strcmp(inData,str2)==0))
   {GLCD.ClearScreen();
      Serial.println("TEA");
     
      GLCD.DrawBitmap(tea,15,12); // draw your bitmap
      delay(500);
      GLCD.CursorTo(2,0);
      //  delay(500);
      GLCD.print("TEA");
        break;
   }
   
   if((strcmp(inData,str3)==0))
   { GLCD.ClearScreen();    
     Serial.println("JUICE");
   
     GLCD.DrawBitmap(juice1,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("JUICE");
       break;
   }
   
   if((strcmp(inData,str4)==0))
   { GLCD.ClearScreen();
     Serial.println("PILLOW");
     
     GLCD.DrawBitmap(pillow,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("PILLOW");
       break;
   }
   
   if((strcmp(inData,str5)==0))
   { 
     GLCD.ClearScreen();
     Serial.println("BDSHET");
    
     GLCD.DrawBitmap(shhet,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("BED SHEET");
       break;
   }
   
   if((strcmp(inData,str6)==0))
   {GLCD.ClearScreen();
     Serial.println("MDCINE");
     
     GLCD.DrawBitmap(medicine,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("MEDICINE");
       break;
   }
   
   if((strcmp(inData,str7)==0))
   {GLCD.ClearScreen();
     Serial.println("MUSIC");
    
     GLCD.DrawBitmap(music,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("MUSIC");
       break;
   }
   
   if((strcmp(inData,str8)==0))
   {Serial.println("MOVIE");
   GLCD.ClearScreen();
     GLCD.DrawBitmap(movie2,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("MOVIE");
       break;
   }
   
   if((strcmp(inData,str9)==0))
   {Serial.println("NWSPPR");
     GLCD.ClearScreen();
     GLCD.DrawBitmap(paper,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("NEWSPAPER");
       break;
   }
   
   if((strcmp(inData,str10)==0))
   {
     
     Serial.println("BANANA");
     GLCD.ClearScreen();
     GLCD.DrawBitmap(banana,15,12); // draw your bitmap
     delay(500);
     
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("BANANA");
       break;
    
     
   }
   
   if((strcmp(inData,str11)==0))
   {Serial.println("ORANGE");
     GLCD.ClearScreen();
     GLCD.DrawBitmap(orange,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("ORANGE");
       break;
   }
   
   if((strcmp(inData,str12)==0))
   {Serial.println("CHICKEN");
     GLCD.ClearScreen();
     GLCD.DrawBitmap(nvv1,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("CHICKEN");
       break;
   }
   
   if((strcmp(inData,str13)==0))
   {Serial.println("FISH");
     GLCD.ClearScreen();
     GLCD.DrawBitmap(fish,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("FISH");
       break;
   }
   
   if((strcmp(inData,str14)==0))
   {Serial.println("CLDCOFE");
    GLCD.ClearScreen();
     GLCD.DrawBitmap(coldcoffee,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("COLD COFFEE");
       break;
   }
   
   if((strcmp(inData,str15)==0))
   {Serial.println("HTCOFE");
    GLCD.ClearScreen();
     GLCD.DrawBitmap(hotcoffee,15,12); // draw your bitmap
     delay(500);
     GLCD.CursorTo(2,0);
     //  delay(500);
     GLCD.print("HOT COFFEE");
       break;
   }
   
   
    delay(500);
}
