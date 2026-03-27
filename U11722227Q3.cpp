#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void readingFile();

int main() {
    readingFile();
}

void readingFile() {
    // string inputFile;
    fstream inputFile("RF1.txt");
    string readFile;
    while (getline(inputFile, readFile)) {
        cout << readFile << endl;
    }

    inputFile.close();
}

