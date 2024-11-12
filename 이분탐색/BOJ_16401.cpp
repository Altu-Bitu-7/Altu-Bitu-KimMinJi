#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//가능한 과자 길이 중 최대값을 찾는다
bool canShare(int max_length, int m, vector<int>& snack_length)
{
    int count = 0;

    for ( int i = 0; i < snack_length.size(); i++ )
    {
        //각 과자에서 max_length 길이로 몇 개를 만들 수 있는지 계산
        count += snack_length[i] / max_length;
    }

    //나눠 준 과자의 수가 m 이상이면 가능
    return count >= m;
}

int binarySearch(int n, int m, vector<int>& snack_length)
{
    int left = 1;
    int right = snack_length[n - 1];
    int result = 0;

    while ( left <= right )
    {
        int mid = (left + right) / 2;
        
        //나눠 줄 수 있다면
        if ( canShare(mid, m, snack_length) )
        {
            //일단 기록하고 더 긴 길이 있는지 확인
            result = mid;
            left = mid + 1;
        }
        //나눠 줄 수 없다면
        else
            right = mid - 1; //길이 줄여서 다시 시도
    }

    return result;
}

int main()
{
    int m, n;

    //입력
    cin >> m >> n;

    vector<int> snack_length(n);
    for ( int i = 0; i < n; i++ )
    {
        cin >> snack_length[i];
    }

    //연산
    sort(snack_length.begin(), snack_length.end()); //정렬
    int result = binarySearch(n, m, snack_length);

    //출력
    cout << result << '\n';

    return 0;
}