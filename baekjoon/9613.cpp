#include<iostream>

using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int l(int a,int b){
    int g = gcd(a,b);
    return a*b/g;
}

int max(int a,int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}
int min(int a,int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int N,M;
    int t[100];

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> M;
        for(int j=0;j<M;j++){
            cin >> t[j];
        }
        long long sum = 0;
        for(int j=0;j<M;j++){
            for(int k=j+1;k<M;k++){
                // cout << j << ", "<< k <<endl;
                sum+=gcd(max(t[j],t[k]),min(t[j],t[k]));
            }
        }
        cout << sum << endl;
    }
    return 0;
}