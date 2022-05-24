#include "LCD.h"
#include "def_principais.h"
#include "LCD.c"


unsigned char nave[] = {
  0x00,
  0x10,
  0x1E,
  0x1F,
  0x1E,
  0x10,
  0x00,
  0x00
};

unsigned char nave_invertida[] = {
  B00000,
  B00001,
  B01111,
  B11111,
  B01111,
  B00001,
  B00000,
  B00000
};

char pos[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF};
char pos_f[] = {0x84, 0x8A, 0xC2, 0x86, 0xC5, 0xC7, 0x82, 0x8B, 0x8D, 0x8E, 0xC1, 0x8C, 0x83, 0xCC, 0x81, 0xCF, 0x88, 0x80, 0xC6, 0xC8, 0xCE, 0x85, 0x87, 0xCA, 0x8F, 0xC4, 0xCB, 0xC0, 0xCD, 0xC3, 0xC9, 0x89};

int main() {

  int k = 0;
  int j = 0;
  int i;
  
  DDRD = 0xFF;
  DDRB = 0xFF;
  PORTB = 0x00;
  DDRC = 0x00;
  PORTC = 0xFF;

  set_bit(PORTB, 2);
  inic_LCD_4bits();

  save_carac(nave, 0);
  save_carac(nave_invertida, 1);
  
  paint();
  _delay_ms(100);
  clear_LCD();

  while (1){
    
    if (!tst_bit(PINC, 0)){
      
      while(!tst_bit(PINC, 0));
      _delay_ms(20);
      
      set_cursor(pos_f[7]);
      desenha_LCD(0x00);
        
      set_cursor(pos_f[6]);    
      desenha_LCD(0b00111101);
       
      set_cursor(pos_f[5]);      
      desenha_LCD(0b00101101);
       
      set_cursor(pos_f[24]);
      desenha_LCD(0x09);
        
      set_cursor(pos_f[25]);
      desenha_LCD(0b00111101);
        
      set_cursor(pos_f[26]);      
      desenha_LCD(0b00101101);
      
      k++;
     
      if (k > 31){
        k = 0;
      }
    }

    set_cursor(pos[k]);
    cmd_LCD(0x0F, 0);

    if(!tst_bit(PINC, 1)){
      i = k;
      j++;
    }

    while(j==1){
      
      if(!tst_bit(PINC, 1)){
         swap(pos_f[i], pos_f[k]);
         j = 0;
        
     }
    }
   }  
  }
  

void paint() {

  set_cursor(pos[7]);
  desenha_LCD(0x00);

  set_cursor(pos[6]);
  desenha_LCD(0b00111101);

  set_cursor(pos[5]);
  desenha_LCD(0b00101101);

  set_cursor(pos[24]);
  desenha_LCD(0x09);

  set_cursor(pos[25]);
  desenha_LCD(0b00111101);

  set_cursor(pos[26]);
  desenha_LCD(0b00101101);

}

void paint_f(){
  
  set_cursor(pos_f[7]);
  desenha_LCD(0x00);
    
  set_cursor(pos_f[6]);    
  desenha_LCD(0b00111101);
   
  set_cursor(pos_f[5]);      
  desenha_LCD(0b00101101);
   
  set_cursor(pos_f[24]);
  desenha_LCD(0x09);
    
  set_cursor(pos_f[25]);
  desenha_LCD(0b00111101);
    
  set_cursor(pos_f[26]);      
  desenha_LCD(0b00101101);
  
}
