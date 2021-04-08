#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "address_map_arm.h"

// Due to the nature of the current circumstances, peripherals could be used to simulate the real world application
//Jac

//define pointers to key addresses
volatile int * SW_ptr = (int *)SW_BASE;
volatile int * KEY_ptr = (int *)KEY_BASE;
volatile int * LED_ptr = (int *)LED_BASE;
volatile int * HEX_ptr = (int *)HEX3_HEX0_BASE;
volatile int * HEX2_ptr = (int *)HEX5_HEX4_BASE;


#define NUMBER_OF_STUDENTS 9
#define NUMBER_OF_TEACHERS 1
    //Structure: {ID, First Name, Last Name, Email, Flag(0:fine,1:temp is bad), InRoom}
char *arr[NUMBER_OF_STUDENTS+NUMBER_OF_TEACHERS][20] = {
    {"1", "John", "Smith", "jsmith@school.com", "0","Teacher", "1"},
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
char *enterRoom(int id){
    // Here we would have some temperature checks, but will use random values instead
    //For convenience, we can just reference the index

    // Set them to be "in" the room
    arr[id-1][6]="1";
    return arr[id-1][6];
};

char *leaveRoom(int id){
    arr[id-1][6]="0";
    return arr[id-1][6];
};

int checkTemperature(id){
    float value = ((rand()%(42-33+1))+33);

    if(value<37.8&&value>35){
        arr[id-1][4] = "0";
        return "0";
    }
    arr[id-1][4] = "1";
    return "1";
};


void DisplayHex(int value)
{
	/*Make an array of 10 elements each representing hex numbers 1-9 */
   int lookUpTable[10];
  
  /*Assign each value in the array to 1-9 according to each hex value*/
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

   if(value < 10)
   {
   *(HEX_ptr) = lookUpTable[value];
   }
    
    else{
    }
};
    
int main()
{
    srand(time(0));

    printf("Covid test\n");

    //printf(enterRoom(3));
    //enterRoom();
    return 0;
}
