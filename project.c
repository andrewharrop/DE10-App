#include <stdio.h>
#include <stdlib.h>

// Due to the nature of the current circumstances, peripherals could be used to simulate the real world application
//Jac

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

checkTemperature(value){
    if(value<37.8&&value>35){
        return 0;
    }
    return 1;
};

int main()
{
    printf("Hello world!\n");
    printf(enterRoom(3));

    //enterRoom();
    return 0;
}
