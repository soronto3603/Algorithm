// 소수 구하기
// https://www.acmicpc.net/problem/1929

#include<iostream>

using namespace std;

// int primes[1000001];
const int MAX = 1000000;
bool check[MAX+1];

int M,N;

int main(){
    // check[0]=true;
    // check[1]=true;    
    // for(int i=2;i*i<=n;i++){
    //     if(check[i]==false){
    //         for(int j=i+i;j<=n;j+=i){
    //             check[j]=true;
    //         }
    //     }
        
    // }
    check[0] = check[1] = true;
    for (int i=2; i*i<=MAX; i++) {
        if (check[i] == false) {
            for (int j=i+i; j<=MAX; j+=i) {
                check[j] = true;
            }
        }
    }
    int m, n;
    cin >> m; 
    cin >> n;
    for (int i=m; i<=n; i++) {
        if (check[i] == false) {
            cout << i << endl;
        }
    }
    //     cin>>M;
    // cin>>N;
    // for(int i=M;i<=N;i++){
    //     if(check[i] == false){
    //         cout << i << endl;
    //     }
    // }
}
