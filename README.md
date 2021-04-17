Since we do not have access to physical peripherals, we had to simulate them instead.

We chose to use the "Swithces" (SW_Base in the address map) to represent students.  
Switches can be selected, but will only function if one switch is selected at a time.

Once a switch, or "Student" is selected, two operations can be performed.  These operations can be selected using the push buttons. (KEY_Base on the address map).
    1. The student can check into the room, and will be prompted to check their temperature, which is randomly generated.  This function can be activited if the first push button is presses (on CPULator it has a 0 under it)
    2. The student can leave the room.  This function can be activited if the second push button is presses (on CPULator it has a 1 under it)

The last functionality is to check if the lights are on.  It can be activated if no students are selected (No switch buttons pressed).  It is activated by the fourth push button (has a 3 under it).  
If there are people in the room, the LEDs will turn on and not flicker.  If there is nobody in the room, the LEDs will be flashing.