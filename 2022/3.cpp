#include <iostream>
#include <vector>
using namespace std;
int main(){
    //part 2
    string e1, e2, e3;
    bool STOP = false;
    int SUM = 0;
    while(getline(cin,e1)){
        getline(cin,e2);
        getline(cin,e3);
        STOP = false;
        for(int i=0; i<e1.length(); i++){
            char badge;
            for(int j=0; j<e2.length(); j++){
                if(e1[i] == e2[j]) {
                    badge = e1[i];
                for(int k=0; k<e3.length(); k++){
                        if(badge == e3[k]){
                            if(badge >= 'A' && badge <= 'Z') SUM += badge - 'A' + 27;
                            else if(badge >= 'a' && badge <= 'z') SUM += badge - 'a' + 1;
                            STOP = true;
                            break;
                        }
                    }
                }
                if(STOP) break;
            }
            if(STOP) break;
        }
    }
    cout << SUM << endl;
    return 0;
    //part1
    string s;
    int sum = 0;
    bool stop;
    while(getline(cin,s)){
        stop = false;
        char c1;
        for(int i=0; i<s.length()/2; i++){
            c1 = s[i];
            for(int j=s.length()/2; j<s.length(); j++){
                if (c1 == s[j]){
                    if(c1 >= 'A' && c1<='Z') sum += c1 - 'A' + 27;
                    else if(c1>='a' && c1<='z') sum += c1 - 'a' + 1;
                    stop = true;
                    break;
                }
            }
            if (stop) break;
        }
    }
    cout << sum << endl;
    return 0;
}