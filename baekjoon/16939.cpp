// 2x2x2x 큐브
// https://www.acmicpc.net/problem/16939

#include <iostream>
#include <vector>
using namespace std;
int n = 24;
bool check(vector<int> a){
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            if(a[i*4+1] != a[i*4+i+j+1]) return false;
        }
    }
    return true;
}

vector<int> lu(vector<int> a){
    int temp = a[1];
    a[1]=a[5];
    a[5]=a[9];
    
}