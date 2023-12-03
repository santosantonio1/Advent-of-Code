/*
    Advent of Code 2022 - Day 5
    @Antonio dos Santos
    To print stacks, define PRINT
    Part1 -> send nothing to argc, argv
    Part2 -> send any value to argc, argv
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// typedef vector<vector<char>> matrix;
vector<stack<char>> getInput(){
    vector<string> input;
    string line;
    int x,y,z; x=y=z=0;
    while(getline(cin,line)){
        if(line=="") break;
        input.push_back(line);
        y++;
    }
    z = input[0].length();
    y--;
    input.pop_back();
    x = (z+1)/4;

    vector<stack<char>> s(x);
    for(int i=0,j=1;i<x;i++,j+=4){
        for(int k=y-1;k>=0;k--){
            char c = input[k][j];
            if(c!=' ') s[i].push(c);
        }
    }
    return s;
}
void print(vector<stack<char>> s){
    for(int i=0;i<s.size();i++){
        while(!s[i].empty()){
            cout << s[i].top() << " ";
            s[i].pop();
        }
        cout << endl;
    }
}
void printLegal(vector<stack<char>> s){
    int x,y; x=0,y=s.size();
    for(int i=0;i<y;i++) if(s[i].size()>x) x=s[i].size();
    //INV STACKS
    vector<stack<char>> crates(y);
    for(int i=0;i<y;i++){
        while(!s[i].empty()){
            crates[i].push(s[i].top());
            s[i].pop();
        }
    }
    //CREATE STRINGS FOR PRINT
    vector<string> stacks(x);
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(!crates[j].empty()){
                stacks[i] += '[';
                stacks[i] += crates[j].top();
                stacks[i] += "] ";
                crates[j].pop();
            }
            else{
                stacks[i] += "    ";
            }
        }
    }
    //PRINT STAGE
    for(int i=stacks.size()-1;i>=0;i--){
        cout << stacks[i] << endl;
    }
    for(int i=1;i<=y;i++){
        cout << " " << i << "  ";
    }
    cout << endl;
}
void CrateMover9000(vector<stack<char>> s){
    while(1){
        string move,from,to;
        int q,origin,dest;
        if(!(cin>>move)) break;
        cin >> q >> from >> origin >> to >> dest;
        for(int i=0;i<q;i++){
            char c = s[origin-1].top();
            s[origin-1].pop();
            s[dest-1].push(c);
        }
    }
    for(int i=0;i<s.size();i++) cout << s[i].top();
    cout << endl;

    #ifdef PRINT
    // print(s);
    printLegal(s);
    #endif 

    return;
}
void CrateMover9001(vector<stack<char>> s){
    while(1){
        string move,from,to;
        int q,origin,dest;
        if(!(cin>>move)) break;
        cin >> q >> from >> origin >> to >> dest;
        vector<char> crates(q);
        for(int i=0;i<q;i++){
            char c = s[origin-1].top();
            s[origin-1].pop();
            crates.push_back(c);
        }
        for(int i=0;i<q;i++){
            char c = crates.back();
            crates.pop_back();
            s[dest-1].push(c);
        }
        crates.clear();
    }
    for(int i=0;i<s.size();i++) cout << s[i].top();
    cout << endl;

    #ifdef PRINT
    // print(s);
    printLegal(s);
    #endif

    return;
}
int main(int argc, char *argv[]){
    vector<stack<char>> s = getInput();

    if(argc == 1) CrateMover9000(s);
    else CrateMover9001(s);
    
    return 0;
}