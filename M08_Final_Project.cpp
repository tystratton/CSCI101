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

enum menu {veggie, hamburger, chickenSlider, hamburgerSlider, veggieSlider, haddock, blt, 
            fauxblt, chickenBurrito, falafel, cheesePizza, pepperoniPizza, fauxmeat, fish};

int menuPrices[] = {
    35, // Veggie Burger
    45, // Hamburger
    38, // Fried Chicken Sliders
    38, // Hamburger Sliders
    38, // Veggie Sliders
    38, // Haddock Sandwich
    42, // BLT
    42, // Faux BLT
    42, // Chicken Burrito
    42, // Falafel Wrap
    59, // Cheese Pizza
    59, // Pepperoni Pizza
    77, // Faux Meat and Chips
    77  // Fish and Chips
};

string getMenuItem(menu item) {
    switch (item) {
        case veggie:
            return "Veggie Burger - $35";
        case hamburger:
            return "Hamburger - $45";
        case chickenSlider:
            return "Fried Chicken Sliders - $38";
        case hamburgerSlider:
            return "Hamburger Sliders - $38";
        case veggieSlider:
            return "Veggie Sliders - $38";
        case haddock:
            return "Haddock Sandwich - $38";
        case blt:
            return "BLT - $42";
        case fauxblt:
            return "Faux BLT - $42";
        case chickenBurrito:
            return "Chicken Burrito - $42";
        case falafel:
            return "Falafel Wrap - $42";
        case cheesePizza:
            return "Cheese Pizza - $59";
        case pepperoniPizza:
            return "Pepperoni Pizza - $59";
        case fauxmeat:
            return "Faux Meat and Chips - $77";
        case fish:
            return "Fish and Chips - $77";
        default:
            return "Invalid Menu Item";
    }
}

struct Reservation{
    string name, time;
    int partyNum;
    bool checkedIn;
};

struct Table{
    int tableNumber, capacity;
    bool isTaken;
};

