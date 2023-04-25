#include <REGX51.H>
unsigned char s8[8]={0xFF,0x89,0x76,0x76,0x76,0x76,0x89,0xFF}; 
unsigned char a[8];
unsigned int i;
unsigned int j;
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
void hien_so(){
	for(i=0;i<=7;i++){
		P2=0x80>>i; // quet theo cot
		P3=s8[i];
		delay(1);
	}
}
void dich_so(){
	unsigned int k;
	for(k=0;k<50;k++){
		hien_so();
	}
	a[0]=s8[7];
	for(i=1;i<=7;i++){
		a[i]=s8[i-1];
	}
	for(i=0;i<=7;i++){
		s8[i]=a[i];
	}
}
void main(){
	while(1){
		dich_so();
		
	}
}


	

