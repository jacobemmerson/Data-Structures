#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string>
#include<math.h>

/***
Jacob Emmerson

CIT 245; DUE: July 9th, 2022

Tower of Hanoi is a mathematical puzzle that will be solved using recursive methods in this program. The minimal number of moves to solve the puzzle is (2^n)-1
***/

void towerOfHanoi(int n, std::string Base, std::string Target, std::string Aux) {

    if (n > 0) {
        towerOfHanoi(n - 1, Base, Aux, Target);
        std::cout << "moved disk " << n << " from " << Base << " to rod " << Target << std::endl;
        towerOfHanoi(n - 1, Aux, Target, Base);    
    }

    else {
        return;
    }

}

int main() {
    int disks, moves;

    std::cout << "How many disks do you have: " << std::endl;
    std::cin >> disks;

    towerOfHanoi(disks, "Base", "Target", "Aux");

    std::cout << "There were a total of " << pow(2,disks) - 1 << " moves." << std::endl;


    system("pause");
    return 0;
}