#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
int compare(int n,  map<string, bool>& map1, string text){
    int count=0;

    for(int i=0; i<n; i++){
        if(map1[text]==true){
            count++;
        }
    }
    return count;
}
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    int count=0;
    string text;
    map<string, bool> map1; 

    //입력
    cin >> n >> m;

    //연산
    for(int i=0; i<n; i++){
        cin >> text;
        map1[text]=i;
        for(int j=0; j<m; j++){
            cin >> text;
            if(map1[text]==true){
                count++;
            }
        }
    }
    
    //출력
    cout << count << '\n';

    return 0;
}