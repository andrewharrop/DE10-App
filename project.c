#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#include "address_map_arm.h"

volatile int * SW_ptr = (int *)SW_BASE;
volatile int * LED_ptr = (int *)LED_BASE;

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

//Allow person to leave the room, setting the field to 0
char *leaveRoom(int id){
    arr[id-1][6]="0";
    return arr[id-1][6];
};

//Check the temperature for a person, uses a random number
int checkTemperature(id){
    float value = ((rand()%(42-33+1))+33);
   
    /*
    Display temperature on LCD here
    */

    if(value<37.8&&value>35){
        arr[id-1][4] = "0";
        return "0";
    }
    arr[id-1][4] = "1";

    return "1";
};

//Return integer value from buttons
int read_switches(void){
    return *(SW_ptr);
}
int bin_dec_index_converter(int data){
    if(data==0){
        return 0;
    }else if(data==1){
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

int main()
{
    int delay_count;
    int current = 0;
    int sv;
    while(1){
        for(delay_count=350000; delay_count>0;delay_count--);
        current = read_switches();
        sv = bin_dec_index_converter(current);
        if(sv ==0){
            *(LED_ptr) = 0x0000000;

        }else{
            *(LED_ptr) = read_switches();
            printf("\n");
            printf("%d",bin_dec_index_converter(current));
        }



    }
    // srand(time(0));

    // printf("Covid test\n");

    //printf(enterRoom(3));
    //enterRoom();
    return 0;
}
