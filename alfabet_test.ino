unsigned char i;
unsigned char j; 
unsigned long startTime;
unsigned long endTime;
unsigned long duration;

byte timerRunning;

   /*Port Definitions*/
  int Max7219_pinCLK = 10;
  int Max7219_pinCS = 9;
  int Max7219_pinDIN = 8;
  int VRX_pin = A0;
  int VRY_pin = A1;
  int SW_pin = 6;

unsigned char deftext [2][8] =
{
  {0x00,0x66,0x99,0xF9,0x99,0x96,0x00,0x00},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};
unsigned char sad [2][8] =
{
  {0x00,0x28,0x00,0x3c,0x42,0x82,0x82,0x82},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};
unsigned char happy [2][8] =
{
  {0x00,0x24,0x00,0x82,0x82,0x82,0x42,0x3C},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};
char pass[12] = "PROIECT2019";
char trypass;
char characters[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numb[11] = "0123456789";
unsigned char passtext[16][8] = {
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x0,0x3e,0x8,0x8,0x8,0x8,0x8,0x8},//T
  {0x3C,0x22,0x22,0x22,0x3C,0x24,0x22,0x21},//R
  {0x41,0x22,0x14,0x8,0x8,0x8,0x8,0x8},//Y
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x3C,0x22,0x22,0x22,0x3C,0x20,0x20,0x20},//P
  {0x8,0x14,0x22,0x3E,0x22,0x22,0x22,0x22},//A
  {0x0,0x1E,0x20,0x20,0x3E,0x2,0x2,0x3C},//S
  {0x0,0x1E,0x20,0x20,0x3E,0x2,0x2,0x3C},//S
  {0x0,0x49,0x49,0x49,0x49,0x2A,0x1C,0x0},//W
  {0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//O
  {0x3C,0x22,0x22,0x22,0x3C,0x24,0x22,0x21},//R
  {0x7C,0x42,0x42,0x42,0x42,0x42,0x7C,0x0},//D
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
 }; 

