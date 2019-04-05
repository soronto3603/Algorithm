// 다이얼
// https://www.acmicpc.net/problem/5622

#include<iostream>

using namespace std;

int main(){

    string word;
    cin >> word;
    int sum=0;
    int len=word.length();
    for(int i=0;i<len;i++){
        sum+=(word[i]-'A')/3+3;
        // cout << word[i] <<","<<(word[i]-'A')/3+3 << endl;
    }
    cout << sum;
    return 0;
}