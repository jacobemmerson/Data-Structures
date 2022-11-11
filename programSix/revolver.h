#include "handgun.h"
#include "gun.h"
#include <string>

#ifndef REVOLVER_H
#define REVOLVER_H

class Revolver : Handgun {
    public:
        Revolver(std::string theManufacturer, std::string theCaliber, std::string theGrips, std::string theSights, bool isLaser, bool isSingleAction, int theRounds);
        Revolver();

        void printRevolver();

    protected:
        bool singleAction;
        int numberOfRounds;
};

#endif