unsigned char numbers[10][8]={
{0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//0
{0x08,0x18,0x28,0x48,0x08,0x08,0x08,0x08},//1
{0x7E,0x2,0x2,0x7E,0x40,0x40,0x40,0x7E},//2
{0x3E,0x2,0x2,0x3E,0x2,0x2,0x3E,0x0},//3
{0x8,0x18,0x28,0x48,0xFE,0x8,0x8,0x8},//4
{0x3C,0x20,0x20,0x3C,0x4,0x4,0x3C,0x0},//5
{0x3C,0x20,0x20,0x3C,0x24,0x24,0x3C,0x0},//6
{0x3E,0x22,0x4,0x8,0x8,0x8,0x8,0x8},//7
{0x0,0x3E,0x22,0x22,0x3E,0x22,0x22,0x3E},//8
{0x3E,0x22,0x22,0x3E,0x2,0x2,0x2,0x3E},//9
};
unsigned char chars[26][8] = {
{0x08,0x14,0x22,0x3E,0x22,0x22,0x22,0x22},//A
{0x3C,0x22,0x22,0x3E,0x22,0x22,0x3C,0x0},//B
{0x3C,0x40,0x40,0x40,0x40,0x40,0x3C,0x0},//C
{0x7C,0x42,0x42,0x42,0x42,0x42,0x7C,0x0},//D
{0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x7C},//E
{0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x40},//F
{0x3C,0x40,0x40,0x40,0x4C,0x44,0x44,0x3C},//G
{0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x44},//H
{0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x7C},//I
{0x3C,0x8,0x8,0x8,0x8,0x8,0x48,0x30},//J
{0x0,0x24,0x28,0x30,0x20,0x30,0x28,0x24},//K
{0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7C},//L
{0x81,0xC3,0xA5,0x99,0x81,0x81,0x81,0x81},//M
{0x0,0x42,0x62,0x52,0x4A,0x46,0x42,0x0},//N
{0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//O
{0x3C,0x22,0x22,0x22,0x3C,0x20,0x20,0x20},//P
{0x1C,0x22,0x22,0x22,0x22,0x26,0x22,0x1D},//Q
{0x3C,0x22,0x22,0x22,0x3C,0x24,0x22,0x21},//R
{0x0,0x1E,0x20,0x20,0x3E,0x2,0x2,0x3C},//S
{0x0,0x3E,0x8,0x8,0x8,0x8,0x8,0x8},//T
{0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3c},//U
{0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18},//V
{0x0,0x49,0x49,0x49,0x49,0x2A,0x1C,0x0},//W
{0x0,0x41,0x22,0x14,0x8,0x14,0x22,0x41},//X
{0x41,0x22,0x14,0x8,0x8,0x8,0x8,0x8},//Y
{0x0,0x7F,0x2,0x4,0x8,0x10,0x20,0x7F},//Z
};

 
 
 
void Write_Max7219_byte(unsigned char DATA) 
{   
            unsigned char i;
      digitalWrite(Max7219_pinCS,LOW);    
      for(i=8;i>=1;i--)
          {     
             digitalWrite(Max7219_pinCLK,LOW);
             digitalWrite(Max7219_pinDIN,DATA&0x80);// Extracting a bit data
             DATA = DATA<<1;
             digitalWrite(Max7219_pinCLK,HIGH);
           }                                 
}
 
 
void Write_Max7219(unsigned char address,unsigned char dat)
{
        digitalWrite(Max7219_pinCS,LOW);
        Write_Max7219_byte(address);           //address，code of LED
        Write_Max7219_byte(dat);               //data，figure on LED 
        digitalWrite(Max7219_pinCS,HIGH);
}
 
void Init_MAX7219(void)
{
  //The MAX7219CNG has a command protocol, built on SPI, where you send 12-bit packet that encodes both a 4-bit command and an 8-bit value. In this packet,
  //the Most Significant Bits (MSBs), or the ones that are sent first, encode the command, and the Least Significant Bits (LSBs) encode the data. The specific packet is constructed such that
  //  B0-B3 encode commands and B4-B11 encode data.
 // IC MAX7219 uses SPI communication interface .It has 12 bits packets with 4 bits for adresses and 8 bits for data. 
 Write_Max7219(0x09, 0x00);       //decoding register:0x09 with value 0x00 no decoding mode; setting all segment lines into no decoding mod cus we work with led matrix,
                                  // if decode mode is selected , it's fine to work with BCD segments;
                                  //so the MAX7219 interprets our byte of date as 8 segment BCD and transforms their LOW/HIGH value into 8 LEDS  LOW/HIGH value
 Write_Max7219(0x0a, 0x05);       //brightness register 0x0A with value 0x05 ->11/32 level of intensity in LEDS of matrix,
                                  // we can adjust these values from 1/32 up to 31/32 levels of intensity
 Write_Max7219(0x0b, 0x07);       //scanlimit register with address 0x0b and value 0x07；
                                  //it adjust the number of LED's enabled in each BCD (on column);for example if it has value of 0x01 it will light up just the first 2 BCD rows
                                  //with the value 0x07 we light up all of our 8 rows in each BCD of the matrix
 Write_Max7219(0x0c, 0x01);       //this is the power register at address 0x0C: power-down mode for 0x00 and power up/normal operation mode on value 0x01
 Write_Max7219(0x0f, 0x01);       //test display register(at address 0x0F) if we set the value to 0x01 it will go into display test mode .So if we set to 0x00 it goes into normal op. mode.
 delay(3000);                                 //The MAX7219/MAX7221 remain in display-test mode(all LEDs on) until the display-test register is reconfigured for normal operation.
 Write_Max7219(0x0f, 0x00);       // switch from test mod to normal running mode.
}
 
 
 
void setup()
{
   Serial.begin(115200);

  pinMode(Max7219_pinCLK,OUTPUT);
  pinMode(Max7219_pinCS,OUTPUT);
  pinMode(Max7219_pinDIN,OUTPUT);
  pinMode(VRX_pin,INPUT);
  pinMode(VRY_pin,INPUT);
  pinMode(SW_pin,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  Init_MAX7219();
  
  showPassMessage();
  showDefMessage(); 


}

void showBlank()
{
    for(j=0;j<10;j++)
  {
   for(i=1;i<9;i++)
    Write_Max7219(i,0);
  }
}
void showDefMessage()
{
  for(int i=1;i<9;i++)Write_Max7219(i,deftext[0][i-1]);
}
void showPassMessage()
{
   for(j=0;j<15;j++)
  {
    int k = 0;
   while(k <8){
   for(i=1;i<9;i++)Write_Max7219(i,passtext[j][k+i]);
   delay(50);
   k++;
   }

  }
}
 void showHappy()
{
   for(int i=1;i<9;i++)Write_Max7219(i,happy[0][i-1]);
}
 void showSad()
{
   for(int i=1;i<9;i++)Write_Max7219(i,sad[0][i-1]);
}
void loop()
{ 
  static int positions ;
  static int init;
  int x = (analogRead(A0) - 505)+511;// read analog
  int y = (analogRead(A1)- 530)+511;
  int swStat = digitalRead(SW_pin);//
  Serial.println("x : ");Serial.println(x);
  Serial.println("y : ");Serial.println(y);
  static int cIndex ;
  static int nIndex;
  static int setAlphabet = 0;//alfabet, 1 -cifre
  Serial.println(cIndex);
  Serial.println(nIndex);
  delay(200);
  static int c;
  int wrong = 0;
  int state =0;
  
  if(y< 100 && (x>100 && x<900))
  {
    state = 1;
    Serial.println("UP");
  }
  else if ( y>800  && (x<800 && x>300))
  {
    state = 2;
    Serial.println("DOWN");
  }
  else if( x > 700 && (y >100 && y<900))
  {
    state = 3;
    Serial.println("RIGHT");
  }
  else if (x<100 && (y >100 && y<900))
  {
    state = 4;
    Serial.println("LEFT");
  }


   if (timerRunning == 0 && swStat == LOW){ 
          startTime = millis();
          timerRunning = 1;
      }
   if (timerRunning == 1 && swStat == HIGH){ 
          endTime = millis();
          timerRunning = 0;
          duration = endTime - startTime;
       if(duration > 1600){
           state = 6;
           Serial.println("STOP");
       }
       else if(duration > 0  && duration <1600){
           state = 5;
            Serial.println("Switch pressed");
      }
   }

  Serial.print(trypass);
  Serial.print(pass[c]);
  switch(state)
  {
    case 1 :{
      if (setAlphabet == 0)
      {
        
        cIndex ++ ;
        if(cIndex == 26)
        {
          cIndex = 0;
          for(i=1;i<9;i++)Write_Max7219(i,chars[cIndex][i-1]);
        }
        for(i=1;i<9;i++)Write_Max7219(i,chars[cIndex][i-1]);
      
      }
      else 
      {
        
          nIndex ++ ;

        if(nIndex == 10)
        {
          nIndex = 0;
          for(i=1;i<9;i++)Write_Max7219(i,numbers[nIndex][i-1]);
        }
        for(i=1;i<9;i++)Write_Max7219(i,numbers[nIndex][i-1]);
      }
      break;
    }
    case 2:
    {
      if(setAlphabet == 0)
      {
        
        cIndex --;
        if(cIndex == -1)
        {
          cIndex = 25;
          for(i=1;i<9;i++)Write_Max7219(i,chars[cIndex][i-1]);
        }
        for(i=1;i<9;i++)Write_Max7219(i,chars[cIndex][i-1]);
      }
      else 
      {
        nIndex--;
       if(nIndex == -1)
        {
          nIndex = 9;
          for(i=1;i<9;i++)Write_Max7219(i,numbers[nIndex][i-1]);
        }
        for(i=1;i<9;i++)Write_Max7219(i,numbers[nIndex][i-1]);
      }
      break;

     
    }
    case 3:
    {
      setAlphabet = 1;
      nIndex = 0;
            
   for(i=1;i<9;i++)Write_Max7219(i,numbers[0][i-1]);

      break;
    }
    case 4:
    {
      setAlphabet = 0;
      cIndex = 0;
        
   for(i=1;i<9;i++)Write_Max7219(i,chars[0][i-1]);

      
      break;
    }
    case 5:
    {
      if(c==10){
        showHappy();
        delay(2000);
        exit(0);
      }
      if(setAlphabet == 0)
      {
      trypass = characters[cIndex];
      
      if(trypass != pass[c]){
      showBlank();
      wrong = 1;
      showSad();
      delay(2000);
      }
      else c++;
      
      }
      else 
      {
        trypass = numb[nIndex];
        if(trypass != pass[c]){
       showBlank();
        wrong = 1;
        showSad();
        delay(2000);
        }
        else c++;
      }
     
      
    break;
    }

    case 6:
    {

      showBlank();
      state = 6;
    }
    case 0:
    {
      break;
    }
    default :{

    for(int i=1;i<9;i++)Write_Max7219(i,deftext[0][i]);
    break;
    }
  }
  if (wrong == 1)exit(0);
 

}
