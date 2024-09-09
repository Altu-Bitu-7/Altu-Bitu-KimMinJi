#include <iostream>
#include <string>

using namespace std;

const int MAX = 8;

void moveLocation(char direction, int move_x, int move_y) {
    switch (direction)
    {
    case 'R':
        move_x++;
        break;
    case 'L':
        move_x--;
        break;
    case 'B':
        move_y--;
        break;
    case 'T':
        move_y++;
        break;
    default:
        break;
    }
}

int main() {
    //입력
    string king_location, stone_location; //초기위치
    int n;
    string move;
    cin >> king_location >> stone_location >> n;

    //연산
    //문자열->숫자 변환
    int king_x = king_location[0] - 'A' + 1;
    int king_y = king_location[1] - '0';
    int stone_x = stone_location[0] - 'A' + 1;
    int stone_y = stone_location[1] - '0';

    for (int i = 0; i < n; i++) {
        cin >> move;
        int move_x = 0, move_y = 0; //움직이는 칸 수
        for (int j = 0; j < move.size(); j++) {
            moveLocation(move[j], move_x, move_y);
        }
        //체스판 밖으로 안 나가는 경우에만 이동
        if ((king_x + move_x <= MAX) && (king_y + move_y <= MAX)) {
            king_x += move_x;
            king_y += move_y;

            king_location[0] = 'A' + (king_x - 1);
            king_location[1] = king_y + '0';

            if (king_location == stone_location) {
                if ((stone_x + move_x <= MAX) && (stone_y + move_y <= MAX)) {
                    stone_x += move_x;
                    stone_y += move_y;

                    stone_location[0] = 'A' + (stone_x - 1);
                    stone_location[1] = stone_y + '0';
                }
            }
        }
    }

    //출력
    cout << king_location << '\n' << stone_location;

    return 0;
}