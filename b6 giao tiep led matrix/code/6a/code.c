#include <REGX51.H>
unsigned char s8[]={0xFF,0x89,0x76,0x76,0x76,0x76,0x89,0xFF};
void delay(int t){
	unsigned int j;
	for(j=0;j<t;j++){
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
	unsigned int i;
	for(i=0;i<=7;i++){
		P2=0x80>>i;
		P3=s8[i];
		delay(1);
	}
}
void main(){
	while(1){
		//D();
		P3=0x00;
		P2=0xFF;
	}
	
}