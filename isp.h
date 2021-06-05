#include <avr/io.h>




void led(uint8_t state){
DDRC |=(1<<5);
if     (state==0x00){PORTC&=~(1<<5);}
else if(state==0x01){PORTC|= (1<<5);}
}

void spi_init(void){
DDRB |=(1<<2)|(1<<3)|(1<<4)|(1<<5);
PORTB&=~(1<<2);
PORTB&=~(1<<5);

_delay_us(100);
PORTB|=(1<<2);
_delay_us(100);
PORTB&=~(1<<2);
SPCR=(1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);
}

uint8_t spi_tx(uint8_t data){
SPDR = data;
while((SPSR & (1 << SPIF))==0);
return SPDR;
}

uint8_t prgm_mode(void){
uint8_t status=0x00,timeout=0x00;
while(status!=0x53){
   spi_init();
   spi_tx(0xAC);
   spi_tx(0x53);
   status=spi_tx(0x00);
   spi_tx(0x00);
   timeout++;
   if(timeout>0x0F){break;}
   }
   if(status==0x53){return 1;}else{return 0;}
}

uint8_t device_ID(uint8_t id){
uint8_t s=0x00;
spi_tx(0x30);
spi_tx(0x00);
spi_tx(id);
s=spi_tx(0x00);
return s;
}

uint8_t Lfuse(void){
uint8_t s=0x00;
spi_tx(0x50);
spi_tx(0x00);
spi_tx(0x00);
s=spi_tx(0x00);
return s;
}

uint8_t Hfuse(void){
uint8_t s=0x00;
spi_tx(0x58);
spi_tx(0x08);
spi_tx(0x00);
s=spi_tx(0x00);
return s;
}