#include<iostream>


using namespace std; 

int dp[100];
int bag[100][2];

int main(){

    int N;
    cin>>N;
    bag[0][0]=0;
    bag[0][1]=0;
    for(int i=1;i<=N;i++){
        cin>>bag[i][0];
        cin>>bag[i][1];
    }
    int C;
    cin>>C;
    dp[0]=0;
    for(int i=1;i<=N;i++){
        int max_local=0;
        // cout<<"-----------------"<<endl;
        for(int j=0;j<i;j++){
            // cout<<"PRICE{bag[i]:"<<bag[i][1]<<" <> bag[j]:"<<bag[j][1]<<"}";
            // cout<<"GRAM{bag[i]:"<<bag[i][0]<<" <> bag[j]:"<<bag[j][0]<<"}"<<endl;
            // cout<<"PRICE{bag[i]+bag[j]:"<<bag[i][1]+bag[j][1]<<" <> max:" << max_local<<"}";
            // cout<<"GRAM{bag[i]+bag[j]:"<<bag[i][0]+bag[i][0]<<" <> C:"<<C<<"}";
            if(bag[i][0]+bag[j][0]<=C && max_local <= bag[i][1]+bag[j][1]){
                
                max_local=bag[i][1]+bag[j][1];
            }
            // cout<<endl;
        }
        dp[i]=max_local;
    }
    int max_r=0;
    for(int i=0;i<=N;i++){
        if(max_r<dp[i]){
            max_r=dp[i];
        }
        cout<<dp[i]<<endl;
    }
    cout<<max_r;
}