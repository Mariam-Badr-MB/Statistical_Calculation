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

* Version: V1.2
*/
// ********************************************************************************************************

#include <bits/stdc++.h>

using namespace std;


// **************************  Statistical Calculation Class **************************
template<typename T>
class StatisticalCalculation {

    T *data = new T[0];                    // Dynamically allocated array for storing data
    int size;                              // Number of elements in the array

public:
    StatisticalCalculation() = default;
    ~StatisticalCalculation();

    // setter
    void setSize(int size);
    void setData(T *data);

    void sort();

    // Statistical Calculation Functions
    double findMedian();
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
void StatisticalCalculation<T>::setSize(int size) {
    this->size = size;
}

template<typename T>
void StatisticalCalculation<T>::setData(T *data) {
    this->data = data;
}


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
double StatisticalCalculation<T>::findMedian() {
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
    string numOfElements, type_elements;
    bool notInteger;

    cout << "\n1) Integer \n2) Float \n3) Double\n";
    cout << "Please, choose the type of your data: ";
    getline(cin, type_elements);

    // Validate type of data
    while (true) {
        if (type_elements == "1" || type_elements == "2" || type_elements == "3") {
            break; // Valid input
        } else {
            cout << "Invalid Input, Try Again: ";
            getline(cin, type_elements);
        }
    }

    // Validate number of elements
    while (true) {
        notInteger = false;
        cout << "\nPlease, enter the number of elements: ";
        getline(cin, numOfElements);

        // Check if the input is a positive integer
        if (numOfElements.empty()) {
            notInteger = true;
        } else {
            for (int i = 0; i < numOfElements.size(); ++i) {
                if (numOfElements[i] < '0' || numOfElements[i] > '9') {
                    notInteger = true;
                    break;
                }
            }
        }

        if (!notInteger && stoll(numOfElements) > 0) {
            break; // Valid input
        }
        cout << "Invalid Input!\n";
    }

    // Set the size of the data array
    this->size = stoll(numOfElements);

    // Allocate memory for the new data array
    T* newData = new T[this->size];

    // Input data elements
    for (int i = 0; i < this->size; ++i) {
        while (true) {
            try {
                cout << "Please, enter element " << (i + 1) << ": ";
                cin >> newData[i];
                if (cin.fail()) {
                    throw runtime_error("Invalid Input!");
                }
                break; // Valid input
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            }
        }
    }

    // Delete the old data and assign the new data
    delete[] this->data;
    this->data = newData;

    // Clear the input buffer
    cin.ignore();
}

// ************************** Implement Statistics Menu **************************

template<typename T>
void StatisticalCalculation<T>::statisticsMenu() {
    cout << "\nSorted Data:";
    displayArray();
    string choice;

    while (true) {
        cout << "\n1) Find Median \n2) Find Minimum\n3) Find Maximum \n"
                "4) Find Mean\n5) Find Summation \n0) Exit from Menu\nPlease, enter your choice:";
        getline(cin, choice);

        while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "0") {
            cout << "Invalid Input, Try again:";
            getline(cin, choice);
        }


        cout << endl;
        if (choice == "1") cout << "The Value of Median is:" << findMedian() << endl << endl;
        else if (choice == "2") cout << "The Value of min is:" << findMin() << endl << endl;
        else if (choice == "3") cout << "The Value of Max is:" << findMax() << endl << endl;
        else if (choice == "4") cout << "The Value of Mean is:" << findMean() << endl << endl;
        else if (choice == "5") cout << "The Value of Summation is:" << findSummation() << endl << endl;
        else if (choice == "0") return;
    }
}

// ************************** Read File Function **************************



