#include <reg52.h>
//�������ܽŶ���
sbit    LS138A=P2^2;       //�ܽŶ���
sbit    LS138B=P2^3;
sbit    LS138C=P2^4; 

//�˱�Ϊ LED ����ģ, ��������� 0-9  - 
unsigned char code Disp_Tab[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
 
unsigned long  LedOut[5],LedNumVal;
void delay(unsigned int i);

void display(unsigned char Key_Val)
{  
   unsigned char i; 
   /********���½���ֵ�͵�LED�������ʾ*************/
      LedNumVal=Key_Val;      //�Ѽ�ֵ�͵�LedNumVal������
	  LedOut[0]=Disp_Tab[LedNumVal%10000/1000];
      LedOut[1]=Disp_Tab[LedNumVal%1000/100];
      LedOut[2]=Disp_Tab[LedNumVal%100/10];	 //ʮλ
      LedOut[3]=Disp_Tab[LedNumVal%10];    //��λ
  	  
    for(i=0; i<4; i++) 
	  {		
		 P0 = LedOut[i] ;
	  			 	 	  	
		switch(i)					  
         {	    	  //138����
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