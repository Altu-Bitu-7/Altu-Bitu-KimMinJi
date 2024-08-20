#include <iostream>
#include <vector>

using namespace std;

int main(){
    int w0, i0, t;
    int d, i, a;
    int xpredicted_weight, xpredicted_meta;
    int predicted_weight, predicted_meta;

    //입력
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    //연산
    int e = i0+a;

    xpredicted_weight=w0;
    xpredicted_meta=i0;
    for(int j=0; j<t; j++){
        xpredicted_weight+=(i-e);
        if(xpredicted_weight<=0 || xpredicted_meta<=0){
            int count=j;
            break;
        }
    }
    
    predicted_weight=w0;
    predicted_meta=i0;
    for(int k=0; k<t; k++){
        predicted_weight+=(i-e);
        int absolute = abs(i-e);
        if(absolute > t){
            predicted_meta+=((i-e)/2);
        }
        e=predicted_meta+a;

        if(predicted_weight<=0 || predicted_meta<=0){
            break;
        }
    }

    int a0=0;
    int final_weight = w0 + (i0-(predicted_meta+a0))/2;
    string msg;
    if(final_weight>w0){
        msg="YOYO";
    }
    else{
        msg="NO";
    }

    //출력
    if(xpredicted_weight<=0 || xpredicted_meta<=0){
        cout << "Danger Diet" << '\n';
    }
    else{
        cout << xpredicted_weight << xpredicted_meta << '\n';
    }
    if(predicted_weight<=0 || predicted_meta<=0){
        cout << "Danger Diet";
    }
    else{
        cout << predicted_weight << predicted_meta << msg;
    }

    return 0;
}