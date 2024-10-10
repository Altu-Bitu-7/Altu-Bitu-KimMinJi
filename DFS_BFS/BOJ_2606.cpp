#include <iostream>

using namespace std;

int n, pair_count;
int graph[101][101] = { 0, };
bool visited[101] = { false, };

void dfs(int num) {
    for ( int i = 1; i <= n; i++ ) {
        if ( graph[num][i] == 1 ) {
            if ( !visited[i] ) {
                visited[i] = true;
                dfs(i);
            }
        }
    }
}

int main() {
    int count = 0;

    //입력
    cin >> n >> pair_count;
    for ( int i = 0; i < pair_count; i++ ) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
    }

    //연산
    visited[1] = true;
    dfs(1);
    for ( int i = 2; i <= n; i++ ) {
        if ( visited[i] ) {
            count++;
        }
    }

    //출력
    cout << count << '\n';

    return 0;
}