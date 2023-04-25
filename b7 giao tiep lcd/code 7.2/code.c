#include <REGX51.H>
#include <Thu_Vien_LCD.h>
char mssv[16] = "   4351170248   ";
char c[16];
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
void hien_thi(){
	LCD_Puts(mssv);
	delay(500);
}
void dich_phai(){
	unsigned int i;
	c[0]=mssv[15];
	for(i=1;i<=15;i++){
		c[i]=mssv[i-1];
	}
	for(i=0;i<=15;i++){
		mssv[i]=c[i];
	}
}
void xuat(){
	hien_thi();
	dich_phai();
}
void main(){
	LCD_Init();
	
	while(1){
		LCD_Gotoxy(0,0);
		LCD_Puts("TRAN QUANG THAI");
		LCD_Gotoxy(0,1);
		xuat();
	}
}