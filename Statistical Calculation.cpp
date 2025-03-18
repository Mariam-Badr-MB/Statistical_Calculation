/*
* Authors:
    * Author1: Esraa Emary Abd El-Salam              ID: 20230054
    * Author2: Mohammed Atef Abd El-Kader            ID: 20231143
    * Author3: Mariam Badr Yehia                     ID: 20230391
    * Author4: John Ayman Demian                     ID: 20230109
    * Author5: George Malak Magdy                    ID: 20231042

* Date: 9 / 3 / 2025
* Prof: Dr. Besheer

* Description:
    This program implements a generic Statistical Calculation class using templates.
    The class provides various statistical operations on a dynamically allocated array of data,
    including sorting, finding the median, minimum, maximum, mean, and summation.
    It also includes utility functions for displaying the sorted data, taking user input dynamically,
    and providing a menu for statistical operations.

* Version: V5.0
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
    ~StatisticalCalculation();

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

template<class T>
void merge(T data[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;    // Size of the left subarray.
    int n2 = right - mid;       // Size of the right subarray.

    // Create temp arrays L[] and R[] to store the data.
    T L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = data[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = data[mid + j + 1];
    }

    // Merge the temp arrays back into data[left...right].
    i = j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any.
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any.
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

template<class T>
void mergeSort(T data[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

// ************************** Implement Sort Function  **************************

template<typename T>
void StatisticalCalculation<T>::sort() {
    // Using Merge Sort Algorithm to sort the array.
    mergeSort(data, 0, size - 1);
}

// ************************** Implement Find Median  **************************

template<typename T>
T StatisticalCalculation<T>::findMedian() {
    sort();

    // If the size of the array is even, return the average of the two middle elements.
    if (this->size % 2 == 0) {
        int middleIndex1 = this->size / 2;
        int middleIndex2 = (this->size / 2) - 1;
        return (data[middleIndex1] + data[middleIndex2]) / 2;
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
    return (findSummation() / (double) this->size);
}

// ************************** Implement Find Summation  **************************

template<typename T>
T StatisticalCalculation<T>::findSummation() {
    T sum = 0;
    for (int i = 0; i < this->size; ++i) {
        sum += this->data[i];
    }
    return sum;
}

// ************************** Implement Display sorted array **************************

template<typename T>
void StatisticalCalculation<T>::displayArray() {
    sort();
    for (int i = 0; i < this->size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}
template<typename T>
StatisticalCalculation<T>::~StatisticalCalculation() {
    delete[] data;
}


// ************************** Implement Input Data **************************

template<typename T>
void StatisticalCalculation<T>::inputData() {
    string numOfElements;
    bool notInteger;

    while (true) {
        notInteger = false; cin.ignore();
        cout << "Please, enter the number of elements:";
        getline(cin, numOfElements);
        if (numOfElements.empty()) {
            notInteger = true;
        } else {
            for (int i = 0; i < numOfElements.size(); ++i) {
                if (numOfElements[i] < '0' || numOfElements[i] > '9' || numOfElements == " ") {
                    notInteger = true;
                    break;
                }
            }
        }
        if (!notInteger) {
            if (stoll(numOfElements) > 0) break;
        }
        cout << "Invalid Input!\n";
    }

    this->size = stoll(numOfElements);
    auto *newData = new T[this->size];

    for (int i = 1; i <= this->size; ++i) {
        while (true) {
            try {
                cout << "Please, enter element " << i << ":";
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
    cout << "\nSorted Data: ";
    displayArray();

    string choice;

    cout << "\n1) Find Median.\n2) Find Minimum\n3) Find Maximum.\n"
            "4) Find Mean\n5) Find Summation\nPlease, enter your choice: ";
    getline(cin, choice);

    while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
        cout << "Invalid Input, Try again: ";
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

    while (true) {

        string choice;  StatisticalCalculation<double> statistics;

        cout << "\n **************************** WELCOME TO OUR STATISTICAL CALCULATION ****************************"<< endl << endl;

        cout << "1) Statistical Calculation" << endl ;
        cout << "2) Exit " << endl ;

        cout << "\nPlease, enter your choice : "; cin >> choice;

        while ((choice != "1" && choice != "2")) {
            cout << "Invalid Input!\n";
            cout << "Please, enter valid choice :"; cin >> choice;
        }

        if (choice == "1") {
            statistics.inputData();
            statistics.statisticsMenu();

        }else {
            cout << "\n**************** Thanks for using our statistical calculation ****************" << endl << endl;
            exit(0);
        }

    }
}
