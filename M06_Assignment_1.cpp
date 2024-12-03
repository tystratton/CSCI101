/* Program name: M06_Assignment_1.cpp
* Author: Ty Stratton
* Date last updated: 12/01/2024
* Purpose: Custom car maker
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <limits>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


enum carColorType {sunset, cherry, phantom, titanium, geaux, lightning, forest, midnight, passion, root, storm, ocean, glacial};

// Gets color input
carColorType getColor(string part){
    int response;
    // Header
    cout << "Please choose a color for the " << part << endl;
    cout << "1. Sunset Orange\n"
         << "2. Cherry Bomb\n"
         << "3. Phantom Black\n"
         << "4. Titanium Silver\n"
         << "5. Geaux Gold\n"
         << "6. Lightning Yellow\n"
         << "7. Forest Green\n"
         << "8. Midnight Blue\n"
         << "9. Passion Purple\n"
         << "10. Root Beer\n"
         << "11. Storm Surge\n"
         << "12. Ocean's Rip\n"
         << "13. Glacial White\n";
    cin >> response;
    // Input validation
    while (cin.fail() || response < 1 || response > 13) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Enter a valid number." << endl;
        cin >> response;
    }
    // Matches response to enum
    switch (response){
        case 1:
        return sunset;
        case 2:
        return cherry;
        case 3:
        return phantom;
        case 4: 
        return titanium;
        case 5: 
        return geaux;
        case 6: 
        return lightning;
        case 7:
        return forest;
        case 8:
        return midnight;
        case 9:
        return passion;
        case 10:
        return root;
        case 11: 
        return storm;
        case 12:
        return ocean;
        case 13:
        return glacial;
    }
}

// Gets string to print
string printColor(carColorType color){
    switch(color){
        case sunset:
        return "Sunset Orange";
        case cherry:
        return "Cherry Bomb";
        case phantom:
        return "Phantom Black";
        case titanium:
        return "Titanium Silver";
        case geaux:
        return "Geaux Gold";
        case lightning:
        return "Lightning Yelow";
        case forest:
        return "Forest Green";
        case midnight:
        return "Midnight Blue";
        case passion:
        return "Passion Purple";
        case root:
        return "Root Beer";
        case storm:
        return "Storm Surge";
        case ocean:
        return "Ocean's Rip";
        case glacial:
        return "Glacial White";
    }
}

int main()
{
    string response;
    ofstream outFile("order.txt"); // for storing values later
    while (response != "y"){
        string body = "body", top = "top", trim = "trim";

        // carColorType is separate to print enum value in order.txt later
        carColorType b = getColor(body);
        body = printColor(b);
        carColorType t = getColor(top);
        top = printColor(t);
        carColorType tr = getColor(trim);
        trim = printColor(tr);

        cout << "You have chosen " << body << " for the body, " << top << " for the top, and " << trim << " for the trim." << endl;
        cout << "Do you want to continue with your order (y/n)? ";
        cin >> response;

        // Input validation
        while (cin.fail() && (response != "y" || response != "n")){
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Enter a valid number." << endl;
            cin >> response;
        }

        // Print to file
        if (response == "y"){
            outFile << b << endl;
            outFile << t << endl;
            outFile << tr << endl;
        }
    }
    outFile.close();
    return 0;   
}
