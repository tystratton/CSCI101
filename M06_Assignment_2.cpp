/* Program name: M06_Assignment_2.cpp
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

int main(){
    string lastName;
    int response, body, top, trim, count = 0;
    string names[10];
    carColorType cars[10][3];

    cout << "Welcome to the car customizer!" << endl;
    while(response != 3 || count <= 9){
        cout << "Please choose an option from the menu: " << endl;
        cout << "1. Read Existing Order" << endl;
        cout << "2. Add New Order" << endl;
        cout << "3. Quit" << endl;
        cin >> response;
        while (cin.fail() || response < 1 || response > 3) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Enter a valid number." << endl;
                cin >> response;
            }

        // Check past order
        if(response == 1){
            cout << "Enter the customer last name for the order: ";
            cin >> lastName;
            ifstream inData; // allow reading from the file
            inData.open(lastName + ".txt"); // opens the file
            inData >> body >> top >> trim;
            cout << "Here is the order for " << lastName << endl;
            cout << "Top Color: " << printColor(carColorType(top)) << endl;
            cout << "Body Color: " << printColor(carColorType(body)) << endl;
            cout << "Trim Color: " << printColor(carColorType(trim)) << endl;
        }

        // Add new order
        else if(response == 2){
            string body = "body", top = "top", trim = "trim", userResponse = "n", name;
            while (userResponse == "n"){
            cout << "Enter the name for the order: ";
            cin >> name;

            // carColorType is separate to print enum value in order.txt later
        
            carColorType b = getColor(body);
            carColorType t = getColor(top);
            carColorType tr = getColor(trim);

            // Check entry with user
            cout << "You have chosen " << printColor(b) << " for the body, " << printColor(t) << " for the top, and " << printColor(tr) << " for the trim." << endl;
            cout << "Do you want to continue with your order (y/n)? ";
            cin >> userResponse;

            // Input validation
            while (cin.fail() || (userResponse != "y" && userResponse != "n")){
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Enter a valid response." << endl;
                cin >> userResponse;
            }

            // Add to 2d array
            if (userResponse == "y"){
                cars[count][0] = b;
                cars[count][1] = t;
                cars[count][2] = tr;
                names[count] = name;
                count++;
                // End program and print to .txts if max input is hit
                if (count == 10){
                    response = 3;
                }
            }
            }
        }
        if (response == 3){
            if (count == 10){
                cout << "You've reached the maximum number of inputs (10).";
            }
            else if (count > 0){
                // Write to files
                for (int i = 0; i < sizeof(cars); i++){
                    ofstream outFile(names[i] + ".txt"); // for storing values later
                    outFile << cars[i][0] << endl;
                    outFile << cars[i][1] << endl;
                    outFile << cars[i][2] << endl;
                }
            }
            return 0;
        }
    }
}
