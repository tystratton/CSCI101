/* Program name: M04_Lecture_Activity.cpp
* Author: Ty Stratton
* Date last updated: 11/11/2024
* Purpose: Create while, for, do-while loops for score averager
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


/* 
---

exercise 2 while loop
int main()
{
    int i = 0;
    double score, total, average;
    int decision = 1;
    while (decision == 1){
        cout << "Submit a score to average: ";
        cin >> score;
        cout << "Do you have another score to submit? 1 to continue, 0 to exit: ";
        cin >> decision;
        total = score + total;
        i++;
    }
    average = total / i;
    cout << "The average score is " << average;
    return 0;
}

---

exercise 2 for loop
int main()
{
    double score, total, average, count;
    int decision = 1;
    for (int i = 0; decision == 1; i++){
        cout << "Submit a score to average: ";
        cin >> score;
        cout << "Do you have another score to submit? 1 to continue, 0 to exit: ";
        cin >> decision;
        total = score + total;
        count = i;
    }
    // adding 1 to count to match how many scores are input
    average = total / (count + 1);
    cout << "The average score is " << average;
    return 0;
}

---

exercise 2 do while
int main()
{
    double score, total, average, count;
    int decision = 1;
    int i = 0;
    do{
        cout << "Submit a score to average: ";
        cin >> score;
        cout << "Do you have another score to submit? 1 to continue, 0 to exit: ";
        cin >> decision;
        total = score + total;
        i++;
    } while (decision == 1);
    // adding 1 to count to match how many scores are input
    average = total / i;
    cout << "The average score is " << average;
    return 0;
}
*/