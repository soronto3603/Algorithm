#include<iostream>
#include<string>

using namespace std;

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    if((n&1)==0){
        return (n==2);
    }
    for(int i=3;i*i<=n;i++){
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
    if(i==10)return;
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