// 최대공약수와 최소공배수
// https://www.acmicpc.net/problem/2609

#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        // cout << a <<endl;
        return a;
    }else{
        // cout << b << ","<<a%b<<endl;
        return gcd(b,a%b);
    }
    // return 0;
}
int l(int a,int b){
    int g=gcd(a,b);
    return g*(a/g)*(b/g);
}



int main(){
    int a,b;
    cin>>a;
    cin>>b;
    cout << gcd(a,b) << endl;
    cout << l(a,b);
}