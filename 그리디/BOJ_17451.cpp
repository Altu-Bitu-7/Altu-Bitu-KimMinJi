#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

vector<int> makeMultiple(int n, vector<int> v) {
    while ( n > 1 ) {
        int velocity_later = v[n - 1];
        int velocity = v[n - 2];

        for ( int i = 2;; i++ ) {
            if ( velocity < velocity_later ) {
                velocity = v[n - 2] * i;
            }
            else {
                v[n - 2] = velocity;
                break;
            }
        }
        n--;
    }

    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, velocity;
    int answer;

    //입력
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> velocity;
        v.push_back(velocity);
    }

    //연산
    v = makeMultiple(n, v);
    answer = v[0];

    //출력
    cout << answer << '\n';

    return 0;
}