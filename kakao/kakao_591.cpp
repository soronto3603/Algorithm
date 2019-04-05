#include<vector>
#include<iostream>
#include<queue>

using namespace std;
struct pos{
    int y,x;
};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int> > visit;
    vector<int> visit_row;
    visit_row.assign(n,0);
    visit.assign(m,visit_row);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(picture[i][j]!=0&&visit[i][j]==0){
                //result_1
                number_of_area++;

                int now_sign=picture[i][j];
                queue<pos> q;
                q.push({i,j});
                int count=-1;
                while(!q.empty()){
                    pos cur=q.front();
                    q.pop();
                    //result_2_comapare_data
                    count++;
                    //result_2
                    if(count>max_size_of_one_area){
                        max_size_of_one_area=count;
                    }
                    // cout<<"current cur"<<cur.x<<" "<<cur.y<<" count"<<count++<<" "<<max_size_of_one_area<<endl;
                    for(int k=0;k<4;k++){
                        pos new_cur;
                        new_cur.x=cur.x+dir[k][0];
                        new_cur.y=cur.y+dir[k][1];
                        if(new_cur.x<0 || new_cur.y<0 ||new_cur.x>=n||new_cur.y>=m){
                            continue;
                        }
                        if(visit[new_cur.y][new_cur.x]==1){
                            continue;
                        }
                        if(picture[new_cur.y][new_cur.x]==now_sign){
                            visit[new_cur.y][new_cur.x]=1;
                            q.push(new_cur);
                        }
                    }
                }
                // cout<<"while end"<<endl;
                
            
            }
        }

    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<visit[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){
    vector<vector<int> > pic;
    int m,n;
    cin>>m;
    cin>>n;
    for(int i=0;i<m;i++){
        vector<int> row;
        row.clear();
        for(int j=0;j<n;j++){
            
            int ele;
            cin>>ele;
            row.push_back(ele);
        }
        pic.push_back(row);
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<pic[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    vector<int> result=solution(m,n,pic);
    cout<<result[0]<<" "<<result[1];
}
