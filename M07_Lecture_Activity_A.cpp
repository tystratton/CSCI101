/* Program name: M07_Lecture_Activity_A.cpp
* Author: Ty Stratton
* Date last updated: 12/2/2024
* Purpose: Reads students' names followed by their test scores
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct studentType{
    string studentFName, studentLName;
    int testScore;
    char grade;
};

void readStudentData(studentType students[]){
    for (int i = 0; i < 5; i++){
        cout <<  "First name: ";
        cin >> students[i].studentFName;
        cout << "Last name: ";
        cin >> students[i].studentLName;
        cout << "Test score: ";
        cin >> students[i].testScore;
    }
}

void assignGrade(studentType students[]){
    for(int i = 0; i < 5; i++){
        if (students[i].testScore >= 90){
            students[i].grade = 'A';
        }
        else if(students[i].testScore>=80){
            students[i].grade = 'B';
        }
        else if(students[i].testScore>=70){
            students[i].grade = 'C';
        }
        else if(students[i].testScore>=60){
            students[i].grade = 'D';
        }
        else{
            students[i].grade = 'F';
        }
    }
}

int main(){
    studentType students[5];
    cout << "Welcome to Student Grade Analyzer! \n";
    readStudentData(students);
    assignGrade(students);
    cout << "Final Grades: " << endl;
    for(int i = 0; i<5; i++){
        cout << "\t" << students[i].studentLName << ", " << students[i].studentFName << ", " << students[i].grade << endl;
    }
    return 0; 
}
    
