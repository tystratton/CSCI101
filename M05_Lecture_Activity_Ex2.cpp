/* Program name: M05_Lecture_Activity.cpp
* Author: Ty Stratton
* Date last updated: 11/18/2024
* Purpose: Creating calculator
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int add(int num1, int num2){
    return num1 + num2;
}

int subtract(int num1, int num2){
    return num1 - num2;
}

int multiply(int num1, int num2){
    return num1 * num2;
}

int divide(int num1, int num2){
    return num1 / num2;
}

int main()
{
    int num1, num2;
    string operation;
    //Inputs
    cout << "Enter first number: " << endl;
    cin >> num1;
    cout << "Enter second number: " << endl;
    cin >> num2;
    cout << "Enter operation to perform (+, -, *, /): " << endl;
    cin >> operation;

    // Add
    if (operation == "+"){
        cout << add(num1,num2);
    }

    // Subtract
    else if(operation == "-"){
        cout << subtract(num1,num2);
    }
    
    // Multiply
    else if(operation == "*"){
        cout << multiply(num1,num2);
    }

    // Divide
    else if(operation == "/"){
        if (num2 > num1) {
            int temp = num1; // Save the value of num1
            num1 = num2;  
            num2 = temp; 
        }    
        // Avoiding divide by zero
        if(num2 != 0){
            cout << divide(num1,num2);
        }
        else{
            cout << "You cannot divide by zero.";
        }
    }
    return 0;
}
    
