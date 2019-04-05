// 구슬 탈출2
// https://www.acmicpc.net/problem/13460

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector< vector<char> > map;
// N줄 M길이
int N,M;
int result=0;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
queue<vector<int>> Q;

// n은 차수, 부모 노드의 값
void bfs(int n,vector<int> pos){
    if( n > 10){
        result=-1;
        return;
    }else{
        for(int x=0;x<4;x++){            
            int cur_red_X = pos[1];
            int cur_red_Y = pos[0];

            int cur_blue_X = pos[3];
            int cur_blue_Y = pos[2];
            
            map[cur_red_Y][cur_red_X]='R';
            map[cur_blue_Y][cur_blue_X]='B';

            while(true){
                int next_red_X = pos[1]+dir[x][1];
                int next_red_Y = pos[0]+dir[x][0];

                int next_blue_X = pos[3]+dir[x][1];
                int next_blue_Y = pos[2]+dir[x][0];
                if( map[next_red_Y][next_red_X] == '#' || map[next_red_Y][next_red_X] == 'B'){
                    
                }else if( map[next_red_Y][next_red_X] == '0' ){
                    result=n+1;
                    break;
                }else{
                    map[cur_red_Y][cur_red_X]='.';
                    map[next_red_Y][next_red_X]='R';
                    
                }
                if(map[next_blue_Y][next_red_X] == '#' || map[next_red_Y][next_red_X] == 'R'){

                }else if( map[next_blue_Y][next_blue_X] == '0' ){
                    result=-1;
                    break;
                }
            }
            
        }
    }
}

int main(){
    cin>>N;
    cin>>M;

    vector<int> pos(4);

    for(int i=0;i<N;i++){
        vector<char> row;
        for(int j=0;j<M;j++){
            char t;
            cin>>t;
            row.push_back(t);
            if( t == 'R' ){
                pos[0]=i;
                pos[1]=j;
            }else if(t == 'B'){
                pos[2]=i;
                pos[3]=j;
            }
        }
        map.push_back(row);
    }
    map[pos[1]][pos[0]]='.';
    map[pos[3]][pos[2]]='.';
    Q.push(pos);
    bfs(0,pos);
    // display
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << pos[0] << "," << pos[1] << "," << pos[2] << "," << pos[3] << endl;
    return 0;
}