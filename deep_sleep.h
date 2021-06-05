#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#define  TRUE  1            /*DO NOT CHANGE*/
#define  FALSE 0            /*DO NOT CHANGE*/


/* Peripherals which will be turn off during sleep*/
/* PUT ONLY TRUE OR FALSE*/

#define  ADC_OFF     TRUE   /*CUSTOMIZABLE*/
#define  USART_OFF   TRUE   /*CUSTOMIZABLE*/
#define  SPI_OFF     TRUE   /*CUSTOMIZABLE*/
#define  TIMER0_OFF  TRUE   /*CUSTOMIZABLE*/
#define  TIMER1_OFF  TRUE   /*CUSTOMIZABLE*/
#define  TIMER2_OFF  TRUE   /*CUSTOMIZABLE*/
#define  TWI_I2C_OFF TRUE   /*CUSTOMIZABLE*/



void turn_off_peripherals(void){
ADCSRA&=~(1<<ADEN);
ACSR  |=(1<<ACD);
PRR    =(ADC_OFF<<0)|(USART_OFF<<1)|(SPI_OFF<<2)|(TIMER1_OFF<<3);
PRR   |=(TIMER0_OFF<<5)|(TIMER2_OFF<<6)|(TWI_I2C_OFF<<7);
DDRB=0xFF;
PORTB=0x00;
DDRC=0xFF;
PORTC=0x00;
DDRD=0xFF;
PORTD=0x00;
DEBUG_DDR&=~(1<<DEBUG_PIN);
DEBUG_PORT&=~(1<<DEBUG_PIN);
}

void deep_sleep(void){
set_sleep_mode(SLEEP_MODE_PWR_DOWN);
sleep_enable();
sleep_bod_disable();
sei();
sleep_cpu();
sleep_disable();
}
