
#include<P89v51Rx2.h>
#include<stdio.h>
//#include<USART.h>

 void USART_Init()	//             USART 
{
//unsigned char c;
 TMOD=0x20;
 TH1=0xFD;
 SCON=0x50;
 TR1=1;
 IEN0=0x90;
}			  


void USART_putc(unsigned char c)	  ///////USART
{
    SBUF=c;														
	while(!TI);
	TI=0;
    
}


void USART_puts(unsigned char *s)	 ///////USART
{
    while(*s)
    {
        USART_putc(*s);
        s++;

    }
}
				  

void SerialPrint (int arg)
{
unsigned char NumArray[10];
// Convert number into string
sprintf (NumArray, "%d", arg);
// Send string to HyperTerminal
USART_puts(NumArray);
} // End of SerialPrint

void byte_to_bin(int temp)
{
unsigned char buf[8];
int k=0;
int t=0;


for(k=0;k<8;k++)
	buf[k]='0';
k=7;
USART_puts(buf);
   
while(temp>1)
	{

	t=temp%2;
	temp/=2;
	if(t==1)
	buf[k]='1';

	else
	buf[k]='0';
	
	k--;
	
	}
	

		if(temp==1)
		buf[k]='1';

		else
		buf[k]='0';
	USART_puts(buf);
}
void dec_to_hex(int temp)
{
unsigned char buf[2];
int k=0;
int t=0;


for(k=0;k<2;k++)
	buf[k]='0';
k=2;
USART_puts(buf);
   
while(temp>15)
	{

	t=temp%16;
	temp/=16;
	
	if(t<10)
	buf[k]='0'+t;

	else
	buf[k]=('A'+(t-10));
	
	
	k--;
	
	}
	

		if(temp<10)
     	buf[k]='0'+temp;

		else
		buf[k]=('A'+(temp-10));

	USART_puts(buf);
}
