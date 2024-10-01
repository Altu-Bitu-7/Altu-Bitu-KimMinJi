#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> li; //톱니바퀴의 극 상태를 저장
vector<pair<int, int> > stack; //회전 정보를 저장
vector<int> visited; //톱니바퀴의 회전여부 확인했는지 (0: 안했음, 1: 했음)

void check_rotation(int current_num, int current_dir) {
    //왼쪽으로 확인
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0) {
        //나의 6번톱니와 내 왼쪽바퀴의 2번톱니가 같은지 확인
        if (li[current_num][6] != li[current_num - 1][2]) { // 맞닿아 있는 면이 서로 다른 극인지 체크
            //왼쪽톱니 회전
            stack.push_back(make_pair(current_num - 1, current_dir * -1));
            visited[current_num - 1] = 1;
            check_rotation(current_num - 1, current_dir * -1);
        }
    }
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0) {
        //나의 2번톱니와 내 오른쪽바퀴의 6번톱니가 같은지 확인
        if (li[current_num][2] != li[current_num + 1][6]) { // 맞닿아 있는 면이 서로 다른 극인지 체크
            //오른쪽톱니 회전
            stack.push_back(make_pair(current_num + 1, current_dir * -1));
            visited[current_num + 1] = 1;
            check_rotation(current_num + 1, current_dir * -1);
        }
    }
}

int main() {
    int t;
    int k;

    cin >> t; //톱니바퀴의 개수 T 입력

    li.resize(t); //톱니바퀴 개수만큼 resize
    for (int i = 0; i < t; ++i)
        cin >> li[i]; //톱니바퀴 상태 입력

    cin >> k; // 회전 횟수 K 입력
    for (int i = 0; i < k; ++i) { //k번 돌면서 회전할 수 있는지에 대해 체크
        int num, direction;
        cin >> num >> direction; //방향 입력 (1이면 시계 방항, -1이면 반시계 방향)
        stack.clear();
        stack.push_back(make_pair(num - 1, direction));
        visited.assign(t, 0); //t개만큼 0을 초기화
        visited[num - 1] = 1; //타겟 톱니바퀴 확인여부 표시
        check_rotation(num - 1, direction); //다른 톱니바퀴들의 회전 여부 확인

        //stack에 회전 정보가 다 들어있게 됨
        while (!stack.empty()) {
            pair<int, int> top = stack.back();
            stack.pop_back();
            int tmp_num = top.first; //돌려야 할 톱니바퀴의 인덱스
            int tmp_dir = top.second; //회전 방향
            //시계방향으로 회전
            if (tmp_dir == 1) {
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
            }
            //반시계방향으로 돌리기
            else {
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < t; ++i) {
        if (li[i][0] == '1') {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}