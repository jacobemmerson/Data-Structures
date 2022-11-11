#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<fstream>
#include<string>
/*
Jacob Emmerson
CIT 245

Due: July 2nd, 2022

Writes / Reads advice to a file
*/

int main() {
    std::ifstream in;
    std::ofstream out;
    std::string readOrWrite = "0";
    std::string *advice = new std::string();
    std::string *adviceOut = advice;

    do {
        std::cout << "Would you like to read or write to the file? [w/r]:" << std::endl;
        std::cin >> readOrWrite;

        if (readOrWrite != "w" && readOrWrite != "r")
            std::cout << "Please enter a 'w' or 'r'." << std::endl;

    } while (readOrWrite != "w" && readOrWrite != "r");
    std::getchar();

    if (readOrWrite == "w") { //if writing to a file
        out.open("advice.txt");
        if (!out.fail()) {
            std::cout << "Enter your advice for the user: " << std::endl;
            std::getline(std::cin, *adviceOut);
            out << *adviceOut;

            out.close();
        }

        else {
            out.close();
            std::ifstream newFile("advice.txt");
            std::cout << "No File Found... Creating new advice.txt..." << std::endl;
            std::cout << "Enter your advice for the user: " << std::endl;
            std::getline(std::cin, *adviceOut);
            out << *adviceOut;
        }
    }

    else { //if reading a file
        in.open("advice.txt");
        if(!in.fail()) {
            char next;
            in.get(next);
            while (!in.eof()) {
                std::cout << next;
                in.get(next);
            } std::cout << std::endl;

            in.close();
        }

        else {
            in.close();
            std::ifstream newFile("advice.txt");
            std::cout << "New File Created - Nothing to Read...";
            exit(1);
        }

        
    }

    delete advice;

    system("pause");
    return 0;
}