#include "handgun.h"
#include "gun.h"
#include <string>

#ifndef PISTOL_H
#define PISTOL_H

class Pistol : public Handgun {
    public:
        Pistol(std::string theManufacturer, std::string theCaliber, std::string theGrips, std::string theSights, bool isLaser, bool isSemiAuto);
        Pistol();

        void printPistol();


    protected:
        bool semiAuto;
    
};

#endif