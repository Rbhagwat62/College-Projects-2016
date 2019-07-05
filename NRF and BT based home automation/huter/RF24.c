#include<spi.h>
#include<USART.h>
#include<P89v51Rx2.h>
#include<delay.h>
#include<HRD.h>

sbit CE =P1^0;
sbit CSN =P1^4;

void write_byt_addrs(unsigned char addr,unsigned char dat)
{//	unsigned char i;
	unsigned char address=addr+0x20;
	CSN=0;
	data_in[0]=spiWrite(address);
	data_in[1]=spiWrite(dat);
	 CSN=1;
}

void read_byt_addrs(unsigned char addr,unsigned char count)
{
	  unsigned char i=0;
	  CSN=0;
	  for(i=0;i<=count;i++)
	  data_in[i]=spiWrite(addr);
	 CSN=1;
	 
	 for(i=0;i<=count;i++)
	 { 
	 	USART_puts("\ndata_in\t");
		SerialPrint(i);
		USART_puts("\t");
		SerialPrint(data_in[i]);
	}
	
}

void transmit(unsigned char val)
{
//unsigned char i;
CSN=0;
data_in[0]=spiWrite(0xE1);
CSN=1;

CSN=0;
data_in[0]=spiWrite(0xA0);
data_in[1]=spiWrite(val);
CSN=1;

CE=0;
delay(1);
write_byt_addrs(0x00,0x3A);
delay(1);
CE=1;
delay(10);
write_byt_addrs(0x00,0x3B);
}


unsigned char receive()
{//unsigned char i;	 
CSN=0;
rx_data[0]=spiWrite(0x61);
rx_data[1]=spiWrite(0x00);
CSN=1;
delay(10);


CSN=0;
data_in[0]=spiWrite(0xE2);
CSN=1 ;
delay(1);
return rx_data[1];
}

void byt_write(unsigned char addrs,unsigned char val[5])
{
	unsigned char add;
	add=addrs+0x20;
	CSN=0;
	data_in[0]=spiWrite(add);
	data_in[1]=spiWrite(val[0]);
	data_in[2]=spiWrite(val[1]);
	data_in[3]=spiWrite(val[2]);
	data_in[4]=spiWrite(val[3]);
	data_in[5]=spiWrite(val[4]);
	CSN=1;
}
void byt_write1()
{
	unsigned char add;
	add=0x10+0x20;
	CSN=0;
	data_in[0]=spiWrite(add);
	data_in[1]=spiWrite(0xE7);
	data_in[2]=spiWrite(0xE7);
	data_in[3]=spiWrite(0xE7);
	data_in[4]=spiWrite(0xE7);
	data_in[5]=spiWrite(0xE7);
	CSN=1;
}


void byt_write2()
{
	unsigned char add;
	add=0x0B+0x20;
	CSN=0;
	data_in[0]=spiWrite(add);
	data_in[1]=spiWrite(0x45);
	data_in[2]=spiWrite(0xB1);
	data_in[3]=spiWrite(0xB1);
	data_in[4]=spiWrite(0xB1);
	data_in[5]=spiWrite(0xB1);
	CSN=1;
}

