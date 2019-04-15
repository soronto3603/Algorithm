// 퇴사2
// https://www.acmicpc.net/problem/15486
#include<iostream>
using namespace std;

int N;
int P[2000000];
int T[2000000];
int dp[2000000];

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin >> T[i] >> P[i];
    }
    P[0]=0;
    T[0]=0;
    dp[0]=0;
    for(int date=1;date<=N;date++){
        if(date + T[date] -1 > N){
            dp[date]=0;
            continue;
        } 
        int big=0;

        for(int j=date-50;j<date;j++){
            if(j<0)continue;

            if( j+T[j]-1 < date && big < dp[j] ) big = dp[j];
        }

    
        dp[date]=big + P[date];
        
        
    }
    // for(int i=0;i<=N;i++){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(int i=0;i<=N;i++){
    //     cout << T[i] << " ";
    // }
    // cout << endl;
    // for(int i=0;i<=N;i++){
    //     cout << P[i] << " ";
    // }
    // cout << endl;
    // for(int i=0;i<=N;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    int big = 0;
    for(int i=0;i<=N;i++){
        if(dp[i]>big)big=dp[i];
    }
    cout << big;
    return 0;
}