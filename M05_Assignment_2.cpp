/* Program name: M05_Assigment_2.cpp
* Author: Ty Stratton
* Date last updated: 11/20/2024
* Purpose: Baking converter
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

map<string, double> ingredients = {
        {"sugar", 1.59},
        {"flour", 0.762},
        {"cocoa powder", 1.35},
        {"honey", 1.38},
        {"egg", 1.031},
        {"milk", 1.025},
        {"water", 0.997},
        {"oil", 0.91}
    };

// Gets ingredient with input validation
string getIngredient(){
    string ingredient;
    cout << "Enter the name of the ingredient: ";
    cin >> ingredient;
    // Decapitalizes all letters in input
    for (char& c : ingredient) {
        c = tolower(c);
    }
    while (cin.fail() || ingredients.count(ingredient) == 0) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "I don't know that ingredient." << endl 
        << "Here is a list of ingredients I know: Sugar, Flour, Coco Powder, Honey, Egg, Milk, Water, and Oil." << endl 
        << "Enter the name of the ingredient: ";
        cin >> ingredient;
        for (char& c : ingredient) {
        c = tolower(c);
    }
    }
    return ingredient;
}

// Get density from ingredient
double getDensity(string ingredient){
    double density = ingredients[ingredient];
    return density;
}

// Get weight from ingredient
double getWeight(){
    int weight;
    cout << "Enter the weight of your ingredient in g: ";
    cin >> weight;
    while (cin.fail() || weight < 0) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "The weight must be greater than 0 and be a valid input." << endl << "Enter the weight of your ingredient in g: ";
    }
    return weight;
}

// Get volume from ingredient
double getVolume(){
    double volume;
    cout << "Enter the volume of your ingredient in ml: ";
    cin >> volume;
    while (cin.fail() || volume < 0) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "The weight must be greater than 0 and be a valid input." << endl << "Enter the weight of your ingredient in g: ";
    }
    return volume;
}

// Convert weight to volume
double convertWeight(double weight, double density){
    double volume = weight/density;
    return volume;
}

// Convert volume to weight
double convertVolume(double volume, double density){
    double weight = volume * density;
    return weight;
}
    
    

int main()
{
    cout << "Welcome to the baking converter." << endl;
    cout << "This program takes a baking ingredient and converts a weight to a volume unit or a volume to a weight unit." << endl;
    string choice;
    string ingredient = getIngredient();
    double density = getDensity(ingredient);
    cout << "Do you want to convert from weight or volume? (Enter W or V): ";
    cin >> choice;
    // Input validation for choice
    while (cin.fail() || (choice != "W" && choice != "V")) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Please return W or V: ";
    }
    // Convert g to ml
    if (choice == "W"){
        double weight = getWeight();
        double volume = convertWeight(weight, density);
        cout << fixed << setprecision(4) << weight << " g of " << ingredient << " is " << fixed << setprecision(4) << volume << " ml";

    }
    // Convert ml to g
    else{
        double volume = getVolume();
        double weight = convertVolume(volume, density);
        cout << volume << fixed << setprecision(4) << " ml of " << ingredient << " is " << fixed << setprecision(4) << weight << " g";
    }
    return 0;
}
