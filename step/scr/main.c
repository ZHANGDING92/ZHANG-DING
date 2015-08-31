#include <reg52.h>
#include <intrins.h>
extern void display(unsigned char Key_Val);
extern void IRInit();    //extern 是引用IR.C中的函数
extern unsigned char  IRCOM[7];//引用ir.c中的IRCOM[7]
void main()
{
	IRInit();
	while(1)
	{
		display(IRCOM[2]);
	}
}

