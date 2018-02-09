#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

struct pos{
    int y,x,lev;
};

queue<pos> q;
int map[201][201];
int visit[201][201]={0,};
int dir[][2]={{0,1},{1,0},{-1,0},{0,-1}};
int max_r=0x7fffffff;
  pos dest;
int main(){
  

    cin>>dest.y>>dest.x;
    for(int i=0;i<dest.y;i++){
        for(int j=0;j<dest.x;j++){
            scanf("%1d",&map[i][j]);
        }
    }

    q.push({0,0,1});
    while(!q.empty()){
        
        pos cur=q.front();
        q.pop();

        visit[cur.y][cur.x]=1;
        if(cur.x==dest.x-1&&cur.y==dest.y-1){
            if(cur.lev<max_r)max_r=cur.lev;
        }
        for(int i=0;i<4;i++){
            pos new_cur;
            new_cur.x=cur.x+dir[i][1];
            new_cur.y=cur.y+dir[i][0];
            new_cur.lev=cur.lev+1;

            if(new_cur.x<0||new_cur.y<0||new_cur.x>=dest.x||new_cur.y>=dest.y){
                continue;
            }

            if(visit[new_cur.y][new_cur.x]==1){
                continue;
            }
            if(map[new_cur.y][new_cur.x]==1){
                q.push({new_cur.y,new_cur.x,new_cur.lev});
            }

            
        }
    }
    cout<<max_r;
    return 0;
}