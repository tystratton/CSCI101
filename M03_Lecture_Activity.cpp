/* Program name: M03_Lecture_Activity.cpp
* Author: Ty Stratton
* Date last updated: 11/04/2024
* Purpose: Baby alarm
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    int temperature, crying, alarm;
    cout << "Enter the temperature: ";
    cin >> temperature;
    cout << "Is the alarm on? (1 for yes, 0 for no): ";
    cin >> alarm;
    cout << "Is the baby crying (1 for yes, 0 for no): ";
    cin >> crying;
    if (alarm == 1 and (temperature < 70 or crying == 1)){
        cout << "The alarm will go off.";
    }
    else{
        cout << "The alarm wil not go off.";
    }
    return 0;
}