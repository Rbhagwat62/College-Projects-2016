#define sen1 2
#define sen2 3
#define sen3 4
#define sen4 5



void setup() {
  pinMode(sen1,INPUT);
    pinMode(sen2,INPUT);
      pinMode(sen3,INPUT);
        pinMode(sen4,INPUT);
        Serial.begin(115200);

        Serial.println("begining of code");
  // put your setup code here, to run once:

}

void loop() {
  
  
  // put your main code here, to run repeatedly:
  if(digitalRead(sen1)==LOW)
  Serial.println("sen one");

   if(digitalRead(sen2)==LOW)
  Serial.println("sen 2");

 if(digitalRead(sen3)==LOW)
  Serial.println("sen 3");

 if(digitalRead(sen4)==LOW)
  Serial.println("sen 4");

}
