#include<iostream>
#include<string>

using namespace std;

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int num=0;
void dfs(int nums,int i){
    //cout<<nums<<endl;
    if(i==num){
        if(isPrime(nums)){
            cout<<nums<<endl;
        }
        return;
    }
    if(!isPrime(nums)&&nums!=0){
        return;
    }
    nums*=10;
    for(int j=1;j<=9;j++){
        dfs(nums+j,i+1);
    }
    
}

int main(){
    
    cin>>num;
    int a=0;
    dfs(a,0);
    return 0;
}