#include <iostream>

using namespace std;

int board[50][50] = { 0, };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 }; // 북 동 남 서

int main() {
    int n, m;
    int r, c, d;

    //입력
    cin >> n >> m;
    cin >> r >> c >> d;

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < m; j++ ) {
            cin >> board[i][j];
        }
    }

    //연산
    int cnt = 0; //로봇청소기가 청소한 칸의 개수
    while ( true ) {
        //아직 청소되지 않은 경우
        if ( board[r][c] == 0 ) {
            cnt++;
            board[r][c] = 2; //청소가 된 칸
        }

        //주변 4칸을 탐색(현재 로보총소기가 바라보는 방향으로부터 90도로 반시계 회전)
        bool dirty = false;
        for ( int i = 0; i < 4; i++ ) {
            int nd = (d - i + 3) % 4;
            int nr = r + dy[nd];
            int nc = c + dx[nd];

            if ( board[nr][nc] == 0 ) {
                dirty = true;
                r = nr;
                c = nc;
                d = nd;
                break;
            }
        }

        //주변 4칸 중 빈칸이 있는 경우
        if ( dirty )
            continue;
        //주변 4칸 중 빈칸이 없는 경우
        else {
            int br = r + dy[(d + 2) % 4];
            int bc = c + dx[(d + 2) % 4];

            //후진을 할 수 없는 경우
            if ( board[br][bc] == 1 )
                break;
            //후진을 할 수 있는 경우
            else {
                r = br;
                c = bc;
            }
        }
    }

    //출력
    cout << cnt;

    return 0;
}