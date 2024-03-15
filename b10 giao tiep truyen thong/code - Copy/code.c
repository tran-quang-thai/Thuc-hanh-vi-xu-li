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
   
void main(){
	UART_Init();
	while(1){
	}
}


void uart_write(char c){
	while(TI==0);
	TI=0;
	SBUF=c;
}
char uart_read_data(){
return RI;
}
char uart_read()
{
RI=0;
return SBUF;
}
void uart_write_text(char * str)
{
unsigned char i=0;
while(str[i]!=0)
{
uart_write(str[i]);
i++;
}
}
void main(){
	uartinit();
	while(1){
	if(uart_read()=='1')
	{
	P3_2=1;
	}
	if(uart_read()=='2')
	{
	P3_3=1;
	}
	if(uart_read()=='3')
	{
	P3_2=0;
	}
	if(uart_read()=='4')
	{
	P3_3=0;
	}
	}
	}
	}