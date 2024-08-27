#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    //입력
    string a, b;
    cin >> a >> b;

    stack<char> s;

    //연산
    int a_size = a.size();
    int b_size = b.size();
    int digit_sum;
    int up = 0; //올림수
    int save_number;
    char save_number_char;

    while (a_size > 0 || b_size > 0) {
        int a_digit = 0; //첫번째 수 자리수
        if (a_size > 0) {
            a_digit = a[--a_size] - '0'; //문자열을 숫자로 변경
        }
        int b_digit = 0; //두번째 수 자리수
        if (b_size > 0) {
            b_digit = b[--b_size] - '0';
        }

        digit_sum = a_digit + b_digit + up; //자리수끼리 합
        //올림수 변경
        if (digit_sum >= 10) {
            up = 1;
            save_number = digit_sum - 10;
        }
        else {
            up = 0;
            save_number = digit_sum;
        }
        save_number_char = save_number + '0'; //더한 값을 문자로 변경
        s.push(save_number_char); //출력할 값을 스택에 저장
    }

    //올림수가 남아있는 경우
    if (up > 0) {
        save_number_char = up + '0';
        s.push(save_number_char);
    }

    //출력
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}