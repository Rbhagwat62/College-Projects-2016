void display_images()
{
  unsigned char receive_data_len=0;
  unsigned char temp_variable=0;
  
  receive_data_len=sizeof(receive_matlab_data);
  
  for(temp_variable=0;temp_variable<receive_data_len;temp_variable++)
  {
    temp=receive_matlab_data[temp_variable];
    
        if(temp=='A')
          { 
            icon2= A;
            GLCD.ClearScreen();
            delay(100);
            GLCD.DrawBitmap(icon2,0,0);
            delay(3000);
          }
          else if(temp=='B')
           { 
             icon2= B;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='C')
           { 
             icon2= C;
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
          
            else if(temp=='D')
           { 
             icon2= D;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='E')
           { 
             icon2= E;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            GLCD.ClearScreen();
            delay(50);
         
          }
          
} 
