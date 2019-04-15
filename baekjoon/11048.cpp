// 이동하기
// https://www.acmicpc.net/problem/11048

#include<iostream>
using namespace std;

int map[1001][1001];
int dp[1001][1001];
int N,M;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    dp[0][0]=map[0][0];
    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            if(r==0&&c==0)continue;

            int x1 =0;
            int x2 =0;

            if(r-1 >= 0)x1=dp[r-1][c];
            if(c-1 >= 0)x2=dp[r][c-1];

            if( x1 > x2 ){
                dp[r][c] = map[r][c] + x1;
            }else{
                dp[r][c] = map[r][c] + x2;
            }
            
        }
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << dp[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N-1][M-1];
    return 0;
}