#include <iostream>
#include <vector>

using namespace std;

const int MAX_LENGTH = 100001;

int solution(int n, int k, vector<int> &nums) {
    int length = 1;
    int left = 0;
    vector<int> count(MAX_LENGTH, 0);

    for ( int i = 0; i < n; i++ ) {
        count[nums[i]]++; //앞에서부터 숫자 개수 세기

        //해당 숫자가 k개보다 많은 경우
        while ( count[nums[i]] > k ) {
            count[nums[left++]]--; //왼쪽포인터를 증가시키면서 기존의 원소들을 수열에서 제외
        }
        length = max(length, i - left + 1);
    }

    return length;
}

int main() {
    int n, k;

    //입력
    cin >> n >> k;
    vector<int> nums(n, 0);
    for ( int i = 0; i < n; i++ ) {
        cin >> nums[i];
    }

    //연산
    //출력
    cout << solution(n, k, nums);

    return 0;
}