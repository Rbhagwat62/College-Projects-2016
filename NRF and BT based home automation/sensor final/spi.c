#include<P89v51Rx2.h>

int spiWrite(int sendbyte)					  //////SPI command dont kow wheather works or not...:D
{	SPDAT=sendbyte;
	while((SPCFG & 0x80)!= 0x80);
	SPCFG=0x00;
	return(SPDAT);
}

