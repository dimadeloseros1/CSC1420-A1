#include <iostream>
#include <stack>
using namespace std;

string reverseInput(const string &userInput);
string applyConstraints(const string &input);

int main() {
    string input;
    cout << "Please enter an input of your choice: ";

    getline(cin, input);

    string reversed = reverseInput(input);
    string result = applyConstraints(reversed);

    cout << "Original: " << input << endl;
    cout << "Reversed: " << result << endl;
}

string reverseInput(const string &userInput) {
    string reversedStr;
    stack<char> st;

    for (int i = 0; i < userInput.length(); i++) {
        st.push(userInput.at(i));
    }

    while (!st.empty()) {
        reversedStr += st.top();
        st.pop();
    }

    return reversedStr;
}

string applyConstraints(const string &input) {
    string result;
    for (int i = 0; i < input.length(); i++) {
        if (input.at(i) == ',' || input.at(i) == '.') {
            continue;
        }
        else {
            result += input.at(i);
        }
    }
    return result;
}