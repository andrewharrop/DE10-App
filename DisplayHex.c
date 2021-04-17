/* This files provides address values that exist in the system */
#include <stdio.h>
#define BOARD                 "DE10-Standard"

/* Memory */
#define DDR_BASE              0x00000000
#define DDR_END               0x3FFFFFFF
#define A9_ONCHIP_BASE        0xFFFF0000
#define A9_ONCHIP_END         0xFFFFFFFF
#define SDRAM_BASE            0xC0000000
#define SDRAM_END             0xC3FFFFFF
#define FPGA_PIXEL_BUF_BASE   0xC8000000
#define FPGA_PIXEL_BUF_END    0xC803FFFF
#define FPGA_CHAR_BASE        0xC9000000
#define FPGA_CHAR_END         0xC9001FFF

/* Cyclone V FPGA devices */
#define LED_BASE	      0xFF200000
#define LEDR_BASE             0xFF200000
#define HEX3_HEX0_BASE        0xFF200020
#define HEX5_HEX4_BASE        0xFF200030
#define SW_BASE               0xFF200040
#define KEY_BASE              0xFF200050
#define JP1_BASE              0xFF200060
#define JP2_BASE              0xFF200070
#define PS2_BASE              0xFF200100
#define PS2_DUAL_BASE         0xFF200108
#define JTAG_UART_BASE        0xFF201000
#define JTAG_UART_2_BASE      0xFF201008
#define IrDA_BASE             0xFF201020
#define TIMER_BASE            0xFF202000
#define TIMER_2_BASE          0xFF202020
#define AV_CONFIG_BASE        0xFF203000
#define RGB_RESAMPLER_BASE    0xFF203010
#define PIXEL_BUF_CTRL_BASE   0xFF203020
#define CHAR_BUF_CTRL_BASE    0xFF203030
#define AUDIO_BASE            0xFF203040
#define VIDEO_IN_BASE         0xFF203060
#define EDGE_DETECT_CTRL_BASE 0xFF203070
#define ADC_BASE              0xFF204000

/* Cyclone V HPS devices */
#define HPS_GPIO0_BASE        0xFF708000
#define HPS_GPIO1_BASE        0xFF709000
#define HPS_GPIO2_BASE        0xFF70A000
#define I2C0_BASE             0xFFC04000
#define I2C1_BASE             0xFFC05000
#define I2C2_BASE             0xFFC06000
#define I2C3_BASE             0xFFC07000
#define HPS_TIMER0_BASE       0xFFC08000
#define HPS_TIMER1_BASE       0xFFC09000
#define HPS_TIMER2_BASE       0xFFD00000
#define HPS_TIMER3_BASE       0xFFD01000
#define HPS_RSTMGR	      0xFFD05000
#define HPS_RSTMGR_PREMODRST  0xFFD05014
#define FPGA_BRIDGE           0xFFD0501C

#define PIN_MUX		      0xFFD08400
#define CLK_MGR		      0xFFD04000

#define SPIM0_BASE	      0xFFF00000
#define SPIM0_SR	      0xFFF00028
#define SPIM0_DR	      0xFFF00060
/* ARM A9 MPCORE devices */
#define   PERIPH_BASE         0xFFFEC000    // base address of peripheral devices
#define   MPCORE_PRIV_TIMER   0xFFFEC600    // PERIPH_BASE + 0x0600

/* Interrupt controller (GIC) CPU interface(s) */
#define MPCORE_GIC_CPUIF      0xFFFEC100    // PERIPH_BASE + 0x100
#define ICCICR                0x00          // offset to CPU interface control reg
#define ICCPMR                0x04          // offset to interrupt priority mask reg
#define ICCIAR                0x0C          // offset to interrupt acknowledge reg
#define ICCEOIR               0x10          // offset to end of interrupt reg
/* Interrupt controller (GIC) distributor interface(s) */
#define MPCORE_GIC_DIST       0xFFFED000    // PERIPH_BASE + 0x1000
#define ICDDCR                0x00          // offset to distributor control reg
#define ICDISER               0x100         // offset to interrupt set-enable regs
#define ICDICER               0x180         // offset to interrupt clear-enable regs
#define ICDIPTR               0x800         // offset to interrupt processor targets regs
#define ICDICFR               0xC00         // offset to interrupt configuration regs

/* 	
	Matthew Vidovic
	Lab1 ECE-3375
	251014434
*/
/*Declare SW and HEX variables as pointers to SW_BASE and HEX3_HEX0_BASE from the adress_map_arm.h file */
volatile int * SW_ptr = (int *)SW_BASE;
volatile int * KEY_ptr = (int *)KEY_BASE;
volatile int * LED_ptr = (int *)LED_BASE;
volatile int * HEX_ptr = (int *)HEX3_HEX0_BASE;
volatile int * HEX2_ptr = (int *)HEX5_HEX4_BASE;
volatile int delay= 10000;


unsigned int count(unsigned int i) {
 unsigned int ret=1;
 while (i/=10){
	 ret++;
 }
	//printf("%d",ret);
 return ret;
	
}

int array_to_num(int arr[],int n){
    char str[6][3];
    int i;
    char number[13] = {'\n'};

    for(i=0;i<n;i++) sprintf(str[i],"%d",arr[i]);
    for(i=0;i<n;i++)strcat(number,str[i]);

    i = atoi(number);
    return i;
} 


/*Function to display the HEXD Value*/
void DisplayHex(int value)
{
	/*Make an array of 16 elements each representing hex numbers 1-F */
   int lookUpTable[10];
  
  /*Assign each value in the array to 1-F according to each hex value*/
   lookUpTable[0] = 0x3F;
   lookUpTable[1] = 0x6;
   lookUpTable[2] = 0x5B;
   lookUpTable[3] = 0x4F;
   lookUpTable[4] = 0x66;
   lookUpTable[5] = 0x6D;
   lookUpTable[6] = 0x7D;
   lookUpTable[7] = 0x7;
   lookUpTable[8] = 0x7F;
   lookUpTable[9] = 0x6F;

	
	
	
   /*If the value in the switches is less than 16, set HEX to the corresponding hex value, and display it*/
   if(value < 10)
   {
   //*(HEX_ptr) = value;
	   *(HEX_ptr) = (lookUpTable[value]);
   }
	else{
	unsigned int dig=count(value);
		unsigned int temp = value;
	char arr[dig];
	while (dig--) {
		printf("%d",value%10);
 arr[dig]=value%10;
		//printf("%d",dig);
 value/=10;
		
			
		//printf("%d",*(HEX_ptr));

}
				
if (temp<100){
	*(HEX_ptr) = (lookUpTable[arr[0]]<<8)|(lookUpTable[arr[1]]);
}
if (temp >=100){
	*(HEX_ptr) = (lookUpTable[arr[0]]<<16)|(lookUpTable[arr[1]]<<8)|(lookUpTable[arr[2]]);
}
	}
   /*If the value is greater than 16, set HEX to zero*/
   
  
  
  
}
/*function to read slide switch bank value and return it*/
int ReadSwitches(void)
{
   volatile int a;
  a = *SW_ptr;
 return a;
  
}
  
int main(void) {
volatile int delay;
volatile int i;
/*set a certain delay*/
delay = 10000;
  
   while(1)
   {
	
	   //count(234);
	   /*For the main function, simply assign the value from the ReadSwitches() function to the DisplayHex() function*/
			   DisplayHex(165);
			   /*Use a for loop to display the number for the appropriate amount of time*/
			   //for (i = delay; i!= 0; --i);
       }
        
}
