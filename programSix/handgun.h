#include <string>
#include "gun.h"

#ifndef HANDGUN_H
#define HANDGUN_H

class Handgun : public Gun {
    public:
        Handgun(std::string theManufacturer, std::string theCaliber, std::string theGrips, std::string theSights, bool isLaser);
        Handgun();

    protected:
        std::string grips;
        std::string sights;
        bool laser;
};

#endif