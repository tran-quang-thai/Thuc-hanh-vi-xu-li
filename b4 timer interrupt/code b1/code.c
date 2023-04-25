#include <REGX51.H>
char a[]={0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
void delay(){
	unsigned int i;
	for(i=0;i<200;i++){
		TMOD=0x01;//timer0, mode1
		TH0=0xFC; // tao tre 1ms
		TL0=0x18;
		TR0=1;
		while(TF0==0);
			TF0=0;
			TR0=0;
	}
}
void main(){
	unsigned int i;
	for(i=0;i<=8;i++){
		P1=a[i];
		delay();
	}
}