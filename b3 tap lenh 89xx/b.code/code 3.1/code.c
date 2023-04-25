#include <REGX51.H>
char a1[]={0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
char a2[]={0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00};
void delay(int t){
	while(t--);
}
void S1(){
	int i;
	for(i=0;i<=7;i++){
		P1=a1[i];
		delay(100000);
	}
}
void S2(){
	int i;
	P1=0xFF;
	delay(30000);
	for(i=0;i<=7;i++){
		P1=a2[i];
		delay(100000);
	}
}
void blink(){
	int i;
	for(i=0;i<=5;i++){
		P1=0xFF;
		delay(100000);
		P1=0x00;
		delay(100000);
	}
}
void main(){
	while(1){
		S1();
		blink();
		S2();
	}
}