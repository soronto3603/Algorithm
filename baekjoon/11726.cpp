// 2xn 타일링
// https://www.acmicpc.net/problem/11726

#include<iostream>
using namespace std;

unsigned long long int dp[10000];
int N;

int main(){
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=5;
    cin >> N;
    for(int i=4;i<=N;i++){
        dp[i]=(dp[i-2]+dp[i-1]) % 10007;  
    }
    
    cout << dp[N];
    
    return 0;
}