#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    
    //입력
    cin >> n;
    vector<int> arr(n);
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }

    //연산
    vector<int> ans(n, 1);
    for ( int i = 1; i < n; i++ ) {
        for ( int j = 0; j < i; j++ ) {
            if ( arr[i] > arr[j] ) {
                ans[i] = max(ans[i], ans[j] + 1);
            }
        }
    }

    //출력
    int size = ans.size();
    cout << size << '\n';

    return 0;
}