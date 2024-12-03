/* Program name: M06_Lecture_Activity_B.cpp
* Author: Ty Stratton
* Date last updated: 11/27/2024
* Purpose: Find triangle type from 3 given sides as input
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

enum triangleType {noTriangle, scalene, isosceles, equilateral};

triangleType triangleShape(int a, int b, int c){
    if ((a + b) > c && (a + c) > b && (b + c) > a){
        if (a == b && b == c){
            return equilateral;
        }
        else if(a == b || b == c || a == c){
            return isosceles;
        }
        else{
            return scalene;
        }
    }
    else{
        return noTriangle;
    }
}
int main()
{
    int a, b, c;
    cout << "Enter the first side: ";
    cin >> a;
    cout << "Enter the second side: ";
    cin >> b;
    cout << "Enter the third side: ";
    cin >> c;
    triangleType tri = triangleShape(a, b, c);

    switch (tri) {
        case noTriangle:
        cout << "No triangle is formed with those sides.";
            break;
        case equilateral:
            cout << "Equilateral triangle." << endl;
            break;
        case isosceles:
            cout << "Isosceles triangle." << endl;
            break;
        case scalene:
            cout << "Scalene triangle." << endl;
            break;
    }
    return 0; 
}
    
