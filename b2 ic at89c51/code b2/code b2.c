#include <REGX51.H>
void delay(int t){
	while(t--);
}
void main(){
	P1_7=0; delay(50000); P1_7=1;
	P1_6=0; delay(50000); P1_6=1;
	P1_5=0; delay(50000); P1_5=1;
	P1_4=0; delay(50000); P1_4=1;
	P1_3=0; delay(50000); P1_3=1;
	P1_2=0; delay(50000); P1_2=1;
	P1_1=0; delay(50000); P1_1=1;
	P1_0=0; delay(50000); P1_0=1;
}