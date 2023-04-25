#include <REGX51.H>
void delay(int t){
	while(t--);
}
void main(){
	P2=0x00;
	P2_7=1; delay(50000); P2_7=0;
	P2_6=1; delay(50000); P2_6=0;
	P2_5=1; delay(50000); P2_5=0;
	P2_4=1; delay(50000); P2_4=0;
	P2_3=1; delay(50000); P2_3=0;
	P2_2=1; delay(50000); P2_2=0;
	P2_1=1; delay(50000); P2_1=0;
	P2_0=1; delay(50000); P2_0=0;
}