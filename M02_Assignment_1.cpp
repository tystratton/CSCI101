/* Program name: M02_Assignment_1.cpp
* Author: Ty Stratton
* Date last updated: 11/3/2024
* Purpose: Read data and create gradebook
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h> // Used to convert double to string
using namespace std;


int main()
{
    string studentNum, studentName, lastName, grade, data;
    double percent;
    ifstream inData; //allow reading from the file
    ofstream outData; // allows writing to a file
    inData.open("gradebook.txt"); // opens the file

    // Set up header
    cout << left;
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << "Student Num" << "| " << setw(30) << "Student Name" << "| "<< setw(10) << "Percent" << "| " << setw(10) << "Grade" << "|" << endl; 
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');

    // Loop to set up multiple rows
    while (inData >> studentNum) {
        inData.ignore(); // Skip the whitespace after studentNum
        inData >> studentName; // Read full name up to a tab or newline
        inData >> lastName; // Read last name to add to first
        studentName += " " + lastName; // Add last name to first
        inData >> percent >> grade; // Read percent and grade
        percent *= 100; // Multiply by 100 for all decimals
        string per = to_string(percent); // Convert double to a string
        per = per.substr(0,6) + "% ";

        // Print the data in table format
        cout << "| " 
        << left << setw(15) << studentNum << "| " 
        << left << setw(30) << studentName << "| " 
        << right << setw(10) << setprecision(2) << per <<  "| " 
        << left << setw(10) << grade << "|" << endl;
        
        cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
        cout << setfill(' ');
    }
    inData.close();
    return 0;
}