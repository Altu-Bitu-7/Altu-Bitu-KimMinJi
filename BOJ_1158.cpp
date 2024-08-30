#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n, k;
    cin >> n >> k;
    
    queue<int> q;

    //연산
    //출력
    cout << '<';
    for(int i=0; i<n; i++){
            q.push(i+1);
        }
    
    while(n--){
        for(int i=0; i<k-1; i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();

        if(q.empty()){
            cout << '>';
        }
        else{
            cout << ", ";
        }
    }

    return 0;
}