#define set_bit(Y,bit_x) (Y|=(1<<bit_x)) // Seta o Bit como 1
#define clr_bit(Y,bit_x) (Y&=~(1<<bit_x)) // Seta o Bit como 0
#define cpl_bit(Y,bit_x) (Y^=(1<<bit_x)) // Inverte um Bit
#define tst_bit(Y,bit_x) (Y&(1<<bit_x)) // Testa um Bit (Retorna True if 1, else 0)

void setup(){
  
  DDRB = 0x20;
  PORTB = 0x00;

  while(1){

    set_bit(PORTB, 3);
    delay(100000);
    clr_bit(PORTB, 3);
    delay(100000);
    
  }
}
