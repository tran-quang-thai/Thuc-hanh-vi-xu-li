#include <REGX51.H>

#define ADC0808_DATA  P3
#define ADC0808_A     P1_0
#define ADC0808_B     P1_1
#define ADC0808_C     P1_2
#define ADC0808_ALE   P1_3
#define ADC0808_START P1_4
#define ADC0808_EOC   P1_5
#define ADC0808_OE    P1_6
#define ADC0808_CLK   P1_7

unsigned char LED[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void INT() interrupt 1 {
	P1_7=~P1_7;
}



unsigned char ADC0808_Read(unsigned char channel){
	unsigned char result;
	ADC0808_A = channel & 0x01;
	ADC0808_B = channel & 0x02;
	ADC0808_C = channel & 0x04;
	ADC0808_ALE = 1;
	ADC0808_START = 1;
	ADC0808_ALE = 0;
	ADC0808_START = 0;
	ADC0808_OE = 1;
	result = ADC0808_DATA;
	ADC0808_OE = 0;
	return result;
}

void delay(unsigned int t){
	unsigned int i;
	for(i=0;i<t;i++){
		TMOD=0x01;
		TH0=0xFC; //delay 1us
		TL0=0x18;
		TR0=1;
		while(!TF0); 
		TF0=0;
		TR0=0;
	}
}

	
void main(){
	unsigned char temp;
	TMOD=0x01;
	TH0=0xFF;
	TL0=0xFF;
	TR0=1;
	EA=1;
	ET0=1;
	while(1){
		temp=ADC0808_Read(0);
		P0_0 = 1;
		P2 = LED[temp/10]; // hang chuc
		delay(66);
		P0_0 = 0;
		P0_1 = 1;
		P2 = LED[temp%10]; // hang don vi
		delay(66);
		P0_1 = 0;
	}
}
