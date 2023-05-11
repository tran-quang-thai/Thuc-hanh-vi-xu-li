#include <REGX51.H>
#include <Thu_Vien_LCD.h>

sbit ROW1 = P1^0;
sbit ROW2 = P1^1;
sbit ROW3 = P1^2;
sbit ROW4 = P1^3;
sbit COL1 = P1^4;
sbit COL2 = P1^5;
sbit COL3 = P1^6;
sbit COL4 = P1^7;

unsigned char key=0;
char s[16]={0};
unsigned int idx = 0;
int c=0;

void delay(int t){
    unsigned int i;
    for(i=0;i<t;i++){
        TMOD=0x01;
        TH0=0xFC; //delay 1ms
        TL0=0x18;
        TR0=1;
        while(!TF0);
        TF0=0;
        TR0=0;
    }		
}

unsigned char Keypad_Read(){
    unsigned char key = 0xFF;
    ROW1=0;
    if(!COL1) key='C'; // Clear
    if(!COL2) key='0';
    if(!COL3) key='=';
    if(!COL4) key='+';
    ROW1=1;
    ROW2=0;
    if(!COL1) key='1';
    if(!COL2) key='2';
    if(!COL3) key='3';
    if(!COL4) key='-'; 
    ROW2=1;
    ROW3=0;
    if(!COL1) key='4';
    if(!COL2) key='5';
    if(!COL3) key='6';
    if(!COL4) key='*';
    ROW3=1;
    ROW4=0;
    if(!COL1) key='7';
    if(!COL2) key='8';
    if(!COL3) key='9';
    if(!COL4) key='/';
    ROW4=1;
    return key;
}

void Display(){
	unsigned int i;
	LCD_Gotoxy(0,0);
	for(i=0;i<idx;i++){
		LCD_PutChar(s[i]);
	}
	if(s[3]=='='){
		LCD_Gotoxy(0,1);
		LCD_PutNumber(c);
	}
}

void Calculate(){
	if(s[1]=='+') c=(s[0]-'0')+(s[2]-'0');
	if(s[1]=='-') c=(s[0]-'0')-(s[2]-'0');
	if(s[1]=='*') c=(s[0]-'0')*(s[2]-'0');
	if(s[1]=='/') c=(s[0]-'0')/(s[2]-'0');
}

void Clear(){
	if(key=='C'){
		idx=0;
		s[3]=' ';
		LCD_Clear();
	}
}

void main(){
  LCD_Init();
  while(1){	
		key = Keypad_Read();
		if(key != 0xFF){
			delay(250);
			s[idx] = key;
			idx++;
		}
		Clear();
		Calculate();
		Display();	
	}
}