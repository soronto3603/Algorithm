#include<iostream>

using namespace std;

int dp[1000000]={0,};

int main(){
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=3;
    int N;
    cin>>N;
    int select;
    int a,b,c;
    for(int i=6;i<=N;i++){
        select=0x7fffffff;
        // cout<<"I="<<i<<">>>>";
        if(i%3==0){
            if(dp[i/3]<select){
                select=dp[i/3]+1;
                // cout<<i/3<<":"<<dp[i/3];
            }
        }
        if(i%2==0){
            if(dp[i/2]<select){
                select=dp[i/2]+1;
                // cout<<i/2<<":"<<dp[i/2];
            }
        }
        if(dp[i-1]<select){
            select=dp[i-1]+1;
            // cout<<i-1<<":"<<dp[i-1];
        }
        dp[i]=select;
        // cout<<"::"<<select<<"/"<<dp[i]<<endl;
    }
    // for(int i=0;i<N+1;i++){
    //     cout<<i<<":"<<dp[i]<<endl;
    // }

    cout<<dp[N];
}