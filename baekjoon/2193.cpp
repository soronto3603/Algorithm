#include<iostream>

using namespace std;

unsigned long dp[10000]={0,};

int N;

int main(){
    dp[0]=1;
    dp[1]=1;
    cin>>N;
    if(N>=2){
        for(int i=2;i<N;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
    }
    cout<<dp[N-1];
}