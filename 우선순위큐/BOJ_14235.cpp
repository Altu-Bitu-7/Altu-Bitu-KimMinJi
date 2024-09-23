#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, a;
    int value;
    priority_queue<int> max_heap;

    //입력
    cin >> n;

    while ( n-- ) {
        cin >> a;

        //연산
        //출력
        if ( a == 0 ) {
            if ( max_heap.empty() ) {
                cout << "-1\n";
            }
            else {
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        }
        else {
            for ( int i = 0; i < a; i++ ) {
                cin >> value;
                max_heap.push(value);
            }
        }
    }

    return 0;
}