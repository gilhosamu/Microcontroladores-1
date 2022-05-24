#include "LCD.h" 
#include "def_principais.h"
#include "LCD.c" 

 


int main(){

    unsigned char k;

    DDRD = 0xFF;
    DDRB = 0xFF;
    PORTB = 0x00;
    
    set_bit(PORTB, 2);
    inic_LCD_4bits();

    for(k=0; k<=16; k++){
    cmd_LCD(0x80+k, 0);
    cmd_LCD(0xFF, 1);
    cmd_LCD(0x96+k, 0);
    cmd_LCD(0xFF, 1);
    _delay_ms(100);
    
    if(k==16){
         cmd_LCD(1,0);
         _delay_ms(100);
         k=-1;   
      }
    }
  }
    
    
    
    


    
    
