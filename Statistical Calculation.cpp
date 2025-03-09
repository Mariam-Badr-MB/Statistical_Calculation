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
    void displayArray();            // Display the sorted array
    void inputData();               // Take input dynamically
    void statisticsMenu();          // Menu for statistical operations
};

// ************************** Implement Sort Algorithm  **************************

template<typename T>
void StatisticalCalculation<T>::sort() {
// Using Bubble Sort Algorithm
    for (int i = 0; i < this->size - 1; ++i) {
        for (int j = 0; j < this->size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// ************************** Implement Find Median  **************************

template<typename T>
T StatisticalCalculation<T>::findMedian() {
    sort();         // Sort the array first to find the median easily.
    displayArray();
    // If the size of the array is even, return the average of the two middle elements.
    if (this->size % 2 == 0) {
        int middleIndex1 = this->size /2;
        int middleIndex2 = (this->size /2) - 1;
        return (data[middleIndex1] + data[middleIndex2]) /2;
    }

    // If the size of the array is odd, return the middle element.
    return data[this->size / 2];
}

// ************************** Implement Find Min  **************************

template<typename T>
T StatisticalCalculation<T>::findMin() {
    sort();
    return this->data[0];
}

// ************************** Implement Find Max  **************************

template<typename T>
T StatisticalCalculation<T>::findMax() {
    sort();
    return this->data[this->size - 1];
}

// ************************** Implement Find Mean  **************************

template<typename T>
double StatisticalCalculation<T>::findMean() {
    double mean = findSummation() /this->size ;
    return  mean;
}

// ************************** Implement Find Summation  **************************

template<typename T>
T StatisticalCalculation<T>::findSummation() {
    T sum = 0;
    for (int i = 0; i < this->size ; ++i) {
        sum += this->data[i];
    }

    return  sum;
}

// ************************** Implement Display sorted array **************************

template<typename T>
void StatisticalCalculation<T>::displayArray() {
    for (int i = 0; i < this->size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// ************************** Implement Input Data **************************

template<typename T>
void StatisticalCalculation<T>::inputData() {
    long long numOfElements;

    while (true) {
        try {
            cout << "Enter the number of elements:";
            cin >> numOfElements;
            if (cin.fail() || numOfElements <= 0) throw runtime_error("Invalid Input!");
            break;
        }
        catch (const runtime_error &e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore();
        }
    }

    this->size = numOfElements;
    auto *newData = new T[this->size];

    for (int i = 1; i <= numOfElements; ++i) {
        while (true) {
            try {
                cout << "Enter element " << i << ":";
                cin >> newData[i - 1];
                if (cin.fail()) throw runtime_error("Invalid Input!");
                break;
            }
            catch (const runtime_error &e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore();
            }
        }
    }

    // Delete the old data and assign new data.
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

    if (choice == "1") cout << "Median: " << findMedian() << endl << endl;
    else if (choice == "2") cout << "Min: " << findMin() << endl << endl;
    else if (choice == "3") cout << "Max: " << findMax() << endl << endl;
    else if (choice == "4") cout << "Mean: " << findMean() << endl << endl;
    else if (choice == "5") cout << "Summation: " << findSummation() << endl << endl;
}

// ************************** Main Function **************************

int main() {
    StatisticalCalculation<double> statistics;
    statistics.inputData();
    statistics.statisticsMenu();
    return 0;
}


