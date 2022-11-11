#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<iostream>

/* 
Jacob Emmerson

June 19th 2022
Money class practice. Using template from 7.1 and 8.1 Friend functions for overloading << and >>. 
*/

class Money {
    public:
        Money();
        Money(double amount);
        Money(int dollars);
        Money(int dollars, int cents); //mostly for the operators
        double getAmount() const;
        int getDollars() const;
        int getCents() const;
        void setMoney();
        void getMoney() const;
        const Money findPercentage(double percentage);

        friend const Money operator +(const Money& amount1, const Money& amount2);
        friend const Money operator -(const Money& amount1, const Money& amount2);
        friend const bool operator >(const Money& amount1 , const Money& amount2) {
            return (amount1.getDollars() * 100 + amount1.getCents()) > (amount2.getDollars() * 100 + amount2.getCents());
        };
        friend const bool operator <(const Money& amount1 , const Money& amount2) {
            return (amount1.getDollars() * 100 + amount1.getCents()) < (amount2.getDollars() * 100 + amount2.getCents());
        };
        friend const Money operator -(const Money& amount) {
            return Money(-amount.getDollars(), -amount.getCents());
        };
        friend bool operator ==(const Money& amount1, const Money& amount2) {
            return (((amount1.getDollars() == amount2.getDollars())) && (amount1.getCents() == amount2.getCents()));
        };

        friend std::ostream& operator <<(std::ostream& outputStream, const Money& amount);

        friend std::istream& operator >>(std::istream& inputStream, Money& amount);

    private:
        int dollars;
        int cents;
        int dollarsPart(double amount) const;
        int centsPart(double amount) const;
        int round(double number) const;
};


int main () {
    double percentage = -1;
    Money myMoney, yourMoney;

    std::cout << "Enter your amount of money: ";
    std::cin >> yourMoney;
    std::cout << "Enter my amount of money: ";
    std::cin >> myMoney;
    std::cout << std::endl;

    std::cout << "You have " << yourMoney << std::endl;
    std::cout << "I have " << myMoney << std::endl;

    if (yourMoney == myMoney) {
        std::cout << "We have the same amount of money.\n";
    }
    else if (yourMoney > myMoney) {
        std::cout << "You have more money.\n";
    }

    else if (yourMoney < myMoney) {
        std::cout << "I have more money.\n";
    }
    else {
        std::cout << "An Error Occured...";
        system("pause");
        exit(1);
    }

    Money ourMoney = yourMoney + myMoney;
    std::cout << yourMoney << " + " << myMoney << " equals " << ourMoney << std::endl;

    Money diffMoney = yourMoney - myMoney;
    std::cout << yourMoney << " - " << myMoney << " equals " << diffMoney << std::endl;

    do {
        std::cout << "Please enter a positive percentage as a standalone integer: ";
        std::cin >> percentage;
    } while (percentage < 0);
    Money yourPercentage = yourMoney.findPercentage(percentage);
    std::cout << percentage << "% of your money = " << yourPercentage << std::endl;
    Money myPercentage = myMoney.findPercentage(percentage);
    std::cout << percentage << "% of my money = " << myPercentage << std::endl;

    system("pause");
    return 0;
}

std::ostream& operator <<(std::ostream& outputStream, const Money& amount) {
    if (amount.dollars < 0 || amount.cents < 0) {
        outputStream << "$-";
    }
    else {
        outputStream << '$';
    }
    outputStream << abs(amount.dollars);

    if (abs(amount.cents) >= 10) {
        outputStream << '.' << abs(amount.cents);
    }
    else {
        outputStream << '.' << '0' << abs(amount.cents);
    }

    return outputStream;
}

std::istream& operator >>(std::istream& inputStream, Money& amount) {
    char dollarSign;
    inputStream >> dollarSign;
    if (dollarSign != '$') {
        std::cout << "No dollar sign in input.\n";
        system("pause");
        exit(1);
    }

    
    double amountAsDouble;
    std::cin >> amountAsDouble;
    amount.dollars = amount.dollarsPart(amountAsDouble);
    amount.cents = amount.centsPart(amountAsDouble);
}

Money::Money() : dollars(0), cents(0) {

}

Money::Money(int dollars) : dollars(dollarsPart(dollars)), cents(0) {

}

Money::Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount)) {

}

Money::Money(int dollars, int cents) {
    this->dollars = dollars;
    this->cents = cents;
}

int Money::dollarsPart(double amount) const {
    return static_cast<int>(amount);
}

int Money::centsPart(double amount) const {
    double doubleCents = amount * 100;
    int intCents = (round(fabs(doubleCents))) % 100;

    if (amount < 0)
        intCents = -intCents;
        
    return intCents;
}

const Money operator +(const Money& amount1, const Money& amount2) {
    int cents1 = amount1.getCents() + amount1.getDollars() * 100;
    int cents2 = amount2.getCents() + amount2.getDollars() * 100;
    int totalCents = cents1 + cents2;

    int finalDollars = abs(totalCents) / 100;
    int finalCents = abs(totalCents) % 100;

    if (totalCents < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }

    return Money(finalDollars, finalCents);

}

const Money operator -(const Money& amount1, const Money& amount2) {
    int cents1 = amount1.getCents() + amount1.getDollars() * 100;
    int cents2 = amount2.getCents() + amount2.getDollars() * 100;
    int diffTotalCents = cents1 - cents2;

    int finalDollars = abs(diffTotalCents) / 100;
    int finalCents = abs(diffTotalCents) % 100;

    if (diffTotalCents < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }

    return Money(finalDollars, finalCents);

}

const Money Money::findPercentage(double percentage) {
    int newMoney = (cents + dollars * 100) * (percentage/100);
    int newDollars = abs(newMoney) / 100;
    int newCents = abs(newMoney) % 100;

    return Money(newDollars, newCents);


}

int Money::round(double number) const {
    return static_cast<int>(floor(number + 0.5));
}

int Money::getDollars() const {
    return dollars;
}

int Money::getCents() const {
    return cents;
}
