#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<math.h>

using namespace std;

/*
Jacob Emmerson
Buoyant Force Alg

Given the radius and weight of a sphere, calculate buoyant force
*/

int main() {

    int radius;
    double weight, buoyantForce, volume;
    const double waterWeightVal = 62.4, PI = 3.141592;
    bool recalculate = true; // set to true until the user no longer wants to recalculate

    cout << "Hey User! I'll be calculating the buoyant force of a sphere provided you have the radius; with the weight I'll calculate whether it will float." 
         << endl;

    do {
        cout << "Please enter the radius of the sphere."
             << endl;
        cin >> radius;

        cout << "Great, please enter the weight of the sphere in lbs."
             << endl;
        cin >> weight;

        volume = (PI) * pow(radius, 3) * (4.0/3.0);
        buoyantForce = volume * waterWeightVal; //water weight val is 62.4 lb per cubic foot

        cout << "Buoyant Force = " << buoyantForce
             << endl;

        if (buoyantForce > weight) { //if force of water is greater than that of the weight, it floats
            cout << "It floats!"
                 << endl;
        } else {
            cout << "It sunk..."
                 << endl;
        }

        cout << "Would you like to recalculate? (1 = Yes / 0 = No)"
             << endl;
        cin >> recalculate;
        
    } while(recalculate);
   
    system("pause");
    return 0;
}
