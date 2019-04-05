#include<iostream>
#include<vector>

int dp[1001][1001]={0,};

using namespace std;

int main(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    int ans=0;
    for(int i=1;i<a.size();i++){
        for(int j=1;j<b.size();j++){
            if(a.at(i)==b.at(j)){
                dp[i][j]=dp[i-1][i-j]+1;

            }
            if(ans<dp[i][j]){
                ans=dp[i][j];
            }
        }
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans;
}