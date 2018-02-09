#include<iostream>

using namespace std;

unsigned long dp[1000000]={0,};
int T;
int n;

int main(){
    dp[0]=1;
    dp[1]=2;
    dp[2]=4;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        for(int j=3;j<n;j++){
            dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
        }
        cout<<dp[n-1]<<endl;
    }
}