//program to enter check whether the serial id is valid or not

#define logic1 13
#define logic2 12

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char data[17];




void setup()
{
  Serial.begin(9600);
  Serial.println("starting the RF Id based car parking program");
  pinMode(logic1,OUTPUT);
  pinMode(logic2,OUTPUT);
  
  
        digitalWrite(logic1,HIGH);
        digitalWrite(logic2,HIGH);
}

void loop()
{
  int i=0;
  char temp=0;
  if(Serial.available()>15)
  {
    for(i=0;i<16;i++)
    data[i]=Serial.read();
  
  
        if((strcmp(data,"1234567890123456")==0)||(strcmp(data,"9876543210987654")==0))
        {Serial.println("valid car");
        digitalWrite(logic1,HIGH);
        digitalWrite(logic2,LOW);
        delay(1000);
        digitalWrite(logic1,HIGH);
        digitalWrite(logic2,HIGH);
        delay(2000);
        digitalWrite(logic1,LOW);
        digitalWrite(logic2,HIGH);
        delay(1000);
        
        digitalWrite(logic1,HIGH);
        digitalWrite(logic2,HIGH);
        }
        
        
        
        else
        Serial.println("invalid car");
        
        for(i=0;i<16;i++)
        data[i]=0;
      
    }
}
