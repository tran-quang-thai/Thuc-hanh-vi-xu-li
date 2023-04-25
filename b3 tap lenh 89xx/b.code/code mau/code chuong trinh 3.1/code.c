#include <REGX51.H>
void bamot();
void delay (int t){
	while (t--);
}
void main(){
	while (1){
		bamot ();
	}
}
void bamot (){
	unsigned char led=0x01,i=0; 
	P1=0x00; 
	for(i=0;i<8;i++){
		P1=led; 
		delay(100000); 
		led=led<<1;
	}
}