#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define  DEBUG_DDR   DDRD    /*USER CONFIGURABLE*/
#define  DEBUG_PORT  PORTD   /*USER CONFIGURABLE*/
#define  DEBUG_PIN   1       /*USER CONFIGURABLE*/
#define  DEBUG_BAUD  9600    /*USER CONFIGURABLE*/

/*DO NOT MODIFY THE REGION BELOW*/
#define  DEBUG_DELAY   1000000/DEBUG_BAUD
#define  dbg_enable()  DEBUG_DDR|= (1<<DEBUG_PIN)
#define  dbg_disable() DEBUG_DDR&=~(1<<DEBUG_PIN)

void data(uint8_t state){
if     (state==1){DEBUG_PORT|= (1<<DEBUG_PIN);}
else if(state==0){DEBUG_PORT&=~(1<<DEBUG_PIN);}
}

void dbg_single_byte(uint8_t byte){
uint8_t tmp[10]={0,0,0,0,0,0,0,0,0,1};
for(uint8_t i=0;i<8;i++){tmp[i+1]=(byte>>i)&1;}
for(uint8_t i=0;i<10;i++){data(tmp[i]);_delay_us(DEBUG_DELAY);}
_delay_us(DEBUG_DELAY*2);
}

/*For printing text use this function*/
void dbg_print_text(char *c){
dbg_enable();
for(uint8_t i=0;i<strlen(c);i++){dbg_single_byte(c[i]);}
dbg_disable();
}

void dbg_print_integer(uint32_t num){
uint32_t curr=num;uint8_t buf[10],cnt=0;
while(curr!=0){buf[cnt]=curr%10;curr=curr/10;cnt++;}
for(int i=cnt-1;i>-1;i--){dbg_single_byte(buf[i]+48);}
}

void dbg_print_hex(uint8_t hex){
dbg_enable();
uint8_t d1=(hex/16);
if(d1>9){d1=d1+55;}else{d1=d1+48;}
uint8_t d2=(hex%16);
if(d2>9){d2=d2+55;}else{d2=d2+48;}
dbg_single_byte('0');
dbg_single_byte('x');
dbg_single_byte(d1);
dbg_single_byte(d2);
dbg_disable();
}



/*For printing any number(including int & float) use this function*/
/*If you want to display float number just put always_float=1*/
void dbg_print_number(double num, uint8_t always_float){
dbg_enable();
if     (num<0) {num=-num;dbg_single_byte('-');}
uint32_t bfp_digit=num;
uint32_t afp_digit=num*100.05;
dbg_print_integer(bfp_digit);
if(always_float==1){
  dbg_single_byte('.');
  dbg_single_byte(((afp_digit/10)%10)+48);
  dbg_single_byte((afp_digit%10)+48);
  }
dbg_disable();
}

