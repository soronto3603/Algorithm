#include<iostream>
#include<vector>

using namespace std;

int MOD = 20170805;

struct node{
    int left,top;
};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int> > city_map) {
    int answer = 0;
    vector<vector<node> >dp(m,vector<node>(n));
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<city_map[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout <<dp[i][j].left<<"/"<<dp[i][j].top<<"\t";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int top,left=0;

            if(city_map[i][j]==1){
                dp[i][j].left=0;
                dp[i][j].top=0;
                continue;    
            }
            // cout<<"dp["<<i<<"]["<<j<<"]=";
            if(i==0){
                top=0;
            }else if(city_map[i-1][j]==0){
                // cout<<"!!0!!";
                top=dp[i-1][j].left+dp[i-1][j].top;
            }else if(city_map[i-1][j]==2){
                // cout<<"!!2!!";
                top=dp[i-1][j].top;
            }
            if(j==0){
                left=0;
            }else if(city_map[i][j-1]==0){
                // cout<<"!!0!!";
                left=dp[i][j-1].left+dp[i][j-1].top;
            }else if(city_map[i][j-1]==2){
                // cout<<"!!2!!";
                left=dp[i][j-1].left;
            }
            
            if(i==1&&j==0){
                top=1;
            }else if(i==0&&j==1){
                left=1;
            }
            // cout <<left<<"/"<<top<<"\t";
            // cout<<endl;
            dp[i][j].top=top;
            dp[i][j].left=left;
        }
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout <<dp[i][j].left<<"/"<<dp[i][j].top<<"\t";
    //     }
    //     cout<<endl;
    // }
    answer=(dp[m-1][n-1].left+dp[m-1][n-1].top)/MOD;
    return answer;
}

int main(){
    int m,n;
    cin>>m;
    cin>>n;
    vector<vector<int> >city_map;
    for(int i=0;i<m;i++){
        vector<int> row;
        row.clear();
        for(int j=0;j<n;j++){
            int row_input;
            cin>>row_input;
            row.push_back(row_input);
        }
        city_map.push_back(row);
    }
    solution(m,n,city_map);
}