void runFromFile() {
    string fileName, line, type_elements;
    cout << "Please, enter file name:";

    while (true) {
        getline(cin, fileName);

        if (fileName.size() < 5 || fileName.substr(fileName.size() - 4) != ".txt") {
            cout << "\nThe file name should be like this ----> (file name).txt\n";
            cout << "Please, enter a valid file name:";
            continue;
        }

        // Check if file exists.
        ifstream file(fileName);
        if (!file.good()) {
            cout << "\nError in opening the file, Check your File\n";
            cout << "Please, enter a valid file name:";
            continue;
        }
        file.close();
        break;
    }

    ifstream file(fileName);

    while (true) {
        // Read Type of Data
        cout << "\n1) Integer \n2) Float \n3) Double \n";
        cout << "Please, enter type of your data: ";
        getline(file, type_elements);
        cout << type_elements << endl;

        // Read number of elements
        getline(file, line);
        cout << "\nPlease, enter the number of elements: ";
        cout << line << endl;
        int size = stoi(line);

        if (type_elements == "1") {
            StatisticalCalculation<int> stat;
            stat.setSize(size);
            int* data = new int[size];

            // Read data elements
            getline(file, line);
            stringstream ss(line);
            for (int i = 0; i < size; ++i) {
                ss >> data[i];
                cout << "Please, element number " << (i + 1) << " : " << data[i] << endl;
            }

            stat.setData(data);
            cout << endl ;

            // Read operations line
            getline(file, line);
            stringstream opStream(line);
            int num;
            while (opStream >> num) {
                if (num == 1) cout << "The Value of Median is: " << stat.findMedian() << endl ;
                else if (num == 2) cout << "The Value of Min is: " << stat.findMin() << endl ;
                else if (num == 3) cout << "The Value of Max is: " << stat.findMax() << endl ;
                else if (num == 4) cout << "The Value of Mean is: " << stat.findMean() << endl ;
                else if (num == 5) cout << "The Value of Summation is: " << stat.findSummation() << endl ;
                else if (num == 0) {
                    cout << endl << endl;
                    return;
                }
            }

        } else if (type_elements == "2") {
            StatisticalCalculation<float> stat;
            stat.setSize(size);
            float* data = new float[size];

            // Read data elements
            getline(file, line);
            stringstream ss(line);
            for (int i = 0; i < size; ++i) {
                ss >> data[i];
                cout << "Please, element number " << (i + 1) << " : " << data[i] << endl;
            }
            stat.setData(data);
            cout << endl ;

            // Read operations line
            getline(file, line);
            stringstream opStream(line);
            int num;
            while (opStream >> num) {
                if (num == 1) cout << "The Value of Median is: " << stat.findMedian() << endl ;
                else if (num == 2) cout << "The Value of Min is: " << stat.findMin() << endl ;
                else if (num == 3) cout << "The Value of Max is: " << stat.findMax() << endl ;
                else if (num == 4) cout << "The Value of Mean is: " << stat.findMean() << endl ;
                else if (num == 5) cout << "The Value of Summation is: " << stat.findSummation() << endl ;
                else if (num == 0) {
                    cout << endl << endl;
                    return;
                }
            }

        } else if (type_elements == "3") {
            StatisticalCalculation<double> stat;
            stat.setSize(size);
            double* data = new double[size];

            // Read data elements
            getline(file, line);
            stringstream ss(line);
            for (int i = 0; i < size; ++i) {
                ss >> data[i];
                cout << "Please, element number " << (i + 1) << " : " << data[i] << endl;
            }
            stat.setData(data);
            cout << endl ;

            // Read operations line
            getline(file, line);
            stringstream opStream(line);
            int num;
            while (opStream >> num) {
                if (num == 1) cout << "The Value of Median is: " << stat.findMedian() << endl ;
                else if (num == 2) cout << "The Value of Min is: " << stat.findMin() << endl ;
                else if (num == 3) cout << "The Value of Max is: " << stat.findMax() << endl ;
                else if (num == 4) cout << "The Value of Mean is: " << stat.findMean() << endl ;
                else if (num == 5) cout << "The Value of Summation is: " << stat.findSummation() << endl ;
                else if (num == 0) {
                    cout << endl << endl;
                    return;
                }
            }
        }
    }
}


// ************************** Main Function **************************

int main() {
    while (true) {
        string choice;
        StatisticalCalculation<double> statistics;

        while (true) {
            cout << "\n******************* WELCOME TO OUR STATISTICAL CALCULATION *******************" << endl << endl;
            cout << "1) Statistical Calculation" << endl;
            cout << "2) Exit " << endl;
            cout << "Please, enter your choice:";
            getline(cin, choice);

            if (choice == "1" || choice == "2") break;
            cout << "Invalid choice. Please, Try again." << endl << endl;
        }

        // Exit the system.
        if (choice == "2") break;

        if (choice == "1") {
            while (true) {
                cout << "\n1) Run From Terminal" << endl;
                cout << "2) Run From File" << endl;
                cout << "3) Exit" << endl;
                cout << "Please, enter your choice:";
                getline(cin, choice);

                if (choice == "1" || choice == "2" || choice == "3") break;
                cout << "Invalid choice. Please, Try again." << endl << endl;
            }

            if (choice == "1") {
                statistics.inputData();
                statistics.statisticsMenu();
            } else if (choice == "2") {
                runFromFile();
            }
        }
    }

    cout << "\n\n**************** Thanks for using our Statistical Calculation ****************" << endl << endl;
    exit(0);
}
