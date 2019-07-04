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
            else if(temp=='F')
           { 
             icon2= F;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='G')
           { 
             icon2= G;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='H')
           { 
             icon2= H;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='I')
           { 
             icon2= I;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
           /* else if(temp=='J')
           { 
             icon2= J;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }*/
            else if(temp=='K')
           { 
             icon2= K;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='L')
           { 
             icon2= L;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='M')
           { 
             icon2= M;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='N')
           { 
             icon2= N;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='O')
           { 
             icon2= O;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='P')
           { 
             icon2= P;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
           /* else if(temp=='Q')
           { 
             icon2= Q;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }*/
        
            else if(temp=='R')
           { 
             icon2= R;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='S')
           { 
             icon2= S;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='T')
           { 
             icon2= T;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='U')
           { 
             icon2= U;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='V')
           { 
             icon2= V;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='W')
           { 
             icon2= W;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='X')
           { 
             icon2= X;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
            else if(temp=='Y')
           { 
             icon2= Y;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }
           /* else if(temp=='Z')
           { 
             icon2= Z;
             GLCD.ClearScreen();
             delay(100);
             GLCD.DrawBitmap(icon2,0,0);
             delay(3000);
           }*/
            GLCD.ClearScreen();
            delay(50);
         
          }
          
} 
