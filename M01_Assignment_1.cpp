/* Program name: M01_Assignment_1.cpp
* Author: Ty Stratton
* Date last updated: 10/23/2024
* Purpose: Binary to decimal conversion
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string one, two, three, four, five, binary;
    cout << "Enter the first binary number: ";
    cin >> one;
    cout << "Enter the second binary number: ";
    cin >> two;
    cout << "Enter the third binary number: ";
    cin >> three;
    cout << "Enter th1e fourth binary number: ";
    cin >> four;
    cout << "Enter the fifth binary number: ";
    cin >> five;
    binary = one + two + three + four + five;
    int num1 = stoi(one);
    int num2 = stoi(two);
    int num3 = stoi(three);
    int num4 = stoi(four);
    int num5 = stoi(five);
    int decimal = num5 + (num4 * 2) + (num3 * 4) + (num2 * 8) + (num1 * 16);
    cout << binary << " converted to decimal is " << decimal;
    return 0;
}