struct Order{
    Reservation reservation;
    Table table;
    menu menu[10];
    bool isOrdered;
    bool isComplete;
    bool isPaid;
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
            cout << "What do you want to change?" << endl;
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
    reservation.checkedIn = false;
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

int main() {
    bool flag = false;
    int currentReservations = 0, orderCount = 0, choice;
    Order order[10];
    Reservation reservations[5] = {
        {"a", "07:30 AM", 10},
        {"b", "04:30 AM", 10},
        {"c", "02:30 AM", 5},
        {"d", "01:30 AM", 2},
        {"e", "09:30 AM", 1}
    };
    currentReservations = 5; // DELETE LATER

    Table tables[5] = { // table number, people, taken (0 for open, 1 for taken)
        {1, 6, false},
        {2, 6, false},
        {3, 6, false},
        {4, 10, false},
        {5, 10, false}
    };

    string taken;

    while (flag == false) {
        // --- MAIN MENU
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

        if (choice == 1) { // --- 1. MAKE RESERVATION
            Reservation newReservation;
            char userResponse = 'N';
            while (userResponse == 'N') {
                getReservation(newReservation);
                userResponse = makeReservation(newReservation);
                if (userResponse == 'Y') {
                    if (currentReservations < 10) {
                        reservations[currentReservations] = newReservation;
                        currentReservations++;
                    } else {
                        cout << "Sorry, we cannot take more reservations at the moment.";
                        break;
                    }
                }
            }
        } else if (choice == 2) { // --- 2. CHECK-IN RESERVATION
            cout << "Choose the reservation to check in: " << endl;

            // Display valid reservations and keep track of the mapping
            int mapping[5]; // Array to map displayed numbers to actual indices
            int displayCount = 0;
            for (int i = 0; i < currentReservations; i++) {
                if (!reservations[i].checkedIn) {
                    mapping[displayCount] = i; // Store the actual index
                    displayCount++;
                    cout << displayCount << ": " << reservations[i].name << " - "
                         << reservations[i].time << ", " << reservations[i].partyNum << " people" << endl;
                }
            }

            if (displayCount == 0) {
                cout << "No reservations available to check in." << endl;
                continue;
            }

            int reservationChoice;
            while (true) {
                cin >> reservationChoice;
                if (cin.fail() || reservationChoice < 1 || reservationChoice > displayCount) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid number. Choose the reservation to check in: ";
                } else {
                    break;  // Valid choice
                }
            }

            // Map the choice back to the actual index in the reservations array
            int actualIndex = mapping[reservationChoice - 1];

            cout << "Please assign a table (O open/X taken): " << endl;
            for (int i = 0; i < 5; i++) {
                taken = tables[i].isTaken ? "O" : "X";
                cout << tables[i].tableNumber << ": " << tables[i].capacity << " people " << taken << endl;
            }

            int tableChoice;
            while (true) {
                cin >> tableChoice;
                if (cin.fail() || tableChoice < 1 || tableChoice > 5 || tables[tableChoice - 1].isTaken) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid number or table is taken. Choose an open table: ";
                }
                else if(tables[tableChoice - 1].capacity < reservations[actualIndex].partyNum){
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Party number exceeds table size. Choose an open table: ";
                } 
                else {
                    tables[tableChoice - 1].isTaken = true; // Mark table as taken
                    reservations[actualIndex].checkedIn = true; // Mark reservation as checked in
                    cout << "Reservation for " << reservations[actualIndex].name
                         << " checked in at table " << tables[tableChoice - 1].tableNumber << "." << endl;
                    break;
                }
            }
        order[orderCount].table = tables[tableChoice - 1];
        order[orderCount].reservation = reservations[actualIndex];
        order[orderCount].isComplete = false;
        orderCount++;
        }
        // --- 3. ENTER ORDER
        else if (choice == 3){
            if (orderCount == 0){
                cout << "No orders to process." << endl;
                continue;
            }
            else{
            cout << "Please choose the table for the order: " << endl;
            int mapping[5];
            int displayCount = 0;
            for (int i = 0; i < orderCount; i++){
                if (!order[i].isOrdered && !order[i].isPaid){
                    mapping[displayCount] = i;
                    displayCount++;
                    cout << displayCount << ": Table " << order[i].table.tableNumber << endl;
                }
            }

            if (displayCount == 0) {
                cout << "No orders to complete" << endl;
                continue;
            }

            int orderChoice;
            while (true) {
                cin >> orderChoice;
                if (cin.fail() || orderChoice < 1 || orderChoice > displayCount) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid number. Choose a table for the order: ";
                }
                else{
                    break;
                }
            }
            int actualIndex = mapping[orderChoice - 1];
                for (int i = 0; i < order[actualIndex].reservation.partyNum; i++){
                    cout << "Please choose entree number " << i+1 << endl;
                    cout << "1: Veggie Burger" << endl;
                    cout << "2: Hamburger" << endl;
                    cout << "3: Fried Chicken Sliders" << endl;
                    cout << "4: Hamburger Sliders" << endl;
                    cout << "5: Veggie Sliders" << endl;
                    cout << "6: Haddock Sandwich" << endl;
                    cout << "7: BLT" << endl;
                    cout << "8: Faux BLT" << endl;
                    cout << "9: Chicken Burrito" << endl;
                    cout << "10: Falafel Wrap" << endl;
                    cout << "11: Cheese Pizza" << endl;
                    cout << "12: Pepperoni Pizza" << endl;
                    cout << "13: Faux Meat and Chips" << endl;
                    cout << "14: Fish and Chips" << endl;
                    int choice;
                    while (true) {
                        cin >> choice;
                        if (cin.fail() || choice < 1 || choice > 14) {
                            cin.clear();  // Clear error flag
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                            cout << "Invalid number. Choose an entree number: " << endl;
                        }
                        else{
                            break;
                        }
                    }
                    switch (choice) {
                        case 1:
                            order[actualIndex].menu[i] = veggie;
                            break;
                        case 2:
                            order[actualIndex].menu[i] = hamburger;
                            break;
                        case 3:
                            order[actualIndex].menu[i] = chickenSlider;
                            break;
                        case 4:
                            order[actualIndex].menu[i] = hamburgerSlider;
                            break;
                        case 5:
                            order[actualIndex].menu[i] = veggieSlider;
                            break;
                        case 6:
                            order[actualIndex].menu[i] = haddock;
                            break;
                        case 7:
                            order[actualIndex].menu[i] = blt;
                            break;
                        case 8:
                            order[actualIndex].menu[i] = fauxblt;
                            break;
                        case 9:
                            order[actualIndex].menu[i] = chickenBurrito;
                            break;
                        case 10:
                            order[actualIndex].menu[i] = falafel;
                            break;
                        case 11:
                            order[actualIndex].menu[i] = cheesePizza;
                            break;
                        case 12:
                            order[actualIndex].menu[i] = pepperoniPizza;
                            break;
                        case 13:
                            order[actualIndex].menu[i] = fauxmeat;
                            break;
                        case 14:
                            order[actualIndex].menu[i] = fish;
                            break;
                        default:
                            cout << "Unexpected error." << endl;
                            break;
                    }
                }
            order[actualIndex].isOrdered = true;
            // --- 4. COMPLETE ORDER
            // --- 5. CALCULATE AND PAY BILL
            }
        }
        else if (choice == 4){
            cout << "Choose the order to complete: " << endl;
            int mapping[5];
            int displayCount = 0;
            for (int i = 0; i < orderCount; i++){
                if (order[i].isOrdered){
                    mapping[displayCount] = i;
                    displayCount++;
                    cout << displayCount << ": Table " << order[i].table.tableNumber << endl;
                }
            }
            int orderChoice;
            while (true) {
                cin >> orderChoice;
                if (cin.fail() || orderChoice < 1 || orderChoice > displayCount) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid number. Choose a table for the order: ";
                }
                else{
                    break;
                }
            }
            int actualIndex = mapping[orderChoice - 1];
            order[actualIndex].isComplete = true;
            if (displayCount == 0) {
                cout << "No orders to complete" << endl;
                continue;
            }
        }
        else if (choice == 5){
            cout << "Choose the order to calculate the bill: " << endl;
            int mapping[5];
            int displayCount = 0;
            for (int i = 0; i < orderCount; i++){
                if (order[i].isComplete && !order[i].isPaid){
                    mapping[displayCount] = i;
                    displayCount++;
                    cout << displayCount << ": Table " << order[i].table.tableNumber << endl;
                }
            }
            int orderChoice;
            while (true) {
                cin >> orderChoice;
                if (cin.fail() || orderChoice < 1 || orderChoice > displayCount) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid number. Choose a table for the order: ";
                }
                else{
                    break;
                }
            }
            if (displayCount == 0) {
                cout << "No orders to calculate the bill." << endl;
                continue;
            }
            int actualIndex = mapping[orderChoice - 1];
            order[actualIndex].isComplete = true;
            cout << "Here is the bill for table " << order[actualIndex].table.tableNumber << endl;
            double subtotal;
            for (int i = 0; i < order[actualIndex].reservation.partyNum; i++){
                cout << getMenuItem(order[actualIndex].menu[i]) << endl;
                subtotal += menuPrices[order[actualIndex].menu[i]];
            }
            double tip = subtotal * .2;
            double tax = subtotal * .1;
            double total = subtotal + tip + tax;
            cout << "Subtotal: $" << subtotal << endl;
            cout << "Tip: $" << fixed << setprecision(2) << tip << endl;
            cout << "Tax: $" << fixed << setprecision(2) << tax << endl;
            cout << "Total: $" << fixed << setprecision(2) << total << endl;
            cout << "Pay bill? ";
            char userResponse;
            while (true) {
                cin >> userResponse;
                if (cin.fail() || (userResponse != 'y' && userResponse !=  'n')) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid response. Please respond with 'y' or 'n': ";
                } else {
                    break;  // Valid party number
                }
            }
            if (userResponse == 'y'){
                order[actualIndex].isPaid = true;
            }
        }
     
    }
    return 0;
}


