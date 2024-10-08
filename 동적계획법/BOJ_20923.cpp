#include <iostream>
#include <deque>
#include <vector>

using namespace std;

//index=0: 도도, index=1: 수연
deque<int> deck[2];
deque<int> ground[2];

//승리한 사람 확인
int winCheck() {
    if ( ground[0].size() && ground[0].front() == 5 ) {
        return 0;
    }
    if ( ground[1].size() && ground[1].front() == 5 ) {
        return 0;
    }
    if ( ground[0].size() && ground[1].size() && ground[0].front() + ground[1].front() == 5 ) {
        return 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    int do_card, su_card;
    int turn = 0;

    //입력
    cin >> n >> m;
    for ( int i = 0; i < n; i++ ) {
        cin >> do_card >> su_card;
        deck[0].push_front(do_card);
        deck[1].push_front(su_card);
    }

    //연산
    for ( int i = 0; i < m; i++ ) {
        //그라운드에 자신의 덱에 있는 카드 내려놓기
        ground[turn].push_front(deck[turn].front());
        deck[turn].pop_front();

        //덱이 비어 있는 경우
        if ( deck[turn].empty() ) {
            cout << (turn ? "do" : "su") << '\n';
            return 0;
        }

        //종을 친 경우, 그라운드에 있는 카드 더미를 자신의 덱 아래로 합치기
        int w = winCheck();
        if ( w != -1 ) {
            int l = 1 - w;
            while ( ground[l].size() ) {
                deck[w].push_back(ground[l].back());
                ground[l].pop_back();
            }
            while ( ground[w].size() ) {
                deck[w].push_back(ground[w].back());
                ground[w].pop_back();
            }
        }

        turn = 1 - turn;
    }

    //출력
    if ( deck[0].size() > deck[1].size() ) {
        cout << "do" << '\n';
    }
    else if ( deck[0].size() < deck[1].size() ) {
        cout << "su" << '\n';
    }
    else {
        cout << "dosu" << '\n';
    }

    return 0;
}