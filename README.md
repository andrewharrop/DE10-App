Since we do not have access to physical peripherals, we had to simulate them instead.
<br/>
We chose to use the "Swithces" (SW_Base in the address map) to represent students.  <br/>
Switches can be selected, but will only function if one switch is selected at a time.
<br/><br/><br/>
Once a switch, or "Student" is selected, three operations can be performed.  These operations can be selected using the push buttons. (KEY_Base on the address map).<br/>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  1. The student can check into the room, and will be prompted to check their temperature, which is randomly generated.  This function can be &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;activited if the first push button is presses (on CPULator it has a 0 under it)<br/>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 2. The student can leave the room.  This function can be activited if the second push button is presses (on CPULator it has a 1 under it)<br/>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3. The teacher can check the attendence of the room at any time by pressing the third push button (on CPULator it has a 2 under it). This &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;will only work if the teacher is selected (first switch is pressed), if a student attempts to press this button it will return an error.
   <br/>

The last functionality is to check if the lights are on.  It can be activated if no students are selected (No switch buttons pressed).  It is activated by the fourth push button (has a 3 under it).  <br/>
If there are people in the room, the LEDs will turn on and not flicker.  If there is nobody in the room, the LEDs will be flashing.<br/>
