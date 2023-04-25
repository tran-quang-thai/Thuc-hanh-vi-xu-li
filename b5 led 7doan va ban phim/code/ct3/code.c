#include <REGX51.H>
char num[]={0x00, 0x08, 0x04, 0x0C, 0x02, 0x0A, 0x06, 0x0E, 0x01, 0x09};
int i;
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
void S1(){
	i++;
	if(i>9){
		i=9;
	}
	P1=num[i];
	delay(50);
}

void S2(){
	i--;
	if(i<0){
		i=0;
	}
	P1=num[i];		
	delay(50);
}

void S3(){
	for(i=0;i<=9;i++){
		P1=num[i];
		delay(50);
	}
}

void S4(){
	for(i=9;i>=0;i--){
		P1=num[i];
		delay(50);
	}
}
void main(){
	i=0;
	P1=0x00;
	while(1){
		if(P3_0==0){
			S1();
		}
		if(P3_1==0){
			S2();
		}
		if(P3_2==0){
			S3();
		}
		if(P3_3==0){
			S4();
		}
	}
}