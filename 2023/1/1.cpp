#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int part1(){
    string input;
    int sum = 0;
    while(cin >> input){

        string aux = "";

        for(int i=0;i<input.length();i++)
            if(isdigit(input[i])){
                aux += input[i];
                break;
            }

        for(int j=input.length()-1;j>=0;j--)
            if(isdigit(input[j])){
                  aux += input[j];
                break;
            }

            sum += stoi(aux);
    }
    return sum;
}

int part2(){
    
    vector<string> word = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> num = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    string input;
    int sum = 0;
    
    while(cin >> input){

        for(int i=0;i<input.length();i++){
            for(int j=0; j<word.size(); j++){
                if(input.substr(i,word[j].length()) == word[j])
                    input.replace(i,word[j].length()-1, num[j]);
            }
        }
        
        string aux = "";
        
        for(int i=0; i<input.length(); i++){
            if(isdigit(input[i])){
                aux += input[i];
                break;
            }
        }
        
        for(int j=input.length()-1;j>=0;j--){
            if(isdigit(input[j])){
                aux += input[j];
                break;
            }
        }

        sum += stoi(aux);
    }
    return sum;
}

int main(int argc, char *argv[]){

    if(argc <= 1) cout << part1() << endl;
    else cout << part2() << endl;

    return 0;
}