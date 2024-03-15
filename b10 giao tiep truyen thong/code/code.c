#include <REGX51.H>
#include <string.h>

unsigned char mssv[10]="4351170248";
	
void delay(int t){
	while(t--);
}

void UART_Init(){
	SM0=0; // Đặt chế độ UART thành 8-bit không đồng bộ với tốc độ kép.
	SM1=1;
	TMOD=0x20; //Đặt chế độ timer 1 thành 8-bit tự động nạp lại.
	TH1=0xFD; //Đặt tốc độ baud thành 9600 bps.
	TR1=1;
	TI=1; //Cho phép truyền UART.
	REN=1; //Cho phép nhận UART.
}

void UART_SendData(){
  unsigned int i;
	for(i=0;i<=9;i++){
			if(i==8 || i==9) P0_1=0;
			else P0_1=1;
		while(!TI);
			TI=0;
			SBUF=mssv[i];
			delay(300000);
			
		}
	
}
   
void main(){
	UART_Init();
	while(1){
		if(P0_0==0){
			delay(100000);
			UART_SendData();
		}
	}
}