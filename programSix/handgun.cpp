#include <string>
#include "handgun.h"
#include "gun.h"

Handgun::Handgun(std::string theManufacturer, std::string theCaliber, std::string theGrips, std::string theSights, bool isLaser) {
    manufacturer = theManufacturer;
    caliber = theCaliber;
    grips = theGrips;
    sights = theSights;
    laser = isLaser;
}

Handgun::Handgun() {
    manufacturer = "Unknown";
    caliber = "Unknown";
    grips = "Unknown";
    sights = "Unknown";
    laser = false;
}