/* Program name: M01_Assignment_1.cpp
* Author: Ty Stratton
* Date last updated: 10/23/2024
* Purpose: Dividing winnings between winners
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    int jackpot, winners, doublewin, win;
    /* Gather inputs from user */
    cout << "Enter the jackpot amount: ";
    cin >> jackpot;
    cout << "Enter the number of winners: ";
    cin >> winners;
    cout << endl;
    /* Calculations for regular winner (win) and first place (doublewin) */
    win = jackpot/(winners+1);
    doublewin = 2 * win;

    /* Print final output of winnings */
    cout << "The first winner gets: $" << doublewin << endl;
    cout << "All the other winners get: $" << win;
    return 0;
}