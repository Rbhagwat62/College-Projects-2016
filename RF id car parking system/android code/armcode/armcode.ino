unsigned char data;     // to read data from xbee
int sensor1=4;          //four sensor connected to 4,5,6,7 pins
int sensor2=5;
int sensor3=6;
int sensor4=7;

boolean full;         //single bit variable to check parking full


void setup() {

  pinMode(sensor1,INPUT);   // define all pins as inputs
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
    
  Serial.begin(9600);       // Start serial communication of Default USb with 9600 use only for debug
  Serial1.begin(9600);      // start xbee connection connected at rx1 and tx1 pins with 9600
  // put your setup code here, to run once:
  Serial.println("begining");   //serial print begin

}

void loop() {
  
  if(Serial1.available())   //if any data is available on xbee module
 { data=Serial1.read();     // read data into variable
   Serial.println(data);    //print data on serial monitor only for debug
   if(data=='5')            // if 5 is receive then scan all sensor and send respective character over xbee
   {
    if(!digitalRead(sensor1))   //ACTIVE LOW  output vehicle is present
    Serial1.write('!');       //send ! char

    else
      Serial1.write('*');     
      
    
  
    if(!digitalRead(sensor2)) // for sensor 2 @, (
    Serial1.write('@');

    else
    Serial1.write('(');

    if(!digitalRead(sensor3))// for sensor 3 %,)
    Serial1.write('%');

    else
    Serial1.write(')');

    if(!digitalRead(sensor4)) //for sensor 4 ^,-
    Serial1.write('^');

    else
    Serial1.write('-');

    if((!digitalRead(sensor1))&&(!digitalRead(sensor2))&&(!digitalRead(sensor3))&&(!digitalRead(sensor4)))//check parking full or not
    Serial1.write('&');
    else
    Serial1.write('+');
    delay(10);
    Serial1.write('$'); // send $ to listen RF Tag 
   }

   
   
 }
  // put your main code here, to run repeatedly:

}
