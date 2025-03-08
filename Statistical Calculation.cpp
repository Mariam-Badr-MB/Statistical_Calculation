/*
* Authors:
    * Author1: Esraa Emary Abd El-Salam              ID: 20230054
    * Author2: Mohammed Atef Abd El-Kader            ID: 20231143
    * Author3: Mariam Badr Yehia                     ID: 20230391
    * Author4: John Ayman Demian                     ID: 20230109
    * Author5: George Malak Magdy                    ID: 20231042

* Description:
    This program implements a generic Statistical Calculation class using templates.
    The class provides various statistical operations on a dynamically allocated array of data,
    including sorting, finding the median, minimum, maximum, mean, and summation.
    It also includes utility functions for displaying the sorted data, taking user input dynamically,
    and providing a menu for statistical operations.

* Version: V1.0
*/
// ********************************************************************************************************

#include <bits/stdc++.h>

using namespace std;

// **************************  Statistical Calculation Class **************************
template<typename T>
class StatisticalCalculation {
private:
    T *data = new T[0];                    // Dynamically allocated array for storing data
    int size;                              // Number of elements in the array
public:
    StatisticalCalculation() = default;
//    ~StatisticalCalculation();

    void sort();

    // Statistical Calculation Functions
    T findMedian();

    T findMin();

    T findMax();

    double findMean();

    T findSummation();

    // Utility Functions
    void displayArray();            // Display sorted array
    void inputData();               // Take input dynamically
    void statisticsMenu();          // Menu for statistical operations
};

// ************************** Implement Sort Algorithm  **************************
template<typename T>
void StatisticalCalculation<T>::sort() {


}

// ************************** Implement Find Median  **************************
template<typename T>
T StatisticalCalculation<T>::findMedian() {

}

// ************************** Implement Find Min  **************************
template<typename T>
T StatisticalCalculation<T>::findMin() {

}

// ************************** Implement Find Max  **************************
template<typename T>
T StatisticalCalculation<T>::findMax() {

}

// ************************** Implement Find Mean  **************************
template<typename T>
double StatisticalCalculation<T>::findMean() {

}

// ************************** Implement Find Summation  **************************
template<typename T>
T StatisticalCalculation<T>::findSummation() {

}

// ************************** Implement Display sorted array **************************
template<typename T>
void StatisticalCalculation<T>::displayArray() {
    for (int i = 0; i < this->size; ++i) {
        cout << data[i] << " ";
    }
}

// ************************** Implement Input Data **************************
template<typename T>
void StatisticalCalculation<T>::inputData() {
    string numOfElements;
    bool notNum;
    T value;

    while (true) {
        notNum = false;
        cout << "Enter the number of elements:";
        getline(cin, numOfElements);
        for (int i = 0; i < numOfElements.size(); ++i) {
            if (numOfElements[i] < '0'|| numOfElements[i]>'9') {
                notNum = true;
                break;
            }
        }
        if (notNum || stoll(numOfElements) == 0) cout << "Invalid Input!\n";
        else break;
    }

    this->size = stoll(numOfElements);
    auto *newData = new T[this->size];

    for (int i = 1; i <= this->size; ++i) {
        while (true) {
            try {
                cout << "Enter element " << i << ":";
                cin>>value;
                if (cin.fail()) throw runtime_error("Invalid Input!");
                break;
            }
            catch (const runtime_error &e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore();
            }
        }
        newData[i - 1] = value;
    }

    // Delete the old data and assign a new data.
    delete[] this->data;
    this->data = newData;
    cin.ignore();
}

// ************************** Implement Statistics Menu **************************
template<typename T>
void StatisticalCalculation<T>::statisticsMenu() {
    string choice;

    cout << "\nSelect a statistical calculation:\n1. Find Median\n2. Find Minimum\n3. Find Maximum\n"
            "4. Find Mean\n5. Find Summation\nEnter your choice (1-5):";
    getline(cin, choice);
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
        cout << "Invalid Input!\n";
        cout << "\nSelect a statistical calculation:\n1. Find Median\n2. Find Minimum\n3. Find Maximum\n"
                "4. Find Mean\n5. Find Summation\nEnter your choice (1-5):";
        getline(cin, choice);
    }

    if (choice == "1") findMedian();
    else if (choice == "2") findMin();
    else if (choice == "3") findMax();
    else if (choice == "4") findMean();
    else if (choice == "5") findSummation();
}

// ************************** Main Function **************************
int main() {
    StatisticalCalculation<string> statistics;
    statistics.inputData();
    statistics.statisticsMenu();
    return 0;
}


