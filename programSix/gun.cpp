#include<string>
#include "gun.h"

Gun::Gun(std::string theManufacturer, std::string theCaliber) {
    manufacturer = theManufacturer;
    caliber = theCaliber;
}

Gun::Gun() {
    manufacturer = "Unknown";
    caliber = "Unknown";
}