#include<iostream>
#include<vector>

using namespace std;

int N,M;

int arr[10];
bool visit[10] = {false ,};

void dfs(int cnt){
    if(cnt == M){
        for(int i=0;i<M;i++){
            cout << arr[i];
            if( i == N-1){

            }else cout << " ";
        }
        cout << "\n";
    }else{
        for(int i=1;i<=N;i++){

            // if( visit[i] == false ){
                // visit[i] = true;
            if( arr[cnt-1] <= i ){
                arr[cnt] = i;
                dfs(cnt+1);
            }
                // visit[i] = false; 
            // }
        }
    }
}

int main(){
    cin>>N;
    cin>>M;
   
    dfs(0);
}