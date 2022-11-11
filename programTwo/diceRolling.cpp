#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <locale>

/* 
Jacob Emmerson
Due: 6/5/2022

Random number and simulated dice rolling
*/

int rollDice();
// generates a random sum of two random integers (1-6) to simulate dice rolling

int main() {
    char runAgain = 'y'; // holding the same roll as a !bool

    while(tolower(runAgain) ==  'y') {
        srand(time(NULL)); // new seed every runAgain
        int numberOfRolls, odds = 1, sum = 0;
        int numbers[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // used an array instead of 10 variables
        int tempNum; // holds num before adding to numbers
        double percentError;
        std::cout << "How many times would you like to roll?"
            << std::endl;

        std::cin >> numberOfRolls; 

        std::cout << "Sum    #Rolled    Odds:    %Error:\n" << std::endl;

        for(int i = 0; i < numberOfRolls; i++) {
            tempNum = rollDice();
            numbers[tempNum - 2] += 1;
        }
    
        while(sum <= 10){
            double newOdds = (odds * (numberOfRolls/36.0));
            percentError = abs((newOdds - numbers[sum])/(numbers[sum] + 1)) * 100.00;

            std::cout << sum + 2 << "    " << numbers[sum] << "    " << newOdds << "    "<< percentError << "%" << std::endl;

            odds = (sum < 5) ? (odds + 1) : (odds - 1); // SKAKSDFLKJFdsf
            sum++;
        }

        /*size_t n = sizeof(numbers)/sizeof(numbers[0]); // used for testing output
        for (size_t i = 0; i < n; i++) {
            std::cout << numbers[i] << ' ';
        }*/
        
        do {
            std::cout << "Would you like to run this again? [y/n]" << std::endl; 
            std::cin >> runAgain;
        } while (runAgain != 'y' && runAgain != 'n');
    }

    system("pause");
    return 0;
}

int rollDice() { //roll dice function
    int num;
    num = ((rand() % 6) + 1) + ((rand() % 6) + 1);

    return num;
}
