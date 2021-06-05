

#include <avr/io.h>
#include <util/delay.h>
#include "debug.h"
#include "isp.h"
#include "fuse.h"
#include "deep_sleep.h"
 

int main(void){
_delay_ms(1000);
dbg_print_text("\n\n");
dbg_print_text("------------------------------------------------------------------\n");
dbg_print_text("                 AVR standalone programmer & debugger\n");
dbg_print_text("------------------------------------------------------------------\n\n");
if(prgm_mode()==1){
                     led(1);
					 dbg_print_text("Device        : OK\n");
					 uint8_t device=0x00;
					 device=device_ID(2);
					 if     (device==ATmega8)   {atmega8();}
					 else if(device==ATmega328p){atmega328p();}
					 else if(device==ATmega328) {atmega328p();}
					 }
else{
                     dbg_print_text("Device        : Error\n");
					 
					 }
led(0);
_delay_ms(200);

while(1){
          
		  deep_sleep();
		  
		  
		  
		  }
}