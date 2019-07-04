#include <glcd.h>

#include "fonts/allFonts.h"         // system and arial14 fonts are used
#include "bitmaps/allBitmaps.h"       // all images in the bitmap dir 

Image_t icon;
Image_t icon2;

unsigned char temp;

void setup()
{
  GLCD.Init();   // initialise the library, non inverted writes pixels onto a clear screen
  Serial.begin(9600);
  Serial.print("welcome to GLCD\n");
  icon = logo;  // the 32 pixel high icon
  icon2= images;
   GLCD.DrawBitmap(icon,0,0);
   delay(100);
   //GLCD.ClearScreen();
    GLCD.SelectFont(Arial14);
   GLCD.CursorTo(6, 1);
   GLCD.print("American");
   GLCD.CursorTo(6, 2);
    GLCD.print("Standard");
    
   GLCD.CursorTo(6, 3);
    GLCD.print("Sign Lang.");
    
   //GLCD.CursorTo(6, 4);
    //GLCD.print("Lang.");
   delay(1000);
   GLCD.ClearScreen();
  

  // font for the default text area
  
}

void loop()
{
  
  if(Serial.available()>1)
    {    temp=Serial.read();
   
   if(temp=='A')
    { icon2= A;
      GLCD.DrawBitmap(icon2,0,0);
      GLCD.CursorTo(6, 1);
      GLCD.print("A");
      delay(1000);
    }
    else if(temp=='B')
     { icon2= B;
      GLCD.DrawBitmap(icon2,0,0);
      GLCD.CursorTo(6, 1);
      GLCD.print("B");
      delay(1000);
    }
      else if(temp=='C')
     { icon2= C;
      GLCD.DrawBitmap(icon2,0,0);
      GLCD.CursorTo(6, 1);
      GLCD.print("C");
      delay(1000);
    }
    
      else if(temp=='D')
     { icon2= D;
      GLCD.DrawBitmap(icon2,0,0);
      GLCD.CursorTo(6, 1);
      GLCD.print("D");
      delay(1000);
    }
      else if(temp=='E')
     { icon2= E;
      GLCD.DrawBitmap(icon2,0,0);
      GLCD.CursorTo(6, 1);
      GLCD.print("E");
      delay(1000);
    }
    }
     
     GLCD.ClearScreen();
    
      
  

}




