#include <glcd.h>
#include <stdio.h>


#include "fonts/allFonts.h"         // system and arial14 fonts are used
#include "bitmaps/allBitmaps.h"       // all images in the bitmap dir 

Image_t icon;
Image_t icon2;

unsigned char temp;
char receive_matlab_data[5];
unsigned char receive_data_index=0;

void display_images();

void setup()
{
  GLCD.Init();   // initialise the library, non inverted writes pixels onto a clear screen
  
  Serial.begin(9600);
  //Serial.print("welcome to GLCD\n");
  icon = startup;  // the 32 pixel high icon
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
  int var;
  if(Serial.available()>0)
    {    temp=Serial.read();
         receive_matlab_data[receive_data_index]=temp;
    
        if((temp=='*')&&(receive_data_index==0))
        receive_data_index=1;
        
        else if(receive_data_index>0)
        {
          if(temp=='$')
          {
            display_images();
            receive_data_index=0;
          }
          else
          receive_data_index++;
        }
    }
    
    {
      icon2= openhand;
      
      GLCD.DrawBitmap(icon2,0,0);
     
   }
   
}





