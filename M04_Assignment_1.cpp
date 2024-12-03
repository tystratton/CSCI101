/* Program name: M04_Assignment_1.cpp
* Author: Ty Stratton
* Date last updated: 11/12/2024
* Purpose: Process results from an esports tournament
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    cout << "IvyGames Tournament Results:" << endl;
    int average = 0, score, g = 0, s = 0, b = 0, count = 0;
    string username, gold = "", silver = "", bronze = "";
    ifstream inData; // allow reading from the file
    inData.open("scores.txt"); // opens the file
    // Loop line by line
    cout << setw(35) << setfill('-') << "-" << endl;
	cout << setfill(' ');
	cout << "| " << setw(15) << left << "Username" << "| " << setw(15) << "Score" << "|"<< endl; 
	cout << setw(35) << setfill('-') << "-" << endl;
    cout << setfill(' ');

    while (inData >> username >> score) {
    // Fit in table
    cout << "| " << setw(15) << left << username << "| " << setw(15) << score << "|"<< endl; 
    cout << setw(35) << setfill('-') << "-" << endl;
	cout << setfill(' ');
    // Increase count for average compute later
    count++;
    average = average + score;
    if (score > g){
        // Silver becomes bronze
        bronze = silver;
        b = s;

        // Gold becomes silver
        s = g;
        silver = gold;

        // Score becomes gold
        g = score;
        gold = username;
    }
    else if (score > s){
        // Silver becomes bronze
        bronze = silver;
        b = s;

        // Score becomes silver
        s = score;
        silver = username;
    }

    else if (score > b){
        // Score becomes bronze
        b = score;
        bronze = username;
    }
    }
    // Compute average
    average = average/count;

    // Output at end
    cout << endl << "The gold medal winner is " << gold << " with " << g << " points." << endl;
    cout << "The silver medal winner is " << silver << " with " << s << " points." << endl;
    cout << "The bronze medal winner is " << bronze << " with " << b << " points." << endl;
    cout << "The average score is " << average << " points." << endl;
    cout << "Congratulations to the winners! See you at the next tournament.";
    return 0;
}