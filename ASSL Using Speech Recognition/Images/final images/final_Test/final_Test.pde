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
  icon = startup_final;  // the 32 pixel high icon
 // icon2= images;
   GLCD.DrawBitmap(icon,0,0);
   delay(100);
   //GLCD.ClearScreen();
 
   delay(4000);
   GLCD.ClearScreen();
  

  // font for the default text area
  
}

void loop()
{
  
  if(Serial.available()>0)
    {    temp=Serial.read();
   
   if(temp=='A')
    { icon2= A;
    GLCD.ClearScreen();
    delay(100);
      GLCD.DrawBitmap(icon2,0,0);
      delay(3000);
    }
    else if(temp=='B')
     { icon2= B;
     GLCD.ClearScreen();
    delay(100);
      GLCD.DrawBitmap(icon2,0,0);
      delay(3000);
    }
      else if(temp=='C')
     { icon2= C;
      GLCD.DrawBitmap(icon2,0,0);
      delay(3000);
    }
    
      else if(temp=='D')
     { icon2= D;
     GLCD.ClearScreen();
    delay(100);
      GLCD.DrawBitmap(icon2,0,0);
      delay(3000);
    }
      else if(temp=='E')
     { icon2= E;
     GLCD.ClearScreen();
    delay(100);
      GLCD.DrawBitmap(icon2,0,0);
      delay(3000);
    }
      GLCD.ClearScreen();
    delay(100);
   
    }
     else
    {
      icon2= openhand;
      
      GLCD.DrawBitmap(icon2,0,0);
     
    }
     
     
    
      
  

}





