/* Program name: M06_Lecture_Activity.cpp
* Author: Ty Stratton
* Date last updated: 11/25/2024
* Purpose: Score high, low, average
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    // Intialize variables
    int scores[10];
    int count = 0;
    int response, average = 0, high, low;
    while (count < 10){
        cout << "Enter a score or -1 to exit: ";
        cin >> response;
        if (response == -1){
            break;
        }
        scores[count] = response;
        count++;
    }
    // Loop through length of array using count
    for (int i = 0; i < count; i++) { 
        // For first run
        if (i == 0){
            high = scores[i];
            low = scores[i];
        }
        // High score
        if (scores[i] > high){
            high = scores[i];
        }
        // Low score
        if (scores[i] < low){
            low = scores[i];
        }
        average += scores[i];
    }
    // Average the scores
    average = average/count;
    cout << "Average: " << average << endl;
    cout << "High: " << high << endl;
    cout << "Low: " << low << endl;
    return 0;
}
    
