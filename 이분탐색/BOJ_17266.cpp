#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

bool checkShineAll(int n, int m, int height, vector<int> location)
{
    //첫번째 가로등의 위치와 높이 비교
    if ( location[0] > height )
        return false;

    for ( int i = 1; i < m; i++ )
    {
        //두 가로등의 간격과 높이 비교
        if ( location[i] - location[i - 1] > 2 * height )
            return false;
    }

    //굴다리의 길이 - 마지막 가로등의 위치
    if ( n - location[m - 1] > height )
        return false;

    return true;
}

void binarySearch(int left, int right, vector<int>& location)
{
    int height = 0;

    while ( left <= right )
    {
        int mid = (left + right) / 2;
        
        if ( checkShineAll(n, m, mid, location) )
        {
            height = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    //출력
    cout << height;
}

int main()
{
    //입력
    cin >> n >> m;
    
    vector<int> location(m);
    for ( int i = 0; i < m; i++ ) {
        cin >> location[i];
    }

    //연산
    sort(location.begin(), location.end());
    binarySearch(0, n, location);

    return 0;
}