#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int ALPHABET_NUM = 26;

//단어에 들어있는 각 알파벳의 개수 세기
vector<int> letterCount(string word) {
    vector<int> arr(ALPHABET_NUM, 0);

    for ( int i = 0; i < word.size(); i++ ) {
        arr[word[i] - 'A']++;
    }
    return arr;
}

//첫번째 단어와의 알파벳 등장 횟수 비교
int compareCount(string word, vector<int> first_letter_count) {
    vector<int> word_letter_count(ALPHABET_NUM, 0);
    int difference = 0;
    word_letter_count = letterCount(word);

    for ( int i = 0; i < ALPHABET_NUM; i++ ) {
        difference += abs(first_letter_count[i] - word_letter_count[i]);
    }
    return difference;
}

int main() {
    int n;
    string first_word, word;
    vector<int> first_letter_count(ALPHABET_NUM, 0);
    int count = 0;

    //입력
    cin >> n >> first_word;

    //연산
    first_letter_count = letterCount(first_word);
    for ( int i = 0; i < n - 1; i++ ) {
        cin >> word;
        int difference = compareCount(word, first_letter_count);
        if ( difference == 0 || difference == 1 || difference == 2 && first_word.size() == word.size() ) {
            count++;
        }
    }

    //출력
    cout << count << '\n';

    return 0;
}