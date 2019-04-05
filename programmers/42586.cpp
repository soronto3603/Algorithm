#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> progresses={93,30,55};
    vector<int> speeds={1,30,5};
    // 2,1

    int complete_index=0;
    int size=progresses.size();
    while(true){
        // 배포 완료된 인덱스가 전체 배열을 넘어서면
        if( complete_index > size-1 ){
            break;
        }
        // 현재 맨앞의 작업이 100 이상이 되었으면
        else if( progresses[complete_index] >= 100 ){
            int completed_work=0;
            for(int i=complete_index;i<size;i++){
                if( progresses )
            }
        }
        // 작업이 완료되지 않았으면 모든 작업 각자의 스피드로 진행
        else{
            for(int i=complete_index;i<size;i++){
                progresses[i] += speeds[i];
            }
        }
    }
        // 배포
        if( progresses[complete_index]  >= 100 ){

        }

        else{
            for(int j=i;j<)
        }
    }    
    return 0;
}