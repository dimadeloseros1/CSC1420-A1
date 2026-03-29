#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;


vector<int> readingFile();
void sortingNums(vector<int> &input);
void selectionSort(vector<int> &arr);

int main() {
    vector<int> input = readingFile();
    sortingNums(input);
    selectionSort(input);
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

void sortingNums(vector<int> &input) {
    /*
     * Inbuilt sort function that sorts the data according to which data structure we are using.
     * Most of the time the "sort" function will use the C++ inbuilt sorting algorithm called "introsort" to sort the data that we are working with
     */
    cout << "| ***SORT*** |" << endl;
    double time = 0;
    for (int k = 1; k <= 10; k++) {
        // IMPORTANT. The line below makes a copy of the original vector
        // If we just use the original parameter, we would just be looping from the second iteration and on an "already sorted" vector
        vector<int> result = input;
        auto start = chrono::high_resolution_clock::now();
        sort(result.begin(), result.end());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> time_ms = end - start;

        time += time_ms.count();
        cout << k << " iteration: " << time_ms.count() << " ms" << endl;
    }

    cout << "Average Sort time: " << time / 10 << " ms" << endl << endl;
}

void selectionSort(vector<int> &arr) {
    cout << "| ***SELECTION SORT*** |" << endl;
    double time = 0;
    // This specific loop will loop through the entire *selection sort* function 10 times as per the exercise requirement
    for (int k = 1; k <= 10; k++) {
        // IMPORTANT. The line below makes a copy of the original vector
        // If we just use the original parameter, we would just be looping from the second iteration and on an "already sorted" vector
        vector<int> copy = arr;
        auto start = chrono::high_resolution_clock::now();
        int n = copy.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (copy[j] < copy[min_idx]) {
                    min_idx = j;
                }
            }
            swap(copy[i], copy[min_idx]);
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> time_ms = end - start;

        time += time_ms.count();
        cout << k << " iteration: " << time_ms.count() << " ms" << endl;
    }

    cout << "Average Selection Sort time: " << time / 10 << " ms" << endl;
}
