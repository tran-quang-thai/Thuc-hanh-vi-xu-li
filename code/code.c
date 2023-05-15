#include <REGX51.H>
#include <Thu_Vien_LCD.h>

#define ADC0808_DATA  P3
#define ADC0808_A     P1_0
#define ADC0808_B     P1_1
#define ADC0808_C     P1_2
#define ADC0808_ALE   P1_3
#define ADC0808_START P1_4
#define ADC0808_EOC   P1_5
#define ADC0808_OE    P1_6
#define ADC0808_CLK   P1_7

unsigned char ADC0808_Read(unsigned char channel){
	unsigned char result;
	ADC0808_A = channel & 0x01;
	ADC0808_B = channel & 0x02;
	ADC0808_C = channel & 0x04;
	ADC0808_ALE = 1;
	ADC0808_START = 1;
	ADC0808_ALE = 0;
	ADC0808_START = 0;
	while(ADC0808_EOC); 
	// wait EOC xuong muc thap ( EOC = 1) , 
	// kiem tra chan EOC co o muc thap hay khong
	while(!ADC0808_EOC); // wait EOC len muc cao ( EOC = 0)
	ADC0808_OE = 1;
	result = ADC0808_DATA;
	ADC0808_OE = 0;
	return result;
}

void TempShow(unsigned char t){
LCD_Puts("Nhiet do:");
LCD_PutChar((t/100)+48);
LCD_PutChar((t%100/10)+48);              
LCD_PutChar((t%10)+48);
LCD_Puts("*C");
}

void INT_Timer0() interrupt 1 {
	TH0=0xFC;
	TL0=0x18;
	ADC0808_CLK=~ADC0808_CLK;
}

void main(){
	unsigned char temp; 
	TMOD=0x01;
	TR0=1; 
	EA=1;
	ET0=1; 
	LCD_Init();
	while(1){
		temp = ADC0808_Read(0);
		LCD_Gotoxy(0,0);
		TempShow(temp);
	}
}
