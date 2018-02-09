#include<iostream>
#include<vector>
#include<queue>

#define DDDD vector<int>

using namespace std;
struct pos{
    int x,y;
};
int dir[][2]={{0,1},{1,0},{-1,0},{0,-1}};
int visit[101][101]={0,};
DDDD solution(int m, int n, vector<DDDD> picture) {
    queue<pos>bfs;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    bfs.push({0,0});

    while(!bfs.empty()){
        pos cur=bfs.front();
        bfs.pop();
        
//         if(cur.x==dest.x-1&&cur.y==dest.y-1){

//         }
        if(picture.at(cur.y).at(cur.x)>0){
            int area_number=picture.at(cur.y).at(cur.x);
            number_of_area++;
            queue<pos>ff;
            ff.push({cur.y,cur.x});
            int count=0;
            while(!ff.empty()){
                pos ff_cur=ff.front();
                ff.pop();
                for(int i=0;i<4;i++){
                    pos ff_new_cur;
                    ff_new_cur.x=ff_cur.x+dir[i][1];
                    ff_new_cur.y=ff_cur.y+dir[i][0];
                    if(picture.at(ff_new_cur.y).at(ff_new_cur.x)!=area_number){
                        continue;
                    }
                    if(ff_new_cur.x<0||ff_new_cur.y<0||ff_new_cur.x>=m||ff_new_cur.y>=n){
                        continue;
                    }
                    if(picture.at(ff_new_cur.y).at(ff_new_cur.x)==area_number){

                        ff.push({ff_new_cur.y,ff_new_cur.x});
                        count++;
                    }
                }
            }
            if(max_size_of_one_area<count){
                max_size_of_one_area=count;
            }
        }
        for(int i=0;i<4;i++){
            pos new_cur;
            new_cur.x=cur.x+dir[i][1];
            new_cur.y=cur.y+dir[i][0];
            if(new_cur.x<0||new_cur.y<0||new_cur.x>=m||new_cur.y>=n){
                continue;
            }

            if(visit[new_cur.y][new_cur.x]==1){
                continue;
            }
            if(picture.at(new_cur.y).at(new_cur.x)==1){
                visit[new_cur.y][new_cur.x]=1;
                bfs.push({new_cur.y,new_cur.x});
            }
        }
        
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main(){
    vector<DDDD>pic={{1,1,1,0},{1,1,1,0},{0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,1}};
    vector<int> a;
    a=solution(6,4,pic);
    cout<<a[0]<<" "<<a[1]<<endl;

}