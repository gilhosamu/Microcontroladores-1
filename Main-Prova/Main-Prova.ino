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

char pos[] = {0x80, 0x81, 0x82, 0xC0, 0xC1, 0xC2};
char pos_f[] = {0xC1, 0x80, 0xC0, 0x82, 0xC2, 0x81};

int main() {

  int k = 0;
  int j = 0;
  int i;

  char b[] = {};
  
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
  _delay_ms(1000);
  clear_LCD();
  paint_f();

  while (1){
    
    if (!tst_bit(PINC, 0)){
      while(!tst_bit(PINC, 0));
      _delay_ms(20);
      k++;
      if (k > 5){
        k = 0;
      }
    }
    
    if(j==0){
      if(!tst_bit(PINC, 1)){
      while(!tst_bit(PINC, 0));
      _delay_ms(20);
        i = k;
        j++;
      }
    }
    
    if(j==1){
      if(!tst_bit(PINC, 1)){
      while(!tst_bit(PINC, 0));
      _delay_ms(20);
                   
         char t;
         t = pos_f[i];
         pos_f[i] = pos_f[k];
         pos_f[k] = t;

         set_cursor(pos_f[2]);
         desenha_LCD(0x00);
        
         set_cursor(pos_f[1]);
         desenha_LCD(0b00111101);
        
         set_cursor(pos_f[0]);
         desenha_LCD(0b00101101);
        
         set_cursor(pos_f[3]);
         desenha_LCD(0x09);
        
         set_cursor(pos_f[4]);
         desenha_LCD(0b00111101);
        
         set_cursor(pos_f[5]);
         desenha_LCD(0b00101101);

         j = 0;
      
         
     }
    }

    set_cursor(pos[k]);
    cmd_LCD(0x0F, 0);

   }  
  }
  

void paint() {

  set_cursor(pos[2]);
  desenha_LCD(0x00);

  set_cursor(pos[1]);
  desenha_LCD(0b00111101);

  set_cursor(pos[0]);
  desenha_LCD(0b00101101);

  set_cursor(pos[3]);
  desenha_LCD(0x09);

  set_cursor(pos[4]);
  desenha_LCD(0b00111101);

  set_cursor(pos[5]);
  desenha_LCD(0b00101101);

  
}

void paint_f(){
  
  set_cursor(pos_f[2]);
  desenha_LCD(0x00);

  set_cursor(pos_f[1]);
  desenha_LCD(0b00111101);

  set_cursor(pos_f[0]);
  desenha_LCD(0b00101101);

  set_cursor(pos_f[3]);
  desenha_LCD(0x09);

  set_cursor(pos_f[4]);
  desenha_LCD(0b00111101);

  set_cursor(pos_f[5]);
  desenha_LCD(0b00101101);

}
