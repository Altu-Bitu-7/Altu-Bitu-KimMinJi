#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    string text;

    stack<char> s;

    //연산
    //출력
    while (true) {
        getline(cin, text);
        if (text == ".") {
            break;
        }

        bool result = true;

        for (int i = 0; i < text.size(); i++) {
            if ((text[i] == '(') || (text[i] = '[')) {
                s.push(text[i]);
            }

            else if (text[i] == ')') {
                if (s.top() == '(' && !s.empty()) {
                    s.pop();
                }
                else {
                    result = false;
                    break;
                }
            }

            else if (text[i] == ']') {
                if (s.top() == '[' && !s.empty()) {
                    s.pop();
                }
                else {
                    result = false;
                    break;
                }
            }
        }

        if (s.empty() && result) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
    

    return 0;
}