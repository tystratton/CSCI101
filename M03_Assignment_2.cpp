/* Program name: M03_Assigment_2.cpp
* Author: Ty Stratton
* Date last updated: 11/04/2024
* Purpose: Ghost hunting point calculator 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    // Initialize variables
    string event;
    int frequency;
    int score = 0;
    ifstream inData; //allow reading from the file
    inData.open("ghosts.txt"); // opens the file
    // Dictionaries that onnect event code to points, and event
    map<string, int> points_dict = {{"E", 3}, {"S", 1}, {"F", 2}, {"A", 5}, {"O", 5}, {"D", 3}, {"T", 2}}; 
    map<string, string> event_dict = {{"E", "EVP (electronic voice phenomena)"}, {"S", "shadows or orbs"}, 
    {"F", "footsteps"}, {"A", "full body apparition"}, {"O", "objects moving on own"}, {"D", "doors shutting on own"}, {"T", "thermoCamera hot or cold spots"}};
    // Loop line by line
    cout << "Analyzing Ghost Hunt Data..." << endl;
    while (inData >> event >> frequency) {
        // Calculate score from points dictionary
        score = score + (frequency * points_dict[event]);
        cout << "Found " << frequency << " instances of " << event_dict[event] << "." << endl;
    }
    cout << "The haunting score for this place is " << score << endl;
    // If score is above 15, haunted, else, not haunted
    if (score > 15){
        cout << "This place is haunted" << endl << "Great job! On to the next one.";
    }
    else{
        cout << "This place is probably not haunted." << endl << "Great job! On to the next one.";
    }
    inData.close();
    return 0;
}
