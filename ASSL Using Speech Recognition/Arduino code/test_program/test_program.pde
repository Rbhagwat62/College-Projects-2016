#include <glcd.h>

#include "fonts/allFonts.h"         // system and arial14 fonts are used
#include "bitmaps/allBitmaps.h"       // all images in the bitmap dir 

Image_t icon;

void setup()
{
  GLCD.Init();   // initialise the library, non inverted writes pixels onto a clear screen
  
  icon = test1;  // the 32 pixel high icon
  
   GLCD.DrawBitmap(icon,0,0);
  //introScreen();
 // GLCD.ClearScreen(); 

  GLCD.SelectFont(System5x7, BLACK); // font for the default text area
}

void loop()
{

}


