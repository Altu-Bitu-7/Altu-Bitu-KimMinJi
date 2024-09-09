#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> input;

int main() {
    //입력
    int n, k;
    cin >> n >> k;

    vector<input> ipt(k);
    vector<char> result(n, '?'); //?로 초기화
    int index = 0;

    for (int i = 0; i < k; i++) {
        cin >> ipt[i].first >> ipt[i].second;

        //연산
        index = (index + ipt[i].first) % n;
        
        if (index < n) {
            if (result[index] == '?') {
                result[index] = ipt[i].second;
            }
            else if (result[index] != ipt[i].second) {
                cout << '!';
                return 0;
            }
        }
    }

    //중복 확인
    for (int i = 0; i < n; i++) {
        if (result[i] == '?') {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (result[i] == result[j]) {
                cout << '!';
                return 0;
            }
        }
    }

    //출력
    for (int i = 0; i < n; i++) {
        if (index >= 0) {
            cout << result[index--];
        }
        else {
            index += n;
            cout << result[index--];
        }
    }
    return 0;
}