#include <REGX51.H>

#define ADC0808_DATA 	P3
#define ADC0808_A			P2_0
#define ADC0808_B 		P2_1
#define ADC0808_C 		P2_2
#define ADC0808_ALE 	P2_3
#define ADC0808_START P2_4
#define ADC0808_EOC 	P2_5
#define ADC0808_OE 		P2_6
#define ADC0808_CLK 		P2_7

unsigned char ADC0808_Read(unsigned char channel){
	unsigned char result;
	ADC0808_A = channel & 0x01;
	ADC0808_B = channel & 0x02;
	ADC0808_C = channel & 0x04;
	ADC0808_ALE = 1;
	ADC0808_START = 1;
	ADC0808_ALE = 0;
	ADC0808_START = 0;
	while(!ADC0808_EOC);
	AD
	return result;
}

void CLK() interrupt 1{
	ADC0808_CLK = ~ADC0808_CLK;
}