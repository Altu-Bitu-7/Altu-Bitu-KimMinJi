#include <iostream>

using namespace std;

pair<string, int> input;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int m;
    cin >> m;

    //연산
    int s = 0;
    while (m--) {
        cin >> input.first;
        if (input.first == "add") {
            cin >> input.second;
            s = s | (1 << input.second);
        }
        else if (input.first == "remove") {
            cin >> input.second;
            s = s & ~(1 << input.second);
        }
        //출력
        else if (input.first == "check") {
            cin >> input.second;
            if (s & (1 << input.second)) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (input.first == "toggle") {
            cin >> input.second;
            if (s & (1 << input.second)) {
                s = s & ~(1 << input.second);
            }
            else {
                s = s | (1 << input.second);
            }
        }
        else if (input.first == "all") {
            s = (1 << 21) - 1;
        }
        else if (input.first == "empty") {
            s = 0;
        }
    }
    
    return 0;
}