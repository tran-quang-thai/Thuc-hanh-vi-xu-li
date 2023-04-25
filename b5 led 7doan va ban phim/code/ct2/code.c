#include <REGX51.H>
char num[]={0x00, 0x08, 0x04, 0x0C, 0x02, 0x0A, 0x06, 0x0E, 0x01, 0x09};
void delay(int t){
	unsigned int i;
	for(i=0;i<t;i++){
		TMOD=0x01;
		TH0=0xFC; //delay 1ms
		TL0=0x18;
		TR0=1;
		while(!TF0);
		TF0=0;
		TR0=0;
	}
}
void D(){
	int i;
	for(i=0;i<=9;i++){
		P1=num[i];
		delay(500);
	}
}
void main(){
	D();
}