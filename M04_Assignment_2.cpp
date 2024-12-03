/* Program name: M04_Assignment_2.cpp
* Author: Ty Stratton
* Date last updated: 11/12/2024
* Purpose: Convert binary number to a decimal
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <limits>
#include <cmath>

using namespace std;


int main()
{
    list<int> numbers;
    int binary = 0, count = 1, place = 1, decimal = 0;
    cout << "Welcome to the binary number converter 2.0." << endl; 
    cout << "You will enter a binary number 1 digit at a time starting at the right and the program will convert the number to decimal." << endl;
    while (binary != -1){
        cout << "Enter the binary digit at position (" << count << "): ";
        cin >> binary;
        // Takes care of invalid input
        if (cin.fail()) {
            cin.clear();  // Clear the error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Get rid of input
            cout << "Invalid input. A binary digit can only be a 1 or 0." << endl;
            continue;
        }
        // Add the numbers to a list
        if (binary == 0 || binary == 1){
            numbers.push_back(binary);
            count++;
        }
        // End user input
        else if (binary == -1){
            break;
        }
        }
    
    // Building placement to match amount of numbers in list (1, 2, 4, 8, etc.)
    for (int number : numbers) {
        place *= 2;
    }

    // Dividing by 2 since 1 is needed
    place = place / 2;

    // Converting binary to decimal
    for (int number : numbers){
        if (number == 1){
            decimal += place;
        }
        place = place / 2;
    }
    // Output    
    cout << "The decimal is: " << decimal;
    return 0;
}