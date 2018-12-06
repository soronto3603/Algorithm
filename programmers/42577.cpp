#include<iostream>
#include<vector>

using namespace std;

int main(){
    // vector<string> phone_book={"119", "97674223", "1195524421"};
    // false
    // vector<string> phone_book={"123","456","789"};
    // true
    vector<string> phone_book={"12","123","1235","567","88"};
    // false

    sort(phone_book.begin(),phone_book.end());

    for( int i=0  ; i<phone_book.size() ; i++ ){
        for( int j=0 ; j<i ; j++){
            if( phone_book[i].find(phone_book[j]) == 0 && j != i ){
                cout << "false";
                return 0;
            }
        }
    }
    cout << "true";
    return 0;
}

// 프로그래머스 실제 코드
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// bool solution(vector<string> phone_book) {
//     sort(phone_book.begin(),phone_book.end());

//     for( int i=0  ; i<phone_book.size() ; i++ ){
//         for( int j=0 ; j<i ; j++){
//             if( phone_book[i].find(phone_book[j]) == 0 && j != i ){
//                 cout << "false";
//                 return false;
//             }
//         }
//     }
//     cout << "true";
//     return true;
// }