/* Program name: M06_EXTRA.cpp
* Author: Ty Stratton
* Date last updated: 12/02/2024
* Purpose: Grade Analysis
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

void getAverageScore(double scores[][5], int numRows, int colToAnalyze, double& average){
    // add up all values in column
    for(int i = 0; i < numRows; i++){
        average += scores[i][colToAnalyze];
    }
    // divide sum by number of rows
    average/= numRows;
}

void getLowScoreIndex(double scores[][5], int numRows, int colToAnalyze, double& lowScoreIndex){
    // Initialize low score index
    for(int i = 0; i < numRows; i++){
        if (i == 0){
            lowScoreIndex = scores[i][colToAnalyze];
        }
        else{
            if(scores[i][colToAnalyze] < lowScoreIndex){
                lowScoreIndex = scores[i][colToAnalyze];
            }
        }

    }
}

void getHighScoreIndex(double scores[][5], int numRows, int colToAnalyze, double& highScoreIndex){
    // Intialize low score index
    for(int i = 0; i < numRows; i++){
        if (i == 0){
            highScoreIndex = scores[i][colToAnalyze];
        }
        else{
            if(scores[i][colToAnalyze] > highScoreIndex){
                highScoreIndex = scores[i][colToAnalyze];
            }
        }

    }
}

void selectionSort(double scoreColumn[], int numItems){
    // sort 1d array into ascending order
    sort(scoreColumn, scoreColumn + numItems);
}

void getMedianScore(double scores[][5], int numRows, int colToAnalyze, double& median){
    double medianSort[numRows];
    for (int i = 0; i < numRows; i++) {
        medianSort[i] = scores[i][colToAnalyze]; // copy 2d array into 1d array
    }
    selectionSort(medianSort, numRows);
    if (numRows % 2 == 0) { // Even number of rows, averages middle
        median = (medianSort[numRows / 2 - 1] + medianSort[numRows / 2]) / 2;
    } else { // odd number of rows
        median = medianSort[numRows / 2];
    }
}

int main(){
    int numRows = 0;
    double scores[20][5];
    double test1, test2, test3, test4, test5;
    double average, lowScoreIndex, highScoreIndex, median;
    ifstream inData("grades.txt");
    while (inData >> test1 >> test2 >> test3 >> test4 >> test5) {
        // Calculate score from points dictionary
        scores[numRows][0] = test1; 
        scores[numRows][1] = test2; 
        scores[numRows][2] = test3; 
        scores[numRows][3] = test4; 
        scores[numRows][4] = test5; 
        numRows++;
    }
    cout << "Grade Statistics:" << endl;
    for (int i = 0; i < 5; i++){
        average = 0;
        highScoreIndex = 0;
        lowScoreIndex = 0;
        // Use functions to update variables
        getLowScoreIndex(scores, numRows, i, lowScoreIndex);
        getHighScoreIndex(scores, numRows, i, highScoreIndex);
        getAverageScore(scores, numRows, i, average);
        getMedianScore(scores, numRows, i, median);
        
        // Outputs
        cout << "Test " << i + 1 << endl;
        cout << "\tHighest Score: " << fixed << setprecision(2) << highScoreIndex << endl;
        cout << "\tLowest Score: " << fixed << setprecision(2) << lowScoreIndex << endl;
        cout << "\tAverage Score: " << fixed << setprecision(2) << average << endl;
        cout << "\tMedian Score: " << fixed << setprecision(2) << median << endl;
    }
    
    return 0;
}
