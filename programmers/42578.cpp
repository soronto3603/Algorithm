#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){

    // vector< vector<string> > clothes={{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    // output : 5
    vector< vector<string> > clothes={{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}};
    // output : 3

    map<string,int> m;
    vector<string> key;

    for( int i=0;i<clothes.size();i++){
        if(m[clothes[i][1]]==0){
            m[clothes[i][1]]=1;
            key.push_back(clothes[i][1]);
        }else{
            m[clothes[i][1]]++;
        }
    }
    int result=1;
    for(int i=0;i<key.size();i++){
        result *= (m[key[i]] + 1);
    }
    cout << result-1;



    // vector< map<string,string> > m_list;

    // for( int i=0;i<clothes.size();i++ ){
    //     map<string,string> t;
    //     t[clothes[i][1]]=clothes[i][0];
    //     m_list.push_back(t);
    //     if( i > 0 ){
    //         for(int j=0;j<m_list.size();j++){
    //             if( m_list[j][clothes[i][1]] == "" ){
    //                 map<string,string> t2;
    //                 t2=m_list[j];
    //                 t2[clothes[i][1]]=clothes[i][0];
    //                 m_list.push_back(t2);
    //             }
    //         }
    //     }
    //     // cout << "["<< i<<"] : "<<m_list.size()<<endl;   
    // }

    return 0;
}

// 프로그래머스 실제 코드
// #include <string>
// #include <vector>
// #include<iostream>
// #include<map>

// using namespace std;

// int solution(vector<vector<string>> clothes) {
//     map<string,int> m;
//     vector<string> key;

//     for( int i=0;i<clothes.size();i++){
//         if(m[clothes[i][1]]==0){
//             m[clothes[i][1]]=1;
//             key.push_back(clothes[i][1]);
//         }else{
//             m[clothes[i][1]]++;
//         }
//     }
//     int result=1;
//     for(int i=0;i<key.size();i++){
//         result *= (m[key[i]] + 1);
//     }
//     return result-1;
// }