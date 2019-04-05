#include<iostream>
#include<algorithm>

using namespace std;

int N,M;

int arr[10];
bool visit[10] = {false ,};

int rep[10];

void dfs(int cnt){
    if(cnt == M){
        for(int i=0;i<M;i++){
            cout << rep[arr[i]-1];
            if( i == N-1){

            }else cout << " ";
        }
        cout << "\n";
    }else{
        for(int i=1;i<=N;i++){
            if( visit[i] == false ){
                visit[i] = true;
                arr[cnt] = i;
                dfs(cnt+1);
                visit[i] = false; 
            }
        }
    }
}

int main(){
    cin>>N;
    cin>>M;
   
    for(int i=0;i<N;i++){
        cin>>rep[i];
    }   
    sort(rep,rep + N);

    dfs(0);
}