#include <iostream>
using namespace std;
int main(){
    int a,b,c,d , sum = 0;
    char comma;
    //part 2
    while(cin >> a){
        cin >> comma >> b >> comma >> c >> comma >> d;
        if(b<c || d<a) continue;
        else sum++;
    }
    cout << sum << endl;
    return 0;
    //part 1
    while(cin >> a){
        cin >> comma >> b >> comma >> c >> comma >> d;
        if(a - c <= 0 && d - b <= 0 && c<=b && d>=a) sum++;
        else if(c - a <= 0 && b - d <= 0 && a<=d && b>=c) sum++;
    }
    cout <<  sum << endl;
    return 0;
}