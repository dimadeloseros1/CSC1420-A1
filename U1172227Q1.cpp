#include <iostream>
#include <stack>
using namespace std;

void userInput();

int main() {
    userInput();
}

void userInput() {
    string userInput;
    string reversedStr;

    cout << "Please enter an input of your choice: ";
    stack<char> st;

    while (getline(cin, userInput)) {
        cout << userInput << endl;
        break;
    }

    for (int i = 0; i < userInput.length(); i++) {
        st.push(userInput.at(i));
    }

    while (!st.empty()) {
        reversedStr += st.top();
        st.pop();
    }

    cout << reversedStr;
}