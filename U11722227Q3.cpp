#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
vector<int> readingFile();
void sortingNums(vector<int>& result);

int main() {
    vector<int> input = readingFile();
    sortingNums(input);
}

vector<int> readingFile() {
    ifstream inputFile("RF1.txt");
    vector<int> result;
    int num;

    while (inputFile >> num) {
        result.push_back(num);
    }

    inputFile.close();
    return result;
}

void sortingNums(vector<int>& result) {
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << endl;
    }
}