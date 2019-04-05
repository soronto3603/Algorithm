// 일곱 난쟁이
// https://www.acmicpc.net/problem/2309

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int people[9];
    for(int i=0;i<9;i++){
        cin >> people[i];
    }
    sort(people,people+9);
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            int sum=0;
            for(int k=0;k<9;k++){
                if(k==i || k==j){
                    continue;
                }else{
                    sum+=people[k];
                }
            }
            if(sum<=100){
                for(int k=0;k<9;k++){
                    if(k==i || k==j){
                        continue;
                    }else{
                        cout << people[k] << "\n";
                    }
                }
                i=9;
                j=9;
            }
        }
    }
    return 0;
}