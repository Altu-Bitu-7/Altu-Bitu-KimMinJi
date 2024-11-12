#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int selectSushi(int n, int k, int c, vector<int> &sushi) {
    int check[3001];
    int max_sushi = 0;

    for ( int i = 0; i < n; i++ ) {
        int flag = 0; //중복된 스시 확인 -> 중복된 것이 있으면 1
        int coupon = 1; //쿠폰 스시 확인 -> 있으면 0
        for ( int j = i; j < i + k; j++ ) {
            if ( check[sushi[j % n]] == 1 ) //중복된 스시가 있는 경우
                flag++;
            else //안 먹어본 스시인 경우
                check[sushi[j % n]] = 1;
            if ( check[sushi[j % n]] == c ) //쿠폰 스시가 있는 경우
                coupon = 0;
        }
        max_sushi = max(max_sushi, k - flag + coupon);
        memset(check, 0, sizeof(check)); //체크 초기화
    }
    return max_sushi;
}

int main() {
    int n, d, k, c;

    //입력
    cin >> n >> d >> k >> c;
    vector<int> sushi(n, 0);
    for ( int i = 0; i < n; i++ ) {
        cin >> sushi[i];
    }

    //연산
    int ans = selectSushi(n, k, c, sushi);

    //출력
    cout << ans;

    return 0;
}