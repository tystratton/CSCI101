/* Program name: M02_Assignment_2.cpp
* Author: Ty Stratton
* Date last updated: 10/31/2024
* Purpose: Create calendar events
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    int count = 0;
    string days[5] = {"first", "second", "third", "fourth", "fifth"}; // To continue print statements in a while
    string event, reminder, date;
    ofstream outFile("events.txt");; // allows writing to a file
    int month, day, year; // variables for user
    // Allows multiple prints without tons of couts
    while (count < 5) {
        cout << "Enter the " << days[count] << " event name: ";
        getline(cin, event);
        cout << "Enter the month for the event: ";
        cin >> month;
        cin.ignore();
        cout << "Enter the day for the event: ";
        cin >> day;
        cin.ignore();
        cout << "Enter the year for the event: ";
        cin >> year;
        cin.ignore();
        // Converting ints to string and adding separators for file.
        date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
        // Creating reminder date
        day = day - 1;
        reminder = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
        if (outFile.is_open()){
            // Header
            outFile << left;
            outFile << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
            outFile << setfill(' ');
            outFile << "| " << setw(19) << "Event Name" << "| " << setw(11) << "Event Date" << "| " << setw(15) << "Reminder Date" << "| " << endl;
            outFile << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
            outFile << setfill(' ');

            // Output
            outFile << "| " << setw(19) << event << "| ";
            outFile << setw(11) << date << "| ";
            outFile << setw(15) << reminder << "| " << endl;
            outFile << "|" << setw(50) << setfill('-') << "-" << "|" << endl;

            count += 1; 
        }
    }
    outFile.close();
    return 0;
}