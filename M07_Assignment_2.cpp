/* Program name: M07_Assignment_2.cpp
* Author: Ty Stratton
* Date last updated: 12/2/2024
* Purpose: Resin order creator
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

enum sizeType {S, M, L};

// Structure for mold
struct moldType{
    string shape;
    sizeType size;
    double price, weight;
};

// Structure for customer
struct customerType{
    string fname, lname, street, address;
};

// Structure for order 
struct orderType{
    customerType customer;
    moldType products[10];
    int numProdOrdered;
    double subTotal, totalWeight, shippingCost;
};

// Read catalog.txt into an array
void readCatalog(moldType productCatalog[], int numProducts){
    ifstream file("catalog.txt");
    string size;
    for (int i = 0; i < numProducts; i++){
        file >> productCatalog[i].shape >> size >> productCatalog[i].price >> productCatalog[i].weight;
        if (size == "S"){
            productCatalog[i].size = S;
        }
        else if (size == "M"){
            productCatalog[i].size = M;
        }
        else if (size == "L"){
            productCatalog[i].size = L;
        }
    }
    file.close();
}

// Print product to console or .txt
void printProduct(ostream& os, moldType mold){
    string size;
    if (mold.size == S){
        size = "S";
    }
    else if (mold.size == M){
        size = "M";
    }
    else if (mold.size == L){
        size = "L";
    }
    os << mold.shape << " - " << size << " $" << fixed << setprecision(2) << mold.price << " " << mold.weight << "g";
}

// Enter customer information 
void enterOrder(orderType& order, moldType catalog[], int numItemsInCatalog){
    customerType customer;
    string address, street, size;
    char response;
    int choice;
    cout << "Enter the customer first name: ";
    cin >> order.customer.fname;
    cout << "Enter the customer last name: ";
    cin >> order.customer.lname;
    cout << "Enter the customer street address: ";
    cin.ignore();
    getline(cin,order.customer.street);
    cout << "Enter the customer city, state, and zip code: ";
    getline(cin, order.customer.address);
    

    // Loop for choosing products
    bool flag = false;
    while (flag == false && order.numProdOrdered < 10){
        cout << "Please choose a product from list: " << endl;
        for (int i = 0; i < numItemsInCatalog; i++){
            cout << i + 1 << ". ";
            printProduct(cout, catalog[i]);
            cout << "\n";
        }
        while (true) {
            cin >> choice;
            if (cin.fail() || (choice < 1 || choice > 20)) {
                cin.clear();  // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                cout << "Invalid number. Please enter a number between 1 and 20: ";
            } else {
                break;  // Valid party number
            }
        }
        // Add item to order
        cout << "Item: " << catalog[choice - 1].shape << " - " << size << "$" << catalog[choice - 1].price << " " << catalog[choice - 1].weight << "g added." << endl;
        order.products[order.numProdOrdered].shape = catalog[choice - 1].shape;
        order.products[order.numProdOrdered].size = catalog[choice - 1].size;
        order.products[order.numProdOrdered].price = catalog[choice - 1].price;
        order.products[order.numProdOrdered].weight = catalog[choice - 1].weight;
        order.numProdOrdered++;

        cout << "\n";
        // Max number of items a user can order is 10
        if(order.numProdOrdered == 10){
                cout << "Maximum number of products ordered." << endl;
                flag = true;
        }
        else{
            cout << "Do you want to add another product to the order? ";
            // Input validation
            while (true) {
                cin >> response;
                tolower(response);
                if (cin.fail() || (response != 'y' && response != 'n')) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid response. Please type 'y' or 'n': ";
                } 
                else {
                    break;  // Valid answer
                }
            } 
            // Flag to check if they want to continue loop
            if (response == 'n'){
                    flag = true;
            }
        } 
    }
}

void printOrder(ostream& os, orderType& order){
    os << "Customer: " << order.customer.fname << " " << order.customer.lname << endl;
    os << order.customer.street << endl;
    os << order.customer.address << endl;
    os << endl;
    double subtotal = 0, weight = 0, shipping = 0, total = 0;
    os << "Products Ordered: " << endl;
    for (int i = 0; i < order.numProdOrdered; i++){
        printProduct(os, order.products[i]);
        os << endl;
        weight += order.products[i].weight;
        subtotal += order.products[i].price;
    }
    // Calculate shipping
    shipping = 0.58 * (weight/28.35);
    total = shipping + subtotal;
    os << endl;
    os << "Subtotal: $" << subtotal << endl;
    os << "Total Weight " << weight << "g" << endl;
    os << "Shipping Cost: $" << fixed << setprecision(2) << shipping << endl;
    os << "Total Cost: $" << fixed << setprecision(2) << total << endl;
}

int main(){
    // Read mold
    moldType molds[20];
    readCatalog(molds, 20);

    cout << "Welcome to Judy's Resin Molds!" << endl;
    bool flag = false;
    while (flag == false){
        char response;
        // Customer order
        orderType order[20];
        enterOrder(order[0], molds, 20);
        ofstream outFile(order[0].customer.lname + ".txt");

        // Print order to console and .txt
        printOrder(outFile, order[0]);
        printOrder(cout, order[0]);

        cout << "Do you want to enter another order? ";
        while (true) {
            cin >> response;
            tolower(response);
            if (cin.fail() || (response != 'y' && response != 'n')) {
                cin.clear();  // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                cout << "Invalid response. Please type 'y' or 'n': ";
            } 
            else {
                break;  // Valid answer
            }
        }
        if (response == 'n'){
            flag = true;
        }
        // Reset number of products ordered
        order[0].numProdOrdered = 0;
    }  
    cout << "Have a nice day!";
    return 0; 
}
    
