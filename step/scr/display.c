#include <reg52.h>
//译码器管脚定义
sbit    LS138A=P2^2;       //管脚定义
sbit    LS138B=P2^3;
sbit    LS138C=P2^4; 

//此表为 LED 的字模, 共阴数码管 0-9  - 
unsigned char code Disp_Tab[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
 
unsigned long  LedOut[5],LedNumVal;
void delay(unsigned int i);

void display(unsigned char Key_Val)
{  
   unsigned char i; 
   /********以下将键值送到LED数码管显示*************/
      LedNumVal=Key_Val;      //把键值送到LedNumVal变量中
	  LedOut[0]=Disp_Tab[LedNumVal%10000/1000];
      LedOut[1]=Disp_Tab[LedNumVal%1000/100];
      LedOut[2]=Disp_Tab[LedNumVal%100/10];	 //十位
      LedOut[3]=Disp_Tab[LedNumVal%10];    //个位
  	  
    for(i=0; i<4; i++) 
	  {		
		 P0 = LedOut[i] ;
	  			 	 	  	
		switch(i)					  
         {	    	  //138译码
			case 0:LS138A=0; LS138B=0; LS138C=0; break;         
            case 1:LS138A=1; LS138B=0; LS138C=0; break;             	
            case 2:LS138A=0; LS138B=1; LS138C=0; break; 
            case 3:LS138A=1; LS138B=1; LS138C=0; break; 
         }
		 
		delay(100);
	  }

	  P0 = 0;    
 }
 void delay(unsigned int i)
{
    char j;
    for(i; i > 0; i--)
        for(j = 200; j > 0; j--);
}