#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<map>
#include<iostream>

/*
    Jacob Emmerson
    Due July 30th, 2022

    Maps and stores social security numbers by names; iterates through containers to reterieve all names.
    Ability to search an individual by name.

*/

int main() {

    std::map<std::string, long long> SSN;
    std::map<std::string, long long>::const_iterator i;
    std::string input;

    SSN["John Brown"] = 4639241854;
    SSN["Kyle Roberts"] = 9248159243;
    SSN["Lila Greene"] = 1429521042;
    SSN["Tyler Watson"] = 5825921423;
    SSN["Rob Time"] = 2041942020;

    std::cout << "Entries Found: " << std::endl;
    for (i = SSN.begin(); i != SSN.end(); i++) {
        std::cout << (*i).first << std::endl;
    }

    while(1) {
        back:
            std::cout << "\nEnter a name to recieve the corresponding SSN or 'q' to exit the program: ";
            std::getline(std::cin, input);
            if (input == "q") break;
            
            for (i = SSN.begin(); i != SSN.end(); i++) {
                if ((*i).first == input) {
                    std::cout << (*i).first << "'s SSN: " << (*i).second << std::endl; goto back;
                }
            }
        std::cout << "No Matching Entry of That Name. " << std::endl;
    }

    system("pause");
    return 0;
}