#include <REGX51.H>
char led[]={0x01, 0x03, 0x07, 0xF, 0x1F, 0x3F, 0x7F, 0XFF};
char a1[]={0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
char a2[]={0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF};
unsigned char aa=1;  
unsigned char bb=0;  
char cc=0;
void delay(int t){
	while(t--);
}

void C(){
	int i;
	for(i=0;i<=8;i++){
		P1=a1[i];
		delay(100000);
	}
}
void L(){
	int i;
	for(i=0;i<=8;i++){
		P1=a2[i];
		delay(100000);
	}
}
void N(){
	P1=0xFF;
	delay(100000);
	P1=0x00;
	delay(50000);
}
void M(){
	if(cc<0){
		cc=cc*(-1);
	}
}
void main(){
	P1=0x00;
	cc=(aa+bb-aa*bb);
	M();
	if(cc%2==0 && cc!=0){
		C();
	}
	if(cc%2==1){
		L();
	}
	if(cc==0){
		N();
	}
}