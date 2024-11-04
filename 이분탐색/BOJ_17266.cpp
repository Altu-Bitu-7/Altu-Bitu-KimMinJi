#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> location;

bool checkShineAll(int n, int m, int height, vector<int> location)
{
    for ( int i = 0; i < m; i++ )
    {
        //첫번째 가로등의 위치와 높이 비교
        if ( i == 0 )
        {
            if ( location[i] > height )
                return false;
        }
        //두 가로등의 간격과 높이 비교
        if ( location[i] - location[i - 1] > 2 * height )
            return false;
    }

    //굴다리의 길이 - 마지막 가로등의 위치
    if ( n - location[m - 1] > height )
        return false;

    return true;
}

void binarySearch(int left, int right, int height, vector<int> location)
{
    while ( left <= right )
    {
        int mid = (left + right) / 2;
        
        if ( checkShineAll(n, m, height, location) )
        {
            right = mid - 1;
            height = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
}

int main()
{
   int height;

   //입력
   cin >> n;
   cin >> m;

   for ( int i = 0; i < m; i++ )
   {
      cin >> location[i];
   }

   //연산
    sort(location.begin(), location.end());
    binarySearch(0, n - 1, height, location);

   //출력
    cout << height;

   return 0;
}