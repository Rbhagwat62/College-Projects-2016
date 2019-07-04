#include <glcd.h>
#include <fonts/allFonts.h>
//#include "bitmaps/a1.h"
//#include "bitmaps/a2.h"
//#include "bitmaps/a3.h"
#include "bitmaps/allBitmaps.h" // all images in the bitmap folder

#define PIN_Y1    12 // digi in 0
#define PIN_X2    13 // digi in 1
#define PIN_Y2    14 // analog input 0
#define PIN_X1    15 // analog input 0

#define XMID      500                  //    Touch screen refs
#define YMID      470                  //     

// stores the position from the touchscreen
int posX = 0;
int posY = 0;
int item=1,stage=0,disp=1,x=1;


void setup()
{
  
Serial.begin(9600);
    
GLCD.Init(); // initialize the library
GLCD.SelectFont(System5x7);
GLCD.CursorTo(0,0);
GLCD.print("Project Guided By");
GLCD.CursorTo(0,1);
GLCD.print("Mrs A.P.Laturkar..");
delay(1000);

Serial.println("HELLO HARSHAD");

  GLCD.ClearScreen();
  GLCD.DrawBitmap(a1,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("MENU");
//  delay(500);
  GLCD.CursorTo(2,7);
//  delay(500);
  GLCD.print("BACK");
//  delay(500);
  GLCD.CursorTo(56,7);
//  delay(500);
  GLCD.print("PREV");
//  delay(500);
  GLCD.CursorTo(56,2);
//  delay(500);
  GLCD.print("NEXT");
  delay(100);
}

void loop()
{
  pinMode(PIN_Y1, INPUT);
  pinMode(PIN_Y2, INPUT);
  pinMode(PIN_X1, OUTPUT);
  digitalWrite(PIN_X1, LOW);
  pinMode(PIN_X2, OUTPUT);
  digitalWrite(PIN_X2, HIGH);
  delay(1);                     // let things settle
  
  posX = analogRead(PIN_Y2); // read the X value
  

  // configuration for reading the y value
  pinMode(PIN_X1, INPUT);
  pinMode(PIN_X2, INPUT);
  pinMode(PIN_Y2, OUTPUT);
  digitalWrite(PIN_Y2, LOW);
  pinMode(PIN_Y1, OUTPUT);
  digitalWrite(PIN_Y1, HIGH);
  delay(1);                     // let things settle

    posY = analogRead(PIN_X1); // read the Y value

  // send position out over serial port


if((posX>(510))&(posY>(480)))
{
  item++;
  GLCD.ClearScreen();
  
    GLCD.CursorTo(2,0);
//  delay(500);
//  GLCD.print("MENU");
//  delay(500);
  GLCD.CursorTo(2,7);
//  delay(500);
  GLCD.print("BACK");
//  delay(500);
  GLCD.CursorTo(56,7);
//  delay(500);
  GLCD.print("PREV");
//  delay(500);
  GLCD.CursorTo(56,2);
//  delay(500);
  GLCD.print("NEXT");
  delay(100);

}

if((posX>(510))&(posY<(480)))
{
  item--;
  GLCD.ClearScreen();
  
    GLCD.CursorTo(2,0);
//  delay(500);
//  GLCD.print("MENU");
//  delay(500);
  GLCD.CursorTo(2,7);
//  delay(500);
  GLCD.print("BACK");
//  delay(500);
  GLCD.CursorTo(56,7);
//  delay(500);
  GLCD.print("PREV");
//  delay(500);
  GLCD.CursorTo(56,2);
//  delay(500);
  GLCD.print("NEXT");
  delay(100);

}

if((posX<(490))&(posY<(460)))
{
  if((item>=(6))&(item<=(30)))
  {
      item=1;
  }

  if((item>=(31))&(item<=(55)))
  {
      item=6;
  }

  if((item>=(56))&(item<=(80)))
  {
      item=11;
  }

  if((item>=(81))&(item<=(105)))
  {
      item=16;
  }

  if((item>=(106))&(item<=(130)))
  {
      item=21;
  }
  
    if((item>=(131))&(item<=(155)))
  {
      item=26;
  }
  stage--;
  
  GLCD.ClearScreen();
  
    GLCD.CursorTo(2,0);
//  delay(500);
//  GLCD.print("MENU");
//  delay(500);
  GLCD.CursorTo(2,7);
//  delay(500);
  GLCD.print("BACK");
//  delay(500);
  GLCD.CursorTo(56,7);
//  delay(500);
  GLCD.print("PREV");
//  delay(500);
  GLCD.CursorTo(56,2);
//  delay(500);
  GLCD.print("NEXT");
  delay(100);

}

if((posX <(510))&(posY>(480)))
{
  item=(item * 5) + 1;
  stage++;

if(item>155)
  item=1;
 // Serial.print(item);
  GLCD.ClearScreen();
  
    GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("MENU");
//  delay(500);
  GLCD.CursorTo(2,7);
//  delay(500);
  GLCD.print("BACK");
//  delay(500);
  GLCD.CursorTo(56,7);
//  delay(500);
  GLCD.print("PREV");
//  delay(500);
  GLCD.CursorTo(56,2);
//  delay(500);
  GLCD.print("NEXT");
  delay(100);

}

/*
  Serial.print(posX);
  Serial.print(",");
  Serial.print(posY);
  Serial.print(",");
  Serial.print(item);
  Serial.print(",");
  Serial.println(stage);
  
  delay(18);                    // wait 18ms (total 20ms)

*/
//disp=(stage*item)+citem;
//disp=arr[item];                //  formula for disp
//switch(disp)

switch(item)
{
  case 0:

//  GLCD.ClearScreen();
  GLCD.DrawBitmap(a1,15,12); // draw your bitmap
  delay(500);
  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("MENU CARD");
  
  break;
  
  case 1:
 // GLCD.ClearScreen();
  GLCD.DrawBitmap(food,15,12); // draw your bitmap
  delay(500);
  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("FOOD");
 
  break;

  case 2:
 // GLCD.ClearScreen();
  GLCD.DrawBitmap(drink,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("DRINKS");
  
  break;

  case 3:
 // GLCD.ClearScreen();
  GLCD.DrawBitmap(a8,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("ACCESSORIES");
  
  break;

  case 4:
 // GLCD.ClearScreen();
  GLCD.DrawBitmap(firstaid1,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("FIRST AID");
  
  break;

  case 5:
 // GLCD.ClearScreen();
  GLCD.DrawBitmap(movie3,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("ENTERTAINMENT");
  
  break;

  case 6:
 // GLCD.ClearScreen();
  GLCD.DrawBitmap(apple,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("VEG");
  
  break;

  case 7:
 // GLCD.ClearScreen();
  GLCD.DrawBitmap(nvv2,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("NON VEG");
  
  break;
  
/*  case 8:
  break;

  case 9:
  break;

  case 10:
  break;
*/
  case 11:
  //GLCD.ClearScreen();
  GLCD.DrawBitmap(water,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("WATER");

  Serial.print("<111111>"); 
  delay(10);  
  
  break;

  case 12:
 // GLCD.ClearScreen();
  GLCD.DrawBitmap(tea,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("TEA");

  Serial.print("<222222>"); 
  delay(10);  
  
  break;

  case 13:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(a4,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("COFFEE");
  
    break;

  case 14:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(juice1,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("JUICE");
  
  Serial.print("<333333>"); 
  delay(10);  
  
  break;
  
/*  case 15:
  break;
  */
  
  case 16:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(pillow,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("PILLOW");
  
    Serial.print("<444444>"); 
  delay(10);  
  
  break;
  case 17:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(shhet,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("BED SHEET");
  
    Serial.print("<555555>"); 
  delay(10);  
  
  break;
  
 /* case 18:
  break;

  case 19:
  break;

  case 20:
  break;
*/
  case 21:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(medicine,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("MEDICINE");
  
    Serial.print("<666666>"); 
  delay(10);  

  
  break;
  
/*  case 22:
  break;

  case 23:
  break;

  case 24:
  break;

  case 25:
  break;
  */
  case 26:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(music,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("MUSIC");
  
    Serial.print("<777777>"); 
  delay(10);  

  
  break;
  case 27:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(movie2,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("MOVIE");
  
    Serial.print("<888888>"); 
  delay(10);  

  
  break;

case 28:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(paper,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("NEWSPAPER");
  
    Serial.print("<999999>"); 
  delay(10);  

  
  break;
/*
case 29:
break;

case 30:
break;
*/
case 31:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(banana,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("BANANA");
  
    Serial.print("<BANANA>"); 
  delay(10);  

  break;
case 32:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(orange,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("ORANGE");
  
    Serial.print("<ORANGE>"); 
  delay(10);  

  
  break;
  
 /* case 33:
  break;
  
    case 34:
  break;
  
    case 35:
  break;
 */
case 36:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(nvv1,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("CHICKEN");
  
    Serial.print("<CHIKEN>"); 
  delay(10);  

  
  break;
  
case 37:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(nv3,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("FISH");
  
    Serial.print("<FISHXX>"); 
  delay(10);  

  
  break;
  
case 66:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(coldcoffee,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("COLD COFFEE");
  
    Serial.print("<CLDCFE>"); 
  delay(10);  
  
  break;
  
case 67:
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(hotcoffee,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("HOT COFFEE");
  
    Serial.print("<HOTCFE>"); 
  delay(10);  

  
  break;

  default:
  
//  GLCD.ClearScreen();
  GLCD.DrawBitmap(a1,15,12); // draw your bitmap
  delay(500);

  GLCD.CursorTo(2,0);
//  delay(500);
  GLCD.print("FATAL ERROR");
  
  break;
}

     delay(100);
     //while(1);
}
