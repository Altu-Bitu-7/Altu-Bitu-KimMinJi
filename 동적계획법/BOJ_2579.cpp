#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<int> score;
    vector<int> dp(n, 0);

    //입력
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> score[i];
    }

    //연산
    if ( n == 1 ) {
        return score[0];
    }

    else if ( n == 2 ) {
        return score[0] + score[1];
    }

    else {
        dp[0] = score[0];
        dp[1] = score[1];
        dp[2] = max(score[0] + score[2], score[1] + score[2]);
        for ( int i = 3; i < n; i++ ) {
            dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
        }
    }
    //출력
    cout << dp[n - 1] << '\n';

    return 0;
}