#include<iostream>

using namespace std;

unsigned long dp[100000];
int P[10000];
int N;

int main(){
    cin>>N;
    P[0]=0;
    dp[0]=0;
    for(int i=1;i<N+1;i++){
        cin>>P[i];
    }
    int max;
    for(int i=1;i<=N;i++){
        max=-1;
        for(int j=0;j<=i;j++){
            // cout<<dp[j]<<"+"<<P[i-j]<<endl;
            int tmp=dp[j]+P[i-j];
            if(tmp>max){
                max=tmp;
            }
        }
        // cout<<"MAX:"<<max<<endl;
        dp[i]=max;
    }
    // for(int i=0;i<N;i++){
    //     cout<<":"<<i<<":";
    // }
    cout<<dp[N];
}