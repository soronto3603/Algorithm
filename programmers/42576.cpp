#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main(){
    // input 1 :
    // vector<string> pt={"leo","kiki","eden"};
    // vector<string> comp={"eden","kiki"};
    // output : "leo"
    // input 2
    vector<string> pt={"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> comp={"josipa", "filipa", "marina", "nikola"};
    // output : "binko"
    // vector<string> pt={"mislav", "stanko", "mislav", "ana"};
    // vector<string> comp={"stanko", "ana", "mislav"};
    // output : "mislav"
    
    
    map<string, int> m;
    // 1. 맵에 집어 넣기
    for( auto x : pt ){
        // cout << x << " : "<<m[x]<<endl;
        // 1.1 처음 넣는 것은 1 삽입
        if( m[x] == false ){
            m[x] = 1;
        }
        //  1.2 중복된 것은 +1 증가
        else if( m[x] > 0){
            m[x]++;
        }
    }
    // 2. comp를 map에 넣어보면서 -1씩 하기
    for( auto x : comp ){
        // 2.1 map[comp] 가 false라면 없는 것으로 해당 결과 출력
        if( m[x] == false ){
            cout << x;
            return 0;
        }
        // 2.2 map[comp] 가 0이상이라면 하나씩 뺌
        else if( m[x] > 0 ){
            m[x]--;
        }
    }
    // 3. map을 돌면서 0이 아닌 것 출력
    for( auto x : pt ){
        if( m[x] != 0 ){
            cout << x;
            return 0;
        }
    }
    return 0;
}
// 실제 프로그래머스 코드
// #include <string>
// #include <vector>
// #include <map>
// #include <iostream>

// using namespace std;

// string solution(vector<string> participant, vector<string> completion) {
//     string answer = "";
//     map<string, int> m;
//     // 1. 맵에 집어 넣기
//     for( auto x : participant ){
//         // cout << x << " : "<<m[x]<<endl;
//         // 1.1 처음 넣는 것은 1 삽입
//         if( m[x] == false ){
//             m[x] = 1;
//         }
//         //  1.2 중복된 것은 +1 증가
//         else if( m[x] > 0){
//             m[x]++;
//         }
//     }
//     // 2. comp를 map에 넣어보면서 -1씩 하기
//     for( auto x : completion ){
//         // 2.1 map[comp] 가 false라면 없는 것으로 해당 결과 출력
//         if( m[x] == false ){
//             cout << x;
//             return x;
//         }
//         // 2.2 map[comp] 가 0이상이라면 하나씩 뺌
//         else if( m[x] > 0 ){
//             m[x]--;
//         }
//     }
//     // 3. map을 돌면서 0이 아닌 것 출력
//     for( auto x : participant ){
//         if( m[x] != 0 ){
//             cout << x;
//             return x;
//         }
//     }
//     return "";
// }