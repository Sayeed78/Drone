/*
This file contains code for a script to follow an obsticle course. 
*/

#include <CoDrone.h>
void setup() {
    CoDrone.begin(115200);
    CoDrone.pair();
    CoDrone.takeoff();          //Take off for 3 seconds
    CoDrone.setThrottle(35);            //Throttle for 2 seconds
    CoDrone.move(4);
    CoDrone.setThrottle(0);              // Set throttle back to 0
    CoDrone.setPitch(50);
    CoDrone.setRoll(-50);                //Pitch and roll for 2 seconds
    CoDrone.move(2);
    CoDrone.land();          //Land
}
void loop () {
    byte bt8 = digitalRead(18);
    byte bt4 = digitalRead(14);
    byte bt1 = digitalRead(11);
    if(bt1 && bt4 && !bt8){
        CoDrone.emergencyStop();
    }
}