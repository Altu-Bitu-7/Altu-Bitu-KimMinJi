#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int target, vector<int> nums)
{
    int left = 0;
    int right = n - 1;

    while ( left <= right )
    {
        int mid = (left + right) / 2;

        if ( nums[mid] == target )
            return 1;
        if ( nums[mid] > target )
            right = mid - 1;
        else
            left = mid + 1;
    }

    return 0;
}

int main()
{
    int n, m, target;
    vector<int> card(n);

    //입력
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cin >> card[i];
    }

    sort(card.begin(), card.end());

    cin >> m;
    while ( m-- )
    {
        cin >> target;
        //연산
        //출력
        cout << binarySearch(n, target, card) << '\n';
    }

    return 0;
}