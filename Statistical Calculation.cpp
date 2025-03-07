/*
* Authors:
    * Author1: Esraa Emary Abd El-Salam, ID: 20230054
    * Author2: Mohammed Atef Abd El-Kader, ID: 20231143
    * Author3: Mariam Badr Yehia, ID: 20230391
    * Author4: John Ayman Demian, ID: 20230109
    * Author5: George Malak Magdy, ID: 20231042

 * Description: This is a program that manages "Iftar Invitations" which makes you add a guest,
             display it and edit the date of invitation.

 * Version: V1.0
*/

//___________________________________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;

//      *************  Statistical Calculation Class *************
template <typename T>
class StatisticalCalculation {

private:
    T* data;         // Dynamically allocated array for storing data
    int size;        // Number of elements in the array

public:
    StatisticalCalculation(int size);
    ~StatisticalCalculation();

    void sort();

    // Statistical Calculation Functions
    T findMedian();
    T findMin();
    T findMax();
    double findMean();
    T findSummation();

    // Utility Functions
    void displayArray();   // Display sorted array
    void inputData();      // Take input dynamically
    void statisticsMenu(); // Menu for statistical operations
};


//     ************* Implement Constructor *************
template <typename T>
StatisticalCalculation<T>::StatisticalCalculation(int size) {
  this->data = new T[size];
}

//      ************* Implement Sort Algorithm  *************
template <typename T>
void StatisticalCalculation<T>::sort() {


}

// ************* Implement Find Median  *************
template <typename T>
T StatisticalCalculation<T>::findMedian() {

}

// ************* Implement Find Min  *************
template <typename T>
T StatisticalCalculation<T>::findMin() {

}

// ************* Implement Find Max  *************
template <typename T>
T StatisticalCalculation<T>::findMax() {

}

// ************* Implement Find Mean  *************
template <typename T>
double StatisticalCalculation<T>::findMean() {

}

// ************* Implement Find Summation  *************
template <typename T>
T StatisticalCalculation<T>::findSummation() {

}

// ************* Implement Display sorted array *************
template <typename T>
void StatisticalCalculation<T>::displayArray() {

}

// ************* Implement Input Data *************
template <typename T>
void StatisticalCalculation<T>::inputData() {

}

// ************* Implement Statistics Menu *************
template <typename T>
void StatisticalCalculation<T>::statisticsMenu() {

}
int main() {
  StatisticalCalculation<int> statistics;
  statistics.inputData();
  statistics.statisticsMenu();
  return 0;
}


