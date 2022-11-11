#include "revolver.h"
#include "gun.h"
#include "handgun.h"
#include <iostream>
#include <string>

Revolver::Revolver(std::string theManufacturer, std::string theCaliber, std::string theGrips, std::string theSights, bool isLaser, bool isSingleAction, int theRounds) {
    manufacturer = theManufacturer;
    caliber = theCaliber;
    grips = theGrips;
    sights = theSights;
    laser = isLaser;
    singleAction = isSingleAction;
    numberOfRounds = theRounds;
}

Revolver::Revolver() {
    manufacturer = "Unknown";
    caliber = "Unknown";
    grips = "Unknown";
    sights = "Unknown";
    laser = false;
    singleAction = true;
    numberOfRounds = 5;
}

void Revolver::printRevolver() {
    std::cout << "Revolver: " << manufacturer << ", " << caliber << ", " << grips << ", " << sights << ", Has Laser: " << laser << ", Is Single Action: " << singleAction << ", Number of Rounds: " << numberOfRounds << std::endl;
}