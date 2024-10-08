#include <iostream>

using namespace std;

int n, a, b, m;
int graph[100][100] = { 0, };
bool visited[100] = { false, };
int ans = -1;

void dfs(int v, int num) {
    visited[v] = true; //현재 노드 v
    if ( v == b ) {
        ans = num;
        return;
    }

    for ( int i = 1; i <= n; i++ ) {
        if ( graph[v][i] == 1 ) {
            if ( !visited[i] ) {
                dfs(i, num + 1);
            }
        }
    }
}

int main() {
    //입력
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for ( int i = 0; i < m; i++ ) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
    }

    //연산
    dfs(a, 0);

    //출력
    if ( ans == -1 ) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}