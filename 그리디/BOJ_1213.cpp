#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int ALPHABET_NUM = 26;
int alphabet[ALPHABET_NUM];
char palindrome_name[50];

void solution(string original_name, int odd_count) {
    int size = original_name.size();
    int idx_front = 0;
    int idx_back = size - 1;

    //이름의 글자 중 홀수 개인 글자가 1개 이상이면 팰린드롬 불가능
    if ( odd_count > 1 ) {
        cout << "I'm Sorry Hansoo" << '\n';
        return;
    }
    else {
        for ( int i = 0; i < ALPHABET_NUM; i++ ) {
            //존재하는 알파벳에 대하여 팰린드롬 만들기 -> 앞뒤로 동시에 만들기
            while ( alphabet[i] > 1 ) {
                palindrome_name[idx_front++] = i + 'A';
                palindrome_name[idx_back--] = i + 'A';
                alphabet[i] -= 2;
            }
        }

        //출력
        for ( int i = 0; i < size; i++ ) {
            cout << palindrome_name[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string original_name;
    int odd_count = 0;

    //입력
    cin >> original_name;

    //연산
    int size = original_name.size();
    for ( int i = 0; i < size; i++ ) {
        alphabet[original_name[i] - 'A']++;
    }
    for ( int i = 0; i < ALPHABET_NUM; i++ ) {
        //알파벳이 홀수 개인 경우
        if ( alphabet[i] % 2 == 1 ) {
            odd_count++;
            palindrome_name[size / 2] = i + 'A'; //홀수 개인 알파벳을 중간에 놓기
            alphabet[i + 'A']--;
        }
    }

    //출력
    solution(original_name, odd_count);

    return 0;
}