// 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int nexta[101];
int dist[101];

int N,M,x,y,u,v;

int main(){
    cin >> N >> M;
    for(int i=0;i<101;i++){
        dist[i]=-1;
        nexta[i]=i;
    }
    for(int i=0;i<N;i++){
        cin >> x >> y;
        nexta[x]=y;
    }
    for(int i=0;i<M;i++){
        cin >> u >> v;
        nexta[u]=v;
    }
    dist[1]=0;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int now=q.front();
        q.pop();

        for(int i=0;i<6;i++){
            int y = now+i+1;
            if(y > 100)continue;
            y=nexta[y];
            if(dist[y] == -1){
                dist[y] = dist[now] + 1;
                q.push(y);
            }
        }
    }
    cout << dist[100] << '\n';
    return 0;
}