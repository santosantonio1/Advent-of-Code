/*
    Advent of Code 2022 - 1
    @Antônio dos Santos
    11/10/2023
    OBS: inputs files with double enter(\0) at the end
*/
#include <iostream>
using namespace std;
#define ll long long
int main(){
    ll max = 0, mid = 0, low = 0, sum = 0;
    string in;
    while(getline(cin,in)){
        if(in == ""){
            if(sum>=max){
                low = mid;
                mid = max;
                max = sum;
            }
            else if(sum>=mid){
                low = mid;
                mid = sum;
            }
            else if(sum>=low){
                low = sum;
            }
            sum = 0;
        }
        else{
            sum += stoi(in);
        }
    }
    cout << max << endl;
    cout << max+mid+low << endl;
    return 0;
}