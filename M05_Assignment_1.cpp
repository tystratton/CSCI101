/* Program name: M05_Assigment_1.cpp
* Author: Ty Stratton
* Date last updated: 11/18/2024
* Purpose: Acceleration racing game
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <limits>
#include <cmath>
using namespace std;

double speedDueToAcceleration(double acceleration, int time){
    return acceleration * time;
}

double accelerationFromButton(double buttonForce){
    return buttonForce * 0.463;
}

int main()
{
    int force = -1, second, count = 0;
    double acceleration;
    // Inputs
    cout << "Enter the button force between 0 and 10: ";
    cin >> force;
    while (cin.fail() || force < 0 || force > 10) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a value between 0 and 10: ";
        cin >> force;
    }
        // Takes care of invalid input
    cout << "Enter the total acceleration time in seconds: ";
    cin >> second;

    // Calculate acceleration
    acceleration = accelerationFromButton(force);
    cout << "Acceleration is " << acceleration <<  " m/s^2" << endl;
    cout << setw(15) << "Time in s" << setw(15) << "Speed in m/s" << endl;
    cout << setw(30) << setfill('*') << "*" << endl;
    cout << setfill(' ');

    // Loop to print speeds
    while (count < second){
        cout << setw(15) << count << setw(15) << fixed << setprecision(3) << speedDueToAcceleration(acceleration, count) << endl;
        count = count + 3;
    }
    // For cout where interval is not within 3
    if (count = second){
        cout << setw(15) << second << setw(15) << fixed << setprecision(3) << speedDueToAcceleration(acceleration, second) << endl;
    }
    return 0;
    
}
