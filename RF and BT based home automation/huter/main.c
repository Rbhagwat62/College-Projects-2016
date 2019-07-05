#include<P89v51Rx2.h>
#include<delay.h>
#include<spi.h>
#include<RF24.h>
#include<USART.h>
#include<I2C.h>

void Init();

sbit CE =P1^0;
sbit CSN=P1^4;
sbit IRQ=P3^3;

sbit sw1=P2^3;




 sbit led0 =P0^0;


sbit MISO=P1^6;
sbit MOSI=P1^5;
sbit SCK=P1^7;
sbit hut=P2^7;

bit flag=0,st=0;
bit on=0;
//void transmit1(char)
unsigned char char_dec(char,char);
void EEEP();
//void transmit1(unsigned char da);



//int data_in[16];
//int rx_data[16],
unsigned char rx,teem[11],rc=0;
unsigned char eep[5];
//unsigned char defval[5]={0xE7,0xE7,0xE7,0xE7,0xE7};
unsigned char newaddrs[5];
//unsigned char data_in[10],rx_data[10];

external0_int() interrupt 2 
{
 unsigned char i;
  
 write_byt_addrs(0x07,0x40);
IE1=0;
SerialPrint(rc);

//USART_puts("\nint occured");
rx=receive();
teem[rc]=rx;
if(rx=='S')
{rc=0;
on=1;
USART_putc(rx);
transmit(rx);
transmit('A');
}

if(rx=='D')
{on=0;
hut=0;
}

if((rc==10)&&(teem[rc]=='T'))
	  {	USART_puts("\n the received string is");
		for(i=0;i<11;i++)
		USART_putc(teem[i]);
		USART_puts("\n in int");
		EEEP();
		rc=0;
		//USART_putc('f');
	  }
	  else
	  if(rx!='S')
	  rc++;
//SerialPrint(rc);
USART_putc(rx);
transmit(rx);

} 

void receive_byt()
{  unsigned char teem;
	if(RI==1)
	 {teem=SBUF;
	 RI=0;
	 transmit(teem);}
}
/*void transmit1(unsigned char da)
{
unsigned char i;
	for(i=0;i<9;i++)
	{
	transmit(da);
	if(rx=='#')
	i=10;
	}
}	*/

void EEEP()
{	unsigned char i,j=0;
	//short int temp;
	// USART_puts("\n in eep fun");
	 	
	
		for(i=0;i<10;i=i+2)
		{ USART_puts("\n in eeep");
		eep[j]=char_dec(teem[i],teem[i+1]);
		j++;

		//Write_I2C((i+2),eep);
		}
	
	/*for(i=0;i<10;i=i+2)
		{
		temp=Read_I2C(i+2);
		USART_puts("val");
		SerialPrint(temp);
		}*/
		/*for(j=0;j<5;j++)
		{USART_puts(" ");
		SerialPrint(eep[j]);
		 }*/

		Write_I2C(1,eep[0]);
		Write_I2C(2,15);
		Write_I2C(3,eep[1]);
		Write_I2C(4,15);
		Write_I2C(5,eep[2]);
		Write_I2C(6,15);
		Write_I2C(7,eep[3]);
		Write_I2C(8,15);
		Write_I2C(9,eep[4]);

		USART_puts("\n data in EProm");
		j=0;
		for(i=1;i<10;i=i+2)
		{USART_puts(" ");
		newaddrs[j]=(Read_I2C(i));
		SerialPrint(newaddrs[j]);
		j++;
		}
			

}

unsigned char char_dec(char a,char b)
{
unsigned char x,y,temp;
	
	if((a>='0')&&(a<='9'))
	x=a-'0';

	if((a>='A')&&(a<='F'))
	x=a-'A'+10;
	

	if((b>='0')&&(b<='9'))
	  y=b-'0';

	if((b>='A')&&(b<='F'))
	  y=b-'A'+10;
	  
	
	 x=x<<4;
	 x=x&0xf0;
	 

	 y=y&0x0f;
	 temp=(x|y);
	 SerialPrint(temp);
	 return(temp);
}


/*void transmit1(unsigned char text)
{
char i;
for(i=0;i<10;i++)
  {		 transmit(text);
  		delay(50);

		if(rx==text)
		i=10;

		if(i==9)
		USART_puts("fail to tansmit");
	}
	rx=0;
} */

void main()							   /////////main
{
	  unsigned char i,j;
	
//	USART_puts("\n the main loop");
 	Init();
	
	write_byt_addrs(0x00,0x3B);
	write_byt_addrs(0x01,0x00);
	write_byt_addrs(0x02,0x03);
	write_byt_addrs(0x11,0x01);
	write_byt_addrs(0x12,0x01);
	write_byt_addrs(0x05,0x02);
	write_byt_addrs(0x06,0x26);
	//write_addrs(0x10);

	read_byt_addrs(0x00,1);
	
	CSN=0;
	spiWrite(0xE1);
	CSN=1;
	CSN=0;
	spiWrite(0xE2);
	CSN=1;
	write_byt_addrs(0x0A,0x10);
	read_byt_addrs(0x0A,5);
	

	byt_write2();
	read_byt_addrs(0x0B,5);

    USART_puts("\n please enter text");
	
	j=0	;
	for(i=1;i<10;i=i+2)
		{
		newaddrs[j]=(Read_I2C(i));
		j++;
		}										 
	while(1)
	{		 // USART_puts("\nwhile loop");
			if(sw1==0)
				{//USART_puts("sw is zero");
				led0=1;
				flag=1;
				}
			  else
			  	{
				//USART_puts("switch is 1");
				led0=0;
				flag=0;
			//	st=0;
				}
			if((flag==1)&&(st==0))
			{byt_write1();
			USART_puts("\n default value");
			read_byt_addrs(0x10,5);
			st=1;}

			else if((flag==0)&&(st==1))
			{byt_write(0x10,newaddrs);
			USART_puts("setting new value");
			read_byt_addrs(0x10,5);
			st=0;
			flag=1;}  

			if((rx=='X')&&(on==1))
			{
			//transmit1('O');
			hut=1;
		
			}

									
			
			receive_byt();			
	}
}






void Init()
{
USART_Init();
CE=1;
CSN=1;
MOSI=0;
MISO=1;
SCK=0;
SPCTL=0xD0;
IEN0=0x94;
IP0H=0x04;
hut=0;
//led=0;
IRQ=1;
USART_puts("\ninitializing");
}


