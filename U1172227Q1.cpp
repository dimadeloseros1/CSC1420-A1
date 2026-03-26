#include <iostream>
#include <stack>
using namespace std;

string userInput();
string applyConstraints(string input);

int main() {
    string input = userInput();
    applyConstraints(input);
}

string userInput() {
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

    return reversedStr;
}

string applyConstraints(string input) {
    string result;
    for (int i = 0; i < input.length(); i++) {
        if (input.at(i) == ',' || input.at(i) == '.') {
            continue;
        }
        else {
            result += input.at(i);
        }
    }
    cout << result;
    return result;
}