#include<string>

#ifndef GUN_H
#define GUN_H

class Gun {
    public:
        Gun(std::string theManufacturer, std::string theCaliber);
        Gun();

    protected:
        std::string manufacturer;
        std::string caliber;
};

#endif