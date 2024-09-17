#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n;
    cin >> n;

    //연산
    int j = 0;
    for (int i = 666;; i++) {
        int temp = i;
        while (temp >= 666) {
            if (temp % 1000 == 666) {
                j++;
                break;
            }
            temp /= 10;
        }

        //출력
        if (n == j) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}