
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#include "address_map_arm.h"

//define pointers to key addresses
volatile int * SW_ptr = (int *)SW_BASE;
volatile int * KEY_ptr = (int *)KEY_BASE;
volatile int * LED_ptr = (int *)LED_BASE;
volatile int * HEX_ptr = (int *)HEX3_HEX0_BASE;
volatile int * HEX2_ptr = (int *)HEX5_HEX4_BASE;

// Definitions for the data structure
#define NUMBER_OF_STUDENTS 9
#define NUMBER_OF_TEACHERS 1

//Structure: {ID, First Name, Last Name, Email, Flag(0:fine,1:temp is bad), InRoom}
char *arr[NUMBER_OF_STUDENTS+NUMBER_OF_TEACHERS][20] = {
    {"1", "John", "Smith", "jsmith@school.com", "0","Teacher", "0"},
    {"2", "Suzy", "Smuth", "ssmuth@school.com", "0","Student","0"},
    {"3", "Alex", "Doe", "adoe@school.com", "0","Student", "0"},
    {"4", "Jane", "Doe", "jdoe@school.com", "0","Student", "0"},
    {"5", "Jacec", "W", "jw@school.com", "0","Student", "0"},
    {"6", "Matthew", "V", "mv@school.com", "0","Student", "0"},
    {"7", "Andrew", "H", "ah@school.com", "0","Student", "0"},
    {"8", "Joe", "Biden", "jbiden@school.com", "0","Student", "0"},
    {"9", "Snoop", "Dog", "sdog@school.com", "0","Student", "0"},
    {"10", "Donald", "Trump", "dtrump@school.com", "0","Student", "0"}
};

int lights = 0;  // Lights on: lights=1, lights off: lights=0


// Change user state to in room, perform checks here to switch on lights
char *enterRoom(int id){
    arr[id-1][6]="1";
    return arr[id-1][6];
};

// Change user state to out of room, perform checks here to switch off lights
char *leaveRoom(int id){
    arr[id-1][6]="0";
    return arr[id-1][6];
};
// void config_interval_timer()
// {
// volatile int * interval_timer_ptr = (int *)TIMER_BASE; // interal timer base address
// /* set the interval timer period for scrolling the HEX displays */
// int counter = 5000000; // 1/(100 MHz) x 5x10^6 = 50 msec
// *(interval_timer_ptr + 0x2) = (counter & 0xFFFF);
// *(interval_timer_ptr + 0x3) = (counter >> 16) & 0xFFFF;
// /* start interval timer, enable its interrupts */
// *(interval_timer_ptr + 1) = 0x7; // STOP = 0, START = 1, CONT = 1, ITO = 1
// }

// Perform temperature check
int checkTemperature(id){
    int value = ((rand()%(42-33+1))+33);
    
    DisplayHex(value);
    /*
    Display temperature on LCD here.
    Display -> Sleep -> Clear
    */
   // Display "please wait", then display the temperature.  2 second sleep here using a timer


    //Flag a person if there temperature is not between 35-37.8 degrees celcius
    if(value<37.8&&value>35){
        arr[id-1][4] = "0";
        return "0";
    }
    arr[id-1][4] = "1";
	arr[id-1][6]="0";
    return "1";
};

// Read value from switches
int read_switches(void){
    return *(SW_ptr);
}

// Read value from push buttons
int read_push_buttons(void){
    return *(KEY_ptr);
}

// Convert distinct selected switch to a unique integer from 1-10.  If no or more than one switch is selected, return 0
// The calculation for this is n = log2(data)-1, where n is the return value as long as it is a whole number and is between 1-10
int bin_dec_index_converter(int data){
    if(data==1){
        return 1;
    }else if(data==2){
        return 2;
    }else if(data==4){
        return 3;
    }else if(data==8){
        return 4;
    }else if(data==16){
        return 5;
    }else if(data==32){
        return 6;
    }else if(data==64){
        return 7;
    }else if(data==128){
        return 8;
    }else if(data==256){
        return 9;
    }else if(data==512){
        return 10;
    }else{
        return 0;
    }
}

void check_lights(){
    int in_room=0;
    for(int i =0; i<10;i++){
		
        if(arr[i][6]=="1"){
            in_room=1;
        }
    }
	//printf("%d",in_room);
	int off_delay = 50000;
    if(in_room==1){
        *(LED_ptr) = 0xFFFFFFFF;
    }else{
		//Animation if lights are off
		for(int j=0; j<off_delay; j++);
		*(LED_ptr) = 0xF0000000;
		for(int j=0; j<off_delay; j++);
		*(LED_ptr) = 0x0F000000;
		for(int j=0; j<off_delay; j++);
		*(LED_ptr) = 0x00F00000;
		for(int j=0; j<off_delay; j++);
		*(LED_ptr) = 0x000F0000;
		for(int j=0; j<off_delay; j++);
		*(LED_ptr) = 0x0000F000;
		for(int j=0; j<off_delay; j++);
		*(LED_ptr) = 0x00000F00;
		for(int j=0; j<off_delay; j++);
		*(LED_ptr) = 0x000000F0;
		for(int j=0; j<off_delay; j++);
		*(LED_ptr) = 0x0000000F;


	}
}
// Conditional execution based on the button pressed.
int process_buttons(int input, int id){
    printf("\n");
    switch(input){
        case 1:
            printf("enter room");
            enterRoom(id);
            printf("Check temperature");
            checkTemperature(id);
            break;
        case 2:
            printf("exit room");
            leaveRoom(id);
            
			break;
        case 4:
            printf("light status");
			check_lights();
            break;
    }
}

unsigned int count(unsigned int i) {
 unsigned int ret=1;
 while (i/=10){
	 ret++;
 }
	//printf("%d",ret);
 return ret;
	
}

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
};
    
int main()
{
    int delay_count; // To slow down the program for human consumption.  Uncomment in production.

    int switch_value, converted_switch_value; // These two values will be used to track the binary and decimal switch values respectively
    int button_value, converted_button_value; // These two values will be used to track the binary and decimal button values respectively
	int lastButtonValue = 0;
    while(1){
        for(delay_count=350000; delay_count>0;delay_count--);
        
        // Reading and converting values from switches
        switch_value = read_switches(); //E.g. 0,1,2,4,8,16,32 ...
        converted_switch_value = bin_dec_index_converter(switch_value); // = log2(switch_value)-1 as long as it is whole and between 1-10

        // Reading and converting values from buttons
        button_value = read_push_buttons(); //E.g. 0,1,2,4,8,16,32 ...
        converted_button_value = bin_dec_index_converter(button_value); // = log2(button_value)-1 as long as it is whole and between 1-10
        
        // If the converted value read on the switches is a whole number and is between 1-10 when applied to log2(x)-1
        if(converted_switch_value){
            
            // Set led to current switch, already sanitized
            *(LED_ptr) = read_switches();
            if(button_value!=lastButtonValue){
            //Check if there is a distinct active push button, cannot check the lights here
            if(4>converted_button_value>0){
                process_buttons(converted_button_value, converted_switch_value);
                *(KEY_ptr)=0x00000000;
            }
		}
            
                
            
        }else{
            // Set the led blank
            *(LED_ptr) = 0x0000000;
            if(converted_button_value==4){
                process_buttons(converted_button_value,0);
            }
        }
		lastButtonValue = button_value;


    }

    return 0;
}
