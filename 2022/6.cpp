/*
    Advent of Code 2022 - Day 6
    @Antonio dos Santos
*/
#include <iostream>
#include <set>
using namespace std;
string getInput(){
    string s;
    getline(cin,s);
    return s;
}
int CommunicationDevice(string s,int x){
    for(int i=0;i<s.length();i++){
        set<char> sq;
        for(int j=0;j<x;j++) sq.insert(s[i+j]);
        if(sq.size()==x) return i+x;
    }
    return 0;
}
int main(){
    string s = getInput();
    cout << CommunicationDevice(s,4) << endl;  //part1
    cout << CommunicationDevice(s,14) << endl; //part2
    return 0;
}