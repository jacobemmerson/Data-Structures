#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string>

#include "gun.h"
#include "handgun.h"
#include "pistol.h"
#include "revolver.h"

/*
name: Jacob Emmerson

this program practices inheritance from classes using a base gun class to derived gun classes.

*/

int main() {

    // only pistol and revolver classes have print functions, but every class has a constructor 

    /*
    handgun:
    manufacturer
    caliber
    grips
    sights
    laser

    pistol:
    semiAuto

    revolver:
    singleAction
    numberOfRounds
    */

    Revolver FirstGun("Nerf", "Foam Rounds", "Plastic Grip", "Orange Irons", false, true, 8);
    Pistol SecondGun("My Pop Gun", "Pop Caps", "Leather", "Irons", true, true);

    FirstGun.printRevolver();
    SecondGun.printPistol();

    system("pause");
    return 0;
}