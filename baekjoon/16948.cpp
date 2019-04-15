// 데스 나이트
// https://www.acmicpc.net/problem/16948

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int dy[6] = {-2,-2,0,0,2,2};
int dx[6] = {-1,1,-2,2,-1,1};
// (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)

int N,r1,r2,c1,c2;

int dist[201][201];


int main(){
    for(int i=0;i<201;i++){
        for(int j=0;j<201;j++){
            dist[i][j]=-1;
        }
    }
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;
    dist[r1][c1] = 0;
    queue< vector<int> > q;
    
    q.push({r1,c1});
    while(!q.empty()){
        
        auto x = q.front(); q.pop();
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++){
        //         cout << dist[i][j] << "  ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        for(int i=0;i<6;i++){
            
            int ny = x[0] + dy[i];
            int nx = x[1] + dx[i];

            if(ny<0 || ny >= N || nx <0 || nx >= N) continue;

            if( dist[ny][nx] == -1 ){
                // cout << nx<<","<<ny<<","<<dist[ny][nx] << "\n";
                dist[ny][nx] = dist[x[0]][x[1]] + 1;
                q.push({ny,nx});
            }
        }
    }
    cout << dist[r2][c2];
}

// #include<iostream>
// #include<tuple>
// #include<cstring>
// #include<queue>

// using namespace std;
// int dx[] = {-2,-2,0,0,2,2};
// int dy[] = {-1,1,-2,2,-1,1};
// int dist[200][200];
// int main(){
//     int n;
//     cin>>n;
//     int sx,sy,ex,ey;
//     cin>>sx>>sy>>ex>>ey;
//     memset(dist,-1)
// }