#include "LCD.h" 
#include "def_principais.h"
#include "LCD.c" 

 
unsigned char POU[] = {
  0x04,
  0x0E,
  0x15,
  0x1F,
  0x0E,
  0x1F,
  0x0A,
  0x00
};

int main(){

    unsigned char k = 0;
    

    DDRD = 0xFF;
    DDRB = 0xFF;
    PORTB = 0x00;
    
    set_bit(PORTB, 2);
    inic_LCD_4bits();

    cmd_LCD(0x40, 0);
    for (k=0;k<=7; k++){
    cmd_LCD(POU[k],1);
    
    }
    
    for(int i=0;i<=16;i++){
    cmd_LCD(0xC0+i, 0);
    cmd_LCD(0xFF, 1);
    }

    for(int i=0;i<=16;i++){
    cmd_LCD(0x80+i/2, 0);
    cmd_LCD(0b00101110,1);
    }
  
    cmd_LCD(0x80, 0);
    cmd_LCD(0x00, 1);
}
       
    
    
    


    
