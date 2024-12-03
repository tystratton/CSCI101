/* Program name: M02_Lecture_Activity.cpp
* Author: Ty Stratton
* Date last updated: 10/28/2024
* Purpose: Learn about functions
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    /*
    int result;
    int x, y; 
    cout<<"Enter two numbers "<<endl;
    cin>>x>>y;
    result = pow(x,y); //call to a function
    cout<<result<<endl;

    //manipulate output 
    double pay, rate = 19.99, hours;
    cout << "Enter hours worked " << endl;
    cin >> hours;
    pay = rate * hours;
    //setprecision(2);
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<pay;

    //output in columns
    cout<<setw(10)<<setfill('@')<<left<<"Name"<<setw(10)<<"Pay"<<endl;
    cout<<setw(10)<<left<<"John"<<setw(10)<<19.99<<endl;

    //input strings
    string fullname, fullname2;
    cout<<"Enter your full name"<<endl;
    cin>>fullname; //skips whitespace
    cout<<fullname<<endl;
    cin.ignore(200,'\n'); // so the leftover Doe isn't there
    cout<<"Enter your full name"<<endl;
    getline(cin,fullname2);
    cout<<fullname2; //does not skip whitespace
    return 0;

    //Reading a file
    string studentNum, studentName, percent, grade, data;
    ifstream inData; //allow reading from the file
    ofstream outData; // allows writing to a file
    inData.open("gradebook.txt"); // opens the file

    //read the file

    //output
    //close the file

    cout << left;
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << "Student Num" << "| " << setw(30) << "Student Name" << "| "<< setw(10) << "Percent" << "| " << setw(10) << "Grade" << "|" << endl; 
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');

    while (inData >> studentNum >> studentName >> percent >> grade) {
        cout << "| " << setw(15) << studentNum << "| " << setw(30) << studentName << "| " << setw(10) << percent << "| " << setw(10) << grade << "|" << endl;
    }
    inData.close();
    */
    return 0;
}
