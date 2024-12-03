/* Program name: M07_Assignment_1.cpp
* Author: Ty Stratton
* Date last updated: 12/2/2024
* Purpose: RPG Character creator
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

enum characterClassType {FIGHT, ROGUE, MAGIC, CLERIC};

// Class for character
struct characterType{
    string name;
    double hp, mp;
    int strength, dexterity, intelligence, speed, endurance, faith;
    characterClassType characterClass;
};

// To return strings for print statement
string getCharacterClass(characterClassType characterClass){
    switch(characterClass){
        case FIGHT: return "Fighter";
        case ROGUE: return "Rogue";
        case MAGIC: return "Magician";
        case CLERIC: return "Cleric";  
    }
}

// Display character information after creation
void displayCharacter(characterType characters[], int size){
    for (int i = 0; i < size; i++){
        cout << characters[i].name << " the " << getCharacterClass(characters[i].characterClass) << " stats:" << endl;
        cout << "HP: " << characters[i].hp << endl;
        cout << "MP: " << characters[i].mp << endl;
        cout << "Strength: " << characters[i].strength << endl;
        cout << "Dexterity: " << characters[i].dexterity << endl;
        cout << "Intelligence: " << characters[i].intelligence << endl;
        cout << "Speed: " << characters[i].speed << endl;
        cout << "Endurance: " << characters[i].endurance << endl;
        cout << "Faith: " << characters[i].faith << endl;
        cout << endl;
    }
}

int main(){
    characterType characters[10];
    int count = 0, choice;
    bool flag = false;
    while (count < 10 && flag == false){
            cout << "What is your character's name: ";
            cin >> characters[count].name;
            cout << "What character class do you want " << characters[count].name << " to be?" << endl;
            cout << "1. Fighter Class" << endl;
            cout << "2. Rogue Class" << endl;
            cout << "3. Magician Class" << endl;
            cout << "4. Cleric Class" << endl;
            while (true) {
                cin >> choice;
                if (cin.fail() || choice < 1 || choice > 4) {
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                    cout << "Invalid number. Please enter a number between 1 and 4: ";
                } else {
                    break;  // Valid input
                }
            }
        

        // Assign stats based on the choice
        if (choice == 1) {
            characters[count].characterClass = FIGHT;
            characters[count].hp = 30;
            characters[count].mp = 0;
            characters[count].strength = 16;
            characters[count].dexterity = 10;
            characters[count].intelligence = 5;
            characters[count].speed = 8;
            characters[count].endurance = 15;
            characters[count].faith = 5;
        } else if (choice == 2) {
            characters[count].characterClass = ROGUE;
            characters[count].hp = 20;
            characters[count].mp = 0;
            characters[count].strength = 10;
            characters[count].dexterity = 16;
            characters[count].intelligence = 16;
            characters[count].speed = 15;
            characters[count].endurance = 8;
            characters[count].faith = 5;
        } else if (choice == 3) {
            characters[count].characterClass = MAGIC;
            characters[count].hp = 25;
            characters[count].mp = 20;
            characters[count].strength = 5;
            characters[count].dexterity = 10;
            characters[count].intelligence = 16;
            characters[count].speed = 16;
            characters[count].endurance = 5;
            characters[count].faith = 8;
        } else if (choice == 4) {
            characters[count].characterClass = CLERIC;
            characters[count].hp = 20;
            characters[count].mp = 20;
            characters[count].strength = 5;
            characters[count].dexterity = 10;
            characters[count].intelligence = 8;
            characters[count].speed = 16;
            characters[count].endurance = 5;
            characters[count].faith = 16;
        }
    count++;
    char response;
    cout << "Do you want to create another character (y or n)? ";
    while (true) {
        cin >> response;
        tolower(response);
        if (cin.fail() || (response != 'y' && response != 'n')) {
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
            cout << "Invalid response. Please type 'y' or 'n': ";
        } else {
            break;  // Valid answer
        }
    } 
    // Flag to check if they want to continue loop
        if (response == 'n'){
                flag = true;
        }
    }
    // Display character information
    cout << "\n";
    cout << "Here are the characters you've created: " << endl;
    displayCharacter(characters, count);
    return 0; 
}
    
