// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE
// 25년 간의 수행 끝에 원재는 미래를 보는 능력을 갖게 되었다. 이 능력으로 원재는 사재기를 하려고 한다.

// 다만 당국의 감시가 심해 한 번에 많은 양을 사재기 할 수 없다.

// 다음과 같은 조건 하에서 사재기를 하여 최대한의 이득을 얻도록 도와주자.

//     1. 원재는 연속된 N일 동안의 물건의 매매가를 예측하여 알고 있다.
//     2. 당국의 감시망에 걸리지 않기 위해 하루에 최대 1만큼 구입할 수 있다.
//     3. 판매는 얼마든지 할 수 있다.

// 예를 들어 3일 동안의 매매가가 1, 2, 3 이라면 처음 두 날에 원료를 구매하여 마지막 날에 팔면 3의 이익을 얻을 수 있다.


// [입력]

// 첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

// 각 테스트 케이스 별로 첫 줄에는 자연수 N(2 ≤ N ≤ 1,000,000)이 주어지고,

// 둘째 줄에는 각 날의 매매가를 나타내는 N개의 자연수들이 공백으로 구분되어 순서대로 주어진다.

// 각 날의 매매가는 10,000이하이다.


// [출력]

// 각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 최대 이익을 출력한다.

#include<iostream>

using namespace std;

long dealing_list[1000000];
long my_money[1000000];
long my_it[1000000];
int N,T;

int main(){
    cin >> T;
    for(int z=0;z<T;z++){
        cin >> N;
        dealing_list[0] = 0;
        my_money[0] = 0;
        my_it[0] = 0;
        for(int i=1;i<=N;i++){
            cin >> dealing_list[i];
        }
        
        // cout << "start test case" << endl;

        for(int i=1;i<=N;i++){
            bool arebig = true;
            for(int j=i+1;j<=N;j++){
                // 나보다 큰 것이 존재
                // cout <<j<<"."<< dealing_list[i] <<" < "<< dealing_list[j]<<endl ;
                if( dealing_list[i] < dealing_list[j] ){
                    arebig = false;
                    break;
                }
            }
             
            // 내가 제일 큼.
            if(arebig==true){
                my_money[i] = my_money[i-1] + my_it[i-1] * dealing_list[i];
                my_it[i] = 0;
                // cout << "arbig is true" << my_money[i]<<" ,"<<my_it[i] <<endl;
            }
            // 나보다 큰 것이 있음.
            else{
                my_money[i] = my_money[i-1] - 1 * dealing_list[i];
                my_it[i] = my_it[i-1] + 1; 
                // cout << "arbig is false" << my_money[i]<<" ,"<<my_it[i] <<endl;
            }
            
        }
        // for(int i=0;i<=N;i++){
        //     cout << i << "my_money : " << my_money[i] << endl;
        //     cout << i << "my_it : " << my_it[i] << endl;
        // }
        cout << "#" << z << " " << my_money[N] << endl;
    }

    return 0;
}