#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


vector<int> readingFile();
void sortingNums(vector<int> &result);
void selectionSort(vector<int> &arr);
void printArr(vector<int> &arr);
void sortingNumsTwo(vector<int> input);

int main() {
    vector<int> input = readingFile();
    // sortingNums(input);

    // selectionSort(input);
    // printArr(input);
    sortingNumsTwo(input);
}

vector<int> readingFile() {
    ifstream inputFile("RF1.txt");
    vector<int> result;
    int num;

    // This section of the code reads the text file and pushes the numbers inside the vector data structure
    while (inputFile >> num) {
        result.push_back(num);
    }

    inputFile.close();
    return result;
}

void sortingNums(vector<int> &result) {
    /*
     * Inbuilt sort function that sorts the data according to which data structure we are using.
     * Most of the time the "sort" function will use the C++ inbuilt sorting algorithm called "introsort" to sort the data that we are working with
     */
    auto start = chrono::high_resolution_clock::now();

    sort(result.begin(), result.end());

    // After having sorted the vector, we will loop through it and print the numbers accordingly.
    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> time_ms = end - start;
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(time_ms);

    chrono::duration<long, micro> int_us = int_ms;

    cout << time_ms.count() << " Sort ms." << endl;
    cout << int_ms.count() << " Sort ms." << endl;
    cout << int_us.count() << " Sort us." << endl;
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void printArr(vector<int> &arr) {
    auto start = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 10; i++) {
        for (int &val: arr) {
            cout << val << " ";
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> time_ms = end - start;
        auto int_ms = chrono::duration_cast<chrono::milliseconds>(time_ms);
        chrono::duration<long, micro> int_us = int_ms;

        cout << endl;
        cout << i << ": " << time_ms.count() << " Selection Sort ms" << endl;
        cout << i << ": " << int_ms.count() << " Selection Sort ms" << endl;
        cout << i << ": " << int_us.count() << " Selection Sort us" << endl;
    }
}


void sortingNumsTwo(vector<int> input) {
    double totalTime = 0.0;

    for (int i = 1; i <= 10; i++) {
        vector<int> arr = input;

        auto start = chrono::high_resolution_clock::now();
        sort(arr.begin(), arr.end());
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> time_ms = end - start;
        totalTime += time_ms.count();

        cout << "Run" << i << ": " << time_ms.count() << " ms" << endl;
    }

    cout << "Average Sort time: " << (totalTime / 10.0) << " ms" << endl;
}