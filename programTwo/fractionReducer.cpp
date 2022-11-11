#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <iostream>

/*
Jacob Emmerson
Due: June 4th, 2022

Fraction reducer using euclid's algorithm
Be wary with very large integers
*/

long int gcd(long, long);
//finds the greatest common denominator using euclid's algorithm

int main() {
    char runAgain = 'y';
    long int divisor, numerator, denominator; //local

    std::cout << "Greetings User, this is a program that will reduce a given fraction to its lowest possible terms." << std::endl;

    do {
        std::cout << "\nPlease enter a numerator (top)" << std::endl;
        std::cin >> numerator;

        std::cout << "Please enter a non-zero denominator (bottom)" << std::endl;
        std::cin >> denominator;

        if(denominator == 0 || !(numerator <= 0 || numerator > 0) || !(denominator <= 0 || denominator > 0)) {
            exit(1); //leads to divison by 0 and non integers break the loop
        }

        divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;

        std::cout << "Your fraction with the lowest terms is " << numerator << "/" << denominator << std::endl;

        do {
            std::cout << "\nWould you like to run this program again? [y/n]" << std::endl;
            std::cin >> runAgain;
        } while (runAgain!= 'y' && runAgain != 'n');
        
    } while(runAgain != 'n');


    system("pause");
    return 0;
}

long int gcd(long int a, long int r) {
    // using euclid's alg
    // gcd(a, b) = gcd(b, r) where r is remainder and a and b are n/d

    while (r != 0) {
        long int b = r;
        r = (a % b);
        a = b;
    }

    std::cout << "\nYour GCD is " << a << std::endl;

    return a;
}