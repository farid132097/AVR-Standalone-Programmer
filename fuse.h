#define  ATmega8           0x07
#define  ATmega32          0x02
#define  ATmega328         0x14
#define  ATmega328p        0x0F

#define  ATmega8_ext_clock 0x00
#define  ATmega8_1MHz      0x01
#define  ATmega8_2MHz      0x02
#define  ATmega8_4MHz      0x03
#define  ATmega8_8MHz      0x04

#define  ATmega328p_8MHz   0x02
#define  ATmega328p_128kHz 0x03

void atmega8(void){
dbg_print_text("Device ID     : ATmega8\n");
uint8_t var=0x00;
var=Lfuse();
if     ((var & 0x0F)==ATmega8_1MHz){                     dbg_print_text("CPU frequency : Internal RC 1MHz\n");}
                     else if((var & 0x0F)==ATmega8_2MHz){dbg_print_text("CPU frequency : Internal RC 2MHz\n");}
                     else if((var & 0x0F)==ATmega8_4MHz){dbg_print_text("CPU frequency : Internal RC 4MHz\n");}
                     else if((var & 0x0F)==ATmega8_8MHz){dbg_print_text("CPU frequency : Internal RC 8MHz\n");}
var=Lfuse();
if(((var & 0x30)>>4)==0)  {                             dbg_print_text("Start-up time : 6 CK, 0 ms\n");}
else if(((var & 0x30)>>4)==1)  {                        dbg_print_text("Start-up time : 6 CK, 4 ms\n");}
else if(((var & 0x30)>>4)==2)  {                        dbg_print_text("Start-up time : 6 CK, 64 ms\n");}
if((var & (1<<7))==0){                                  dbg_print_text("BOD level     : 4.0v\n");}
else{                                                     dbg_print_text("BOD level     : 2.7v\n");}
if((var & (1<<6))==0){                                  dbg_print_text("BOD status    : Enabled\n");}
else{                                                     dbg_print_text("BOD status    : Disabled\n");}

var=Hfuse();
if((var & (1<<0))==0){                                  dbg_print_text("Boot Reset    : Enabled\n");}
else{                                                     dbg_print_text("Boot Reset    : Disabled\n");}
if     (((var & 0x06)>>1)==0){                          dbg_print_text("Boot Size     : 1024 words (2048 bytes)\n");}
else if(((var & 0x06)>>1)==1){                          dbg_print_text("Boot Size     : 512 words (1024 bytes)\n");}
else if(((var & 0x06)>>1)==2){                          dbg_print_text("Boot Size     : 256 words(512 bytes)\n");}
else if(((var & 0x06)>>1)==3){                          dbg_print_text("Boot Size     : 128 words(256 bytes)\n");}
if((var & (1<<3))==0){                                  dbg_print_text("EESAVE        : Enabled (EEPROM preserved when chip erased)\n");}
else{                                                     dbg_print_text("EESAVE        : Disabled (EEPROM erased when chip erased)\n");}
if((var & (1<<4))==0){                                  dbg_print_text("CKOPT         : Enabled (Oscillator option, High power swing on)\n");}
else{                                                     dbg_print_text("CKOPT         : Disabled (Oscillator option, High power swing off)\n");}
if((var & (1<<6))==0){                                  dbg_print_text("WDTON         : Enabled (Watchdog always on)\n");}
else                   {                                  dbg_print_text("WDTON         : disabled (Watchdog off)\n");}
dbg_print_text("\nFuse Bits     : LF[");
                     var=Lfuse();
					 dbg_print_hex(var);
					 dbg_print_text("]  HF[");
					 var=Hfuse();
					 dbg_print_hex(var);
					 dbg_print_text("]\n");
}

void atmega328p(void){
uint8_t device=0x00;
device=device_ID(2);
if(device==ATmega328p)    dbg_print_text("Device ID     : ATmega328p\n");
else if(device==ATmega328)dbg_print_text("Device ID     : ATmega328\n");
uint8_t var=0x00;
var=Lfuse();
if     ((var & 0x0F)==ATmega328p_8MHz){                  dbg_print_text("CPU frequency : Internal RC 8MHz\n");}
else if((var & 0x0F)==ATmega328p_128kHz){                dbg_print_text("CPU frequency : Internal RC 128kHz\n");}
var=Lfuse();
if(((var & 0x30)>>4)==0)  {                             dbg_print_text("Start-up time : 6 CK, 0 ms\n");}
else if(((var & 0x30)>>4)==1)  {                        dbg_print_text("Start-up time : 6 CK, 4.1 ms\n");}
else if(((var & 0x30)>>4)==2)  {                        dbg_print_text("Start-up time : 6 CK, 65 ms\n");}
if((var & (1<<7))==0){                                  dbg_print_text("CKDIV8        : Enabled (Clock divided by 8)\n");}
else{                                                     dbg_print_text("CKDIV8        : Disabled (Clock divided by 1)\n");}
if((var & (1<<6))==0){                                  dbg_print_text("Clock output  : Enabled\n");}
else{                                                     dbg_print_text("Clock output  : Disabled\n");}

var=Hfuse();
if((var & (1<<0))==0){                                  dbg_print_text("Boot Reset    : Enabled\n");}
else{                                                     dbg_print_text("Boot Reset    : Disabled\n");}
if     (((var & 0x06)>>1)==0){                          dbg_print_text("Boot Size     : 2048 words (4096 bytes)\n");}
else if(((var & 0x06)>>1)==1){                          dbg_print_text("Boot Size     : 1024 words (2048 bytes)\n");}
else if(((var & 0x06)>>1)==2){                          dbg_print_text("Boot Size     : 512 words(1024 bytes)\n");}
else if(((var & 0x06)>>1)==3){                          dbg_print_text("Boot Size     : 256 words(512 bytes)\n");}
if((var & (1<<3))==0){                                  dbg_print_text("EESAVE        : Enabled (EEPROM preserved when chip erased)\n");}
else{                                                     dbg_print_text("EESAVE        : Disabled (EEPROM erased when chip erased)\n");}
if((var & (1<<6))==0){                                  dbg_print_text("DebugWire     : Enabled\n");}
else{                                                     dbg_print_text("DebugWire     : Disabled\n");}
if((var & (1<<4))==0){                                  dbg_print_text("WDTON         : Enabled (Watchdog always on)\n");}
else                   {                                  dbg_print_text("WDTON         : disabled (Watchdog off)\n");}
dbg_print_text("\nFuse Bits     : LF[");
                     var=Lfuse();
					 dbg_print_hex(var);
					 dbg_print_text("]  HF[");
					 var=Hfuse();
					 dbg_print_hex(var);
					 dbg_print_text("]\n");
}