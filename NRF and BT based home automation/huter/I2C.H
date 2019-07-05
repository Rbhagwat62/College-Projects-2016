

sbit SDA = P3^7;		/* Set P3.7 = SDA */
sbit SCL = P3^6;		/* Set P3.6 = SCL */

#define I2C_DELAY 0x1F  //0x0f	/* For delay i2c bus */

 #define DS1307_ID  0xA0//	0xA0
void I2C_delay(void)
{
	unsigned char i;

	for(i=0; i<I2C_DELAY; i++);
}

void I2C_clock(void)
{
	I2C_delay();

	SCL = 1;		//Start clock

	I2C_delay();    

	SCL = 0;		//Clear SCL
}

void I2C_start(void)
{
	if(SCL)
	SCL = 0;		//Clear SCL

	SDA = 1;        //Set SDA
	SCL = 1;		//Set SCL

	I2C_delay(); 

	SDA = 0;        //Clear SDA

	I2C_delay(); 

	SCL = 0;        //Clear SCL
}

void I2C_stop(void)
{
	if(SCL)	
	SCL = 0;			//Clear SCL

	SDA = 0;			//Clear SDA
	I2C_delay();

	SCL = 1;			//Set SCL

	I2C_delay();

	SDA = 1;			//Set SDA
}

bit I2C_write(unsigned char dat)
{
	bit data_bit;		
	unsigned char i;	

	for(i=0;i<8;i++)				//A "for" loop being executed 8 times to send 1 -bute (8-bits) of data.
	{
		data_bit = dat & 0x80;		//Filter MSB bit keep to data_bit
		SDA = data_bit;				//Send data_bit to SDA

		I2C_clock();      			//Call for send data to i2c bus

		dat = dat<<1;  
	}

	SDA = 1;			//Set SDA

	I2C_delay();	
	
	SCL = 1;			//Set SCL

	I2C_delay();	

	data_bit = SDA;   	//Check acknowledge
	SCL = 0;			//Clear SCL

	I2C_delay();

	return data_bit;	//If send_bit = 0 i2c is valid
}

unsigned char I2C_read(void)
{
	bit rd_bit;	
	unsigned char i, dat;

	dat = 0x00;	

	for(i=0;i<8;i++)		//A "for" loop being executed 8 times to send 1 -bute (8-bits) of data.
	{
		I2C_delay();

		SCL = 1;			//Set SCL

		I2C_delay(); 

		rd_bit = SDA;		//Keep for check acknowledge
		dat = dat<<1;		
		dat = dat | rd_bit;	//Keep bit data in dat

		SCL = 0;			//Clear SCL
	}

	return dat;
}

void I2C_ack()
{
	SDA = 0;		//Clear SDA

	I2C_delay();    

	I2C_clock();	//Call for send data to i2c bus

	SDA = 1;		//Set SDA
}

void I2C_noack()
{
	SDA = 1;		//Set SDA

	I2C_delay();

	I2C_clock();	//Call for send data to i2c bus

	SCL = 1;		//Set SCL
}

void  Write_I2C(unsigned char addr ,unsigned char dat)
 {
	I2C_start();            	//Start I2C bus transaction;	

	I2C_write(DS1307_ID);		//connect to DS1307 
	I2C_write(addr);		//Request RAM address at 04H
	
	I2C_write(dat);			//Write date on RAM address 04H


	I2C_stop();			//Stop I2C bus
 }
  unsigned char Read_I2C(unsigned char addr)
  {
	unsigned char ret;	

	I2C_start();            	//Start I2C bus transaction

	I2C_write(DS1307_ID);   	//Connect to DS1307
	I2C_write(addr);		//Request RAM address on DS1307
	
	I2C_start();			//Start i2c bus

	I2C_write(DS1307_ID+1);		//Connect to DS1307 for Read
	ret = I2C_read();		//Receive data
	
	I2C_stop();			//Stop I2C bus
	return ret;
   }