void GPS_data()
{

  for (unsigned long start = millis(); millis() - start < 1000;)
  {
   while (ss.available())
    {
      char c = ss.read();
      // Serial.write(c); // uncomment this line if you want to see the GPS data flowing
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
    }
  }
   

    if (newData)
    {
  //    Serial.println("getting data");
      unsigned long age;
      gps.f_get_position(&flat, &flon, &age);
      speed_gps=gps.speed();
      speed_gps=1.852*speed_gps;
     
    }
    
}

