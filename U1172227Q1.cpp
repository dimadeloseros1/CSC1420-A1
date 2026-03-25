#include <iostream>
#include <stack>
using namespace std;

void userInput();

int main() {
    userInput();
}

void userInput() {
    string userInput;

    cout << "Please enter an input of your choice: ";
    stack<char> st;
    // stack<string> temp;

    while (getline(cin, userInput)) {
        cout << userInput << endl;
        break;
    }

    for (char c : userInput) {
        st.push(c);
    }

    string reversedStr;

    while (!st.empty()) {
        reversedStr += st.top();
        st.pop();
    }

    cout << reversedStr;
}