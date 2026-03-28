#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> readingFile();

void sortingNums(vector<int> &result);

int main() {
    auto start = chrono::high_resolution_clock::now();

    vector<int> input = readingFile();
    sortingNums(input);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> time_ms = end - start;
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(time_ms);

    chrono::duration<long,  micro> int_us = int_ms;

    cout << time_ms.count() << " ms." << endl;
    cout << int_ms.count() << " ms." << endl;
    cout << int_us.count() << " us." << endl;
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

    sort(result.begin(), result.end());

    // After having sorted the vector, we will loop through it and print the numbers accordingly.
    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << endl;
    }
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

void printArray(vector<int> &arr) {
    for (int &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
