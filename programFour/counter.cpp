#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<iostream>

/* 
Jacob Emmerson

June 19th 2022
Increment and decrement practice assignment. Use display(), inc(), and dec(). Initalize variables to 0 and 200 and increase by 85 and decrease by 242 respectively.
*/

class incDec {

    public:
        incDec(int input);
        //initalizes to input num

        incDec();
        //intializes to 0

        void inc() {
            increments++;
            num++;
        };

        void dec() {
            decrements++;
            num--;
        };

        static int getInc() {
            return increments;
        };

        static int getDec() {
            return decrements;
        };

        void display();
        

    private:
        int num;
        static int increments;
        static int decrements;

};

int incDec::increments = 0;
int incDec::decrements = 0;

int main() {

    incDec C2(200), C1;

    std::cout << "\nCurrent state of C1 after " << incDec::getInc() << " increments" << std::endl;
    C1.display();

    std::cout << "\nCurrent state of C2 after " << incDec::getDec() << " decrements"  << std::endl;
    C2.display();

    for(int i = 0; i < 85; i++) {
        C1.inc();
    }

    std::cout << "\nCurrent state of C1 after " << incDec::getInc() << " increments"  << std::endl;
    C1.display();

    for(int j = 0; j < 242; j++) {
        C2.dec();
    }

    std::cout << "\nCurrent state of C2 after " << incDec::getDec() << " decrements" << std::endl;
    C2.display();
    

    system("pause");
    return 0;
}

incDec::incDec() : num(0) {
}

incDec::incDec(int input) : num(input) {
}

void incDec::display() {
    std::cout<< "Count: " << num << std::endl;
    std::cout << "Total Number of Increments and Decrements: " <<
    increments + decrements << std::endl;
}