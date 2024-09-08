#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int addNumber(string serial_number){
    int sum=0;
    for(int i=0; i < serial_number.size(); i++){
        //숫자들만 더하기
        if(isdigit(serial_number[i])){
            sum+=serial_number[i];
        }
    }
    return sum;
}

bool compare(const string& s1, const string& s2){
    if(s1.size() != s2.size()){
        return s1.size() < s2.size();
    }
    if(addNumber(s1) != addNumber(s2)){
        return addNumber(s1) < addNumber(s2);
    }
    return s1 < s2;
}

int main(){
    int n;
    vector<string> guitar;

    //입력
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> guitar[i];
    }

    //연산
    sort(guitar.begin(), guitar.end(), compare);

    //출력
    for(int i=0; i<n; i++){
        cout << guitar[i] << '\n';
    }

    return 0;
}