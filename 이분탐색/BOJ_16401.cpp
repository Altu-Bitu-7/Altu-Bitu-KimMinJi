#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binarySearch(int n)
{
    int left = 0;
    int right = n - 1;
    while ( left <= right )
    {
        int mid = (left + right) / 2;

        if (  )
        {
            right = mid - 1;
            int height = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
}

int main()
{
    int m, n;
    vector<int> snack_length;

    //입력
    cin >> m >> n;

    for ( int i = 0; i < n; i++ )
    {
        cin >> snack_length[i];
    }

    //연산
    sort(snack_length.begin(), snack_length.end());
    binarySearch(n);

    //출력
    cout << ;

    return 0;
}