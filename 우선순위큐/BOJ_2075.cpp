#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, value;
    priority_queue<int, vector<int>, greater<int>> heap;

    //입력
    cin >> n;

    //연산
    for ( int i = 0; i < n * n; i++ ) {
        cin >> value;
        heap.push(value);

        if ( heap.size() > n ) {
            heap.pop();
        }
    }

    //출력
    cout << heap.top() << '\n';

    return 0;
}