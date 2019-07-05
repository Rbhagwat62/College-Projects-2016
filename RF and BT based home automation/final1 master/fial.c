#include<P89v51Rx2.h>
#include<USART.h>
#include<delay.h>
#include<I2C.h>
#include<RF24.h>
#include<spi.h>

sbit sw=P3^4;
sbit config=P3^5;

sbit l1=P2^0;
sbit l2=P2^1;
sbit l3=P2^2;
sbit l4=P2^3;
sbit l5=P2^4;
sbit l6=P2^5;
sbit l7=P2^6;
sbit l8=P2^7;

void Init();

sbit CE =P1^0;
sbit CSN=P1^4;
sbit IRQ=P3^3;

//sbit sw1=P0^0;

//sbit led1 =P0^1;

sbit MISO=P1^6;
sbit MOSI=P1^5;
sbit SCK=P1^7;

unsigned char rx[16];
unsigned char rx1;
unsigned char index=0;
volatile unsigned char temp; 
bit flag=0;

void EEEP(unsigned char ind);
void process();

void receive1()
{

	unsigned char c,i;
	if(RI==1)
	{
		c=SBUF;
		RI=0;

			if(config==0)
			{	 
				if(c=='s')
				{
					index=1;
				//	USART_puts("\nstart");
				}
				else 
				{
				rx[index]=c;
				
				//SerialPrint(index);
					if(c=='t')
					{
					temp=index;
					index=0;
					
		
				//	USART_puts("\ndone");
					USART_puts("PWD");
					for(i=2;i<temp;i++)
					{USART_putc(rx[i]);
					//USART_puts("\n");}
					
					}
					if(rx[1]=='p')
					EEEP(temp);
					
					}
					index++;
		
		
				}
			} 

			else
			{	 if(c=='s')
				  index=1;
				 else
				 {
					rx[index]=c;
					if(c=='t')
					{
					temp=index;
					index=0;
					process();
					}
					index++;
				}
			}
	RI=0;		
	}
}	

void EEEP(unsigned char ind)
{	unsigned char i=2,j=0;			  	
	while(i<=ind)
	{
		Write_I2C(j,rx[i]);
		Write_I2C(j+1,0);

		j=j+2;
		i++;
	}
	 	
			

}
void process()
{
	if((rx[1]==Read_I2C(0))&&(rx[2]==Read_I2C(2))&&(rx[3]==Read_I2C(4)))
		{

			if(rx[4]=='A')
			{
				if((rx[7]=='L')&&(rx[8]=='1'))
				l1=!l1;

				if((rx[7]=='L')&&(rx[8]=='2'))
				l2=!l2;

				if((rx[7]=='L')&&(rx[8]=='3'))
				l3=!l3;

				if((rx[7]=='L')&&(rx[8]=='4'))
				l4=!l4;

				if((rx[7]=='L')&&(rx[8]=='5'))
				l5=!l5;

				if((rx[7]=='L')&&(rx[8]=='6'))
				l6=!l6;

				if((rx[7]=='L')&&(rx[8]=='7'))
				l7=!l7;

				if((rx[7]=='L')&&(rx[8]=='8'))
				l8=!l8;
			}
			else if(rx[4]=='S')
			{
				if((rx[8]=='A')&&(rx[9]=='R')&&(rx[10]=='M'))
				{
				USART_putc(Read_I2C(0));
				USART_putc(Read_I2C(2));
				USART_putc(Read_I2C(4));
				USART_puts("SSGP01");
				transmit('G');
 				byt_write(0x10);
 				write_byt_addrs(0x10,0x45);
 				transmit('S');
 				write_byt_txd();
				}
				if((rx[8]=='D')&&(rx[9]=='R')&&(rx[10]=='M'))
				{
				USART_putc(Read_I2C(0));
				USART_putc(Read_I2C(2));
				USART_putc(Read_I2C(4));
				USART_puts("SSGP02");
				transmit('D');
 				byt_write(0x10);
 				write_byt_addrs(0x10,0x45);
 				transmit('D');
 				write_byt_txd();
				
				}
				if((rx[8]=='S')&&(rx[9]=='O')&&(rx[10]=='S'))
				{
				USART_putc(Read_I2C(0));
				USART_putc(Read_I2C(2));
				USART_putc(Read_I2C(4));
				USART_puts("SSGP03");
				byt_write(0x10);
 				write_byt_addrs(0x10,0x45);
 				transmit('X');
 				write_byt_txd();
				}

			}

		}
	else
	{
		USART_puts("\n not match");
		}
}

external0_int() interrupt 2 
{  
//USART_puts("\nint occured");
	rx1=receive();
	if(rx1=='X')
		{
 		transmit('#');
 		byt_write(0x10);
 		write_byt_addrs(0x10,0x45);
		delay(100);
 		transmit('X');
		delay(100);
 		write_byt_txd();
 		}
//transmit(rx);
write_byt_addrs(0x07,0x40);
IE1=0;
} 



void main()
{	   
//unsigned char i;


//unsigned char tem;

Init();

    write_byt_addrs(0x00,0x3B);
	write_byt_addrs(0x01,0x00);
	write_byt_addrs(0x02,0x03);
	write_byt_addrs(0x11,0x01);
	write_byt_addrs(0x12,0x01);
	write_byt_addrs(0x05,0x02);
	write_byt_addrs(0x06,0x26);
	//write_addrs(0x10)

	
	CSN=0;
	spiWrite(0xE1);
	CSN=1;
	CSN=0;
	spiWrite(0xE2);
	CSN=1;
	byt_write(0x0B);
	write_byt_addrs(0x0C,0x45);
	
	
	  
//USART_puts("\n start");


while(1)
	{
		receive1();
		
	}
}

void Init()
{
USART_Init();
//sw=1;
config=1;

l1=0;
l2=0;
l3=0;
l4=0;
l5=0;
l6=0;
l7=0;
l8=0;

CE=1;
CSN=1;
MOSI=0;
MISO=1;
SCK=0;
SPCTL=0xD0;
IEN0=0x94;
IP0H=0x04;
//led=0;
IRQ=1;
}

