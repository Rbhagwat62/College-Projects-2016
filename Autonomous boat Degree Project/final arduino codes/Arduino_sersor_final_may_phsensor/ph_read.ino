void ph_read()
{
  analogReference(DEFAULT);
 int sensorValue = analogRead(ph_sen);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  long voltage = sensorValue * (5000 / 1023.0);
  // print out the value you read:
  voltage=voltage-200;

 // Serial.println(voltage);

  if(voltage>=2600)
  {
    ph=mapfloat(voltage,2600,5000,7.0,0);
  }
  else
  {
    ph=mapfloat(voltage,0,2599,14.0,7.0);
   }
  
 }

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
