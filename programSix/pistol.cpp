#include "gun.h"
#include "handgun.h"
#include "pistol.h"
#include <iostream>
#include <string>

Pistol::Pistol(std::string theManufacturer, std::string theCaliber, std::string theGrips, std::string theSights, bool isLaser, bool isSemiAuto) {
    manufacturer = theManufacturer;
    caliber = theCaliber;
    grips = theGrips;
    sights = theSights;
    laser = isLaser;
    semiAuto = isSemiAuto;
}

Pistol::Pistol() {
    manufacturer = "Unknown";
    caliber = "Unknown";
    grips = "Unknown";
    sights = "Unknown";
    laser = false;
    semiAuto = true;
}

void Pistol::printPistol() {
    std::cout << "Pistol: " << manufacturer << ", " << caliber << ", " << grips << ", " << sights << ", Has Laser: " << laser << ", Is Semi Auto: " << semiAuto << std::endl;
}