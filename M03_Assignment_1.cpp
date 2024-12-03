/* Program name: M03_Assigment_1.cpp
* Author: Ty Stratton
* Date last updated: 11/04/2024
* Purpose: Computer specs given user input
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;


int main()
{
    // Create dictionary for task and minimum ram
    map<int, int> pairs = {
        {1, 12}, {2, 8}, {3, 16}, {4, 8}, {5, 20}, {6, 8}, {7, 6}, {8, 6}, {9, 32}
    };
    int ram, task;

    //Inputs
    cout << "Enter the amount of RAM in GB" << endl;
    cin >> ram;
    cout << "Choose the task you want to do on your computer from the following list:" << endl;
    cout << "1. Android Studio" << endl;
    cout << "2. Visual Studio Code" << endl;
    cout << "3. Gaming" << endl;
    cout << "4. Web Browsing with Chrome" << endl;
    cout << "5. Multiple Programming Tasks (both Android Studio and Visual Studio Code)" << endl;
    cout << "6. Zoom" << endl;
    cout << "7. Email" << endl;
    cout << "8. Create and edit documents" << endl;
    cout << "9. Everything listed above" << endl;
    cin >> task;
    // If available RAM is greater than RAM needed for task
    if (ram >= pairs[task]){
        cout << "Congratulations! You have sufficient RAM for your task.";
    }
    else{
        cout << "Sorry the RAM you have is not sufficient.";
    }

    
    return 0;
}