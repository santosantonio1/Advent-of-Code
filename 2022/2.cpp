/*
    Advent of Code 2022 - 2.1
    @Antonio dos Santos
    11/10/2023
*/
#include <iostream>
using namespace std;
//2.1
int part1(char p1, char p2){
    char player1[3] = {'A', 'B', 'C'};
    char player2[3] = {'X', 'Y', 'Z'};
    int i,j;
    for(i=0;i<3;i++) if(player1[i] == p1) break;
    for(j=0;j<3;j++) if(player2[j] == p2) break;
    
    if(i==j) return 3+j+1;       // draw
    if(j==(i+1)%3) return 6+j+1; // win 
    return j+1;                  // lose
}
//2.2
int part2(char p1, char p2){
    char player1[3] = {'A', 'B', 'C'};  
    int i,j;
    for(i=0;i<3;i++) if(player1[i]==p1) break;
    j = (i+2)%3;
    if(p2 == 'X') return j+1;   //lose
    if(p2 == 'Y') return 3+i+1; //draw
    j = (i+1)%3;
    return 6+j+1;               //win
}

int main(){
    int score = 0;
    char p1, p2;
    while(cin >> p1 >> p2){
        score += part2(p1,p2);
    }
    cout << score << endl;
    return 0;
}