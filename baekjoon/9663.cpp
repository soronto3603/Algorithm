// N-Queen
// https://www.acmicpc.net/problem/9663

#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

int N;
int map[20];
int result=0;

bool isPossible(int c){    
    for(int i = 1 ; i < c ;i++){

        // 로우가 같은가
        if( map[c] == map[i] ){
            return false;
        }
        // 대각선이 같은가
        if(  abs(map[i] - map[c] ) == abs( i  -  c ) ){
            return false;
        }
    }
    return true;
}

void dfs(int row){
    // cout << map[row] << endl;
    if(row == N){
        result++;
    }else{
        for(int i=1;i<=N;i++){
            // cout << "  " << i << ":" << isPossible(row+1) << endl;
            map[row+1] = i;
            if( isPossible(row+1) ){
                dfs(row+1);
            }else{
                map[row+1] = 0;
            }
        }
    }
    map[row] = 0;
}

int main(){
    cin >> N;
    
    for(int i=1;i<=N;i++){
        map[1] = i;
        dfs(1);
    }
    cout << result;

    return 0;
}
