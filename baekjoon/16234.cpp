// 인구 이동
// https://www.acmicpc.net/problem/16234

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <cmath>
// using namespace std;

// int N,L,R;

// int check[51][51];
// int map[51][51];

// int dx[] = {-1,1,0,0};
// int dy[] = {0,0,1,-1};

// int main(){
//     cin >> N >> L >> R;
    
//     for(int i=0;i<N;i++){
//         for(int j=0;j<N;j++){
//             cin >> map[i][j];
//             check[i][j]=-1;
//         }
//     }

//     queue< vector<int> > q;
//     for(int i=0;i<N;i++){
//         for(int j=0;j<N;j++){
//             if(check[i][j]==-1){
//                 q.push({i,j});
//                 while(!q.empty()){
//                     auto x = q.front(); q.pop();
//                     for(int dir=0;dir<4;dir++){
//                         int nx=dx[dir]+x[1];
//                         int ny=dx[dir]+x[0];

//                         if(nx<0 || nx>=N || ny<0 || ny>=N)continue;
                        
//                         int g = abs(map[ny][nx] - map[x[0]][x[1]]);
//                         if( g < R && g > L){
//                             check[ny][nx]=1;
//                             q.push({ny,nx});
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

#include<iostream>
#include<stack>
#include<tuple>
#include<vector>
#include<queue>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool bfs(vector<vector<int>> &a, int l,int r){
    int n = a.size();
    vector<vector<bool>> c(n, vector<bool>(n, false));
    bool ok = false;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c[i][j] == false){
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                c[i][j] = true;
                stack<pair<int,int>> s;
                s.push(make_pair(i,j));
                int sum = a[i][j];
                while(!q.empty()){
                    int x,y;
                    tie(x,y) = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if( 0 <= nx && nx < n && 0 <= ny && ny < n ){
                            if(c[nx][ny])continue;
                            int diff = a[nx][ny] - a[x][y];
                            if(diff < 0) diff = -diff;
                            if( l <= diff && diff <=r ){
                                q.push(make_pair(nx,ny));
                                s.push(make_pair(nx,ny));
                                c[nx][ny] = true;
                                ok = true;
                                sum += a[nx][ny];
                            }
                        }
                    }
                }
                int val = sum / s.size();
                while(!s.empty()){
                    int x,y;
                    tie(x,y) = s.top();
                    s.pop();
                    a[x][y] = val;
                }
            }
        }
    }
    return ok;
}
int main(){
    int n,l,r;
    cin >> n >> l >> r;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    while(true){
        if(bfs(a,l,r)){
            ans+=1;
        }else{
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}