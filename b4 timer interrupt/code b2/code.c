#include <REGX51.H>
/*
abc = 248 Hz -> T = 0,0040322580645161 s ~ 4 ms -> delay 2 ms
-> x = 0 -> su dung ngat timer 0 
*/
void ngat() interrupt 1{
	TH0=0xF8; // tao tre 2ms
	TL0=0x30;
	P2_0=~P2_0;
}
void main(){
	TMOD=0x01;//timer0, mode1
	TH0=0xF8; // tao tre 2ms
	TL0=0x30;
	TR0=1; // cho phep timer 0 hoat dong
	EA=1; // cho phep ngat toan cuc 
	ET0=1; // cho phep ngat timer 0
	while(1){
	}
}