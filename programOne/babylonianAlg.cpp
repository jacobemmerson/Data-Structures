#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

/*
Jacob Emmerson
Babylonian Square Root Algorithm

Given any positive number S, find the square root. 

Make an initial guess; apply the formula to get an approximation of sqrt(S)
*/

int main() {

    int number;
    double guess, r, newNum;
    bool notWithin = true; //true while the number is not close enough

    cout << "Greetings User, enter any positive integer and I will apply the Babylonian Square Root Algorithm until I am within .001 of the correct answer. " 
         << endl;
    cin >> number;

    guess = (number)/2;
    do {
        r = (number)/guess;
        guess = (guess + r)/2;
        newNum = (guess * guess);

        cout << "guessing " << guess << endl;

        if (abs((newNum) - number) <= 0.001) { //actually within 0.001 of the original number instead of the exact answer, but it will be more exact
            notWithin = false;
        }

    } while(notWithin);

    cout << "Checking... \n"
         << guess << " * " << guess << " = " << newNum
         << "\nWhich is less than 0.001 within the exact value!"
         << endl;

    system("pause");
    return 0;
}