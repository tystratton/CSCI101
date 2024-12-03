/* Program name: M08_Final_Project.cpp
* Author: Ty Stratton
* Date last updated: 12/09/2024
* Purpose: Final
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <limits>
#include <cctype>
#include <algorithm>
#include <regex>
using namespace std;

struct Reservation{
    string name, time;
    int partyNum;
};

char makeReservation(Reservation &reservation){
    int choice;
    char userResponse;
    cout << "Please confirm the reservation: " << endl;
                cout << "Reservation Name: " << reservation.name << endl;
                cout << "Reservation Time: " << reservation.time << endl;
                cout << "Number in Party: " << reservation.partyNum << endl;
                cout << "Is this information correct [Y]es, [N]o (make changes), [C]ancel? ";
    while (true) {
        cin >> userResponse;
        // Convert the input to uppercase (or lowercase) for uniform comparison
        userResponse = toupper(userResponse);  // You could also use tolower() if preferred

        if (userResponse == 'Y') {
            cout << "Information confirmed." << endl;
            return userResponse;
        }
        else if (userResponse == 'C'){
            cout << "Reservation cancelled." << endl;
            return userResponse;
        }
        else if (userResponse == 'N'){ // Edit reservation
            cout << "What do you want to change?";
            cout << "1. Name" << endl;
            cout << "2. Number of People" << endl;
            cout << "3. Time" << endl;
            cout << "4. Cancel" << endl;
            // 
            while (true) {
                cin >> choice;
                if (cin.fail() || choice <= 0 || choice > 4) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid number. Please enter a number between 1 and 4: ";
                } else {
                    break;  // Valid party number
                }
            }

            if (choice == 1){ // New name for reservation
                cout << "Enter a new name for the reservation: ";
                cin.ignore();
                getline(cin, reservation.name);
            }
            
            else if (choice == 2){ // New number of people for reservation
                cout << "Enter a new number of people for the reservation: ";
                while (true) {
                    cin >> reservation.partyNum;
                    if (cin.fail() || reservation.partyNum <= 0) {
                        cin.clear();  // Clear error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                        cout << "Invalid number. Please enter a positive integer: ";
                    } else {
                        break;  // Valid party number
                    }
                }
            }

            else if (choice == 3){ // New time for reservation
                cout << "Enter a new time for the reservation: ";
                cin.ignore(); 
                // Input validation time
                while (true) {
                    getline(cin, reservation.time);
                    // Regex to match time format (e.g., 12:34 AM or 01:45 PM)
                    regex timeFormat(R"(^([0-1][0-9]):([0-5][0-9])\s?(AM|PM)$)", regex_constants::icase);
                    if (regex_match(reservation.time, timeFormat)) {
                        break;  // Valid time format
                    } 
                    else {
                        cout << "Invalid time format. Please use HH:MM AM/PM format (e.g., 07:30 PM): ";
                    }
                }
            }

            else if (choice == 4){
                cout << "Reservation cancelled.";
                return 'C';
            }
            return makeReservation(reservation);
        }
        else {
                cout << "Invalid input. Please enter [Y]es, [N]o, or [C]ancel: ";
            }
    }
}

void getReservation(Reservation& reservation){
    cout << "Enter a name for the reservation: ";
    cin.ignore();
    getline(cin, reservation.name);

    cout << "Enter the time for the reservation in HH::MM AM/PM: ";

    // Input validation time
    while (true) {
        getline(cin, reservation.time);
        // Regex to match time format (e.g., 12:34 AM or 01:45 PM)
        regex timeFormat(R"(^([0-1][0-9]):([0-5][0-9])\s?(AM|PM)$)", regex_constants::icase);
        if (regex_match(reservation.time, timeFormat)) {
            break;  // Valid time format
        } 
        else {
            cout << "Invalid time format. Please use HH:MM AM/PM format (e.g., 07:30 PM): ";
        }
    }

    int partyNum;
    cout << "Enter the number of people in the party: ";      
    // Input validation partyNum
    while (true) {
        cin >> reservation.partyNum;
        if (cin.fail() || reservation.partyNum <= 0) {
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
            cout << "Invalid number. Please enter a positive integer: ";
        } else {
            break;  // Valid party number
        }
    }
}

int main(){
    bool flag = false;
    int currentReservations = 0;
    int choice;
    Reservation reservations[10];
    while (flag == false){
        // --- MAIN MENU
        int tables[5][3] = { // table number, people, taken (0 for open, 1 for taken)
            {1, 6, 0},
            {2, 6, 0},
            {3, 6, 0},
            {4, 10, 0},
            {5, 10, 0}
        };
        cout << "Welcome to Messijoes" << endl;
        cout << "1. Make Reservation" << endl;
        cout << "2. Check-in Reservation" << endl;
        cout << "3. Enter Order" << endl;
        cout << "4. Complete Order" << endl;
        cout << "5. Calculate and Pay Bill" << endl;
        cin >> choice;
        // Input validation
        while (cin.fail() || choice < 1 || choice > 5) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Enter a valid number." << endl;
            cin >> choice;
        }

        
        if (choice == 1){ // --- 1. MAKE RESERVATION
            Reservation newReservation;
            char userResponse = 'N';
            while (userResponse == 'N'){
                getReservation(newReservation);
                userResponse = makeReservation(newReservation);
                if(userResponse == 'Y'){
                    if (currentReservations < 10){
                        
                        reservations[currentReservations] = newReservation;
                        currentReservations++;
                    }
                    else {
                        cout << "Sorry, we cannot take more reservations at the moment.";
                        break;
                    }
                }
            }
        }
        else if (choice == 2) { // --- 2. CHECK-IN RESERVATION
            if (currentReservations == 0) {
                cout << "No reservations to check in." << endl;
                continue;
            }

            cout << "Choose the reservation to check in: " << endl;
            for (int i = 0; i < currentReservations; i++) {
                cout << i + 1 << ": " << reservations[i].name << " - " << reservations[i].time
                     << ", " << reservations[i].partyNum << " people" << endl;
            }

            int reservationChoice;
            while (true) {
                cin >> reservationChoice;
                if (cin.fail() || reservationChoice < 1 || reservationChoice > currentReservations) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid number. Choose the reservation to check in: ";
                } else {
                    break;  // Valid choice
                }
            }

            cout << "Please assign a table (O open/X taken): " << endl;
            for (int i = 0; i < 5; i++) {
                string taken = (tables[i][2] == 0) ? "(O)" : "(X)";
                cout << tables[i][0] << ": " << tables[i][1] << " people " << taken << endl;
            }

            while (true) {
                cin >> choice;
                if (cin.fail() || choice < 1 || choice > 5 || tables[choice - 1][2] == 1) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid number or table is taken. Choose an open table: ";
                } else {
                    tables[choice - 1][2] = 1; // Mark table as taken
                    cout << "Reservation for " << reservations[choice - 1].name
                         << " checked in at table " << tables[choice - 1][0] << "." << endl;
                    break;
                }
            }
        }
     // --- 2. CHECK-IN RESERVATION

    // --- 3. ENTER ORDER
    // --- 4. COMPLETE ORDER
    // --- 5. CALCULATE AND PAY BILL
}   
return 0;
}
    




   