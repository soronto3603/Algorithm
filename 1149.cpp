#include<iostream>

using namespace std;

int dp[1000000]={0,};
int post_select=-1;
int now_rgb[3];

int main(){
    int N;
    int max=0xffffffff;
    int rgb[3];

    //rgb function test
    // rgb[0]=12;
    // rgb[1]=22;
    // rgb[2]=10;
    // cout<<rgb_middle(rgb);
    //cout<<max;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            cin>>now_rgb[j];
        }
        int select_index;
        if(rgb[0]<rgb[1]&&rgb[0]<rgb[1]){
            
        }


        dp[i]=dp[i-1]+now_rgb[select_index];
        cout<<"dp[i]=["<<dp[i-1]<<"]+["<<now_rgb[select_index]<<"]selectindex"<<select_index<<endl;
        post_select=select_index;
    }
    cout<<dp[N];
    
}