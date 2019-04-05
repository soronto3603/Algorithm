#include<iostream>
#include<vector>

using namespace std;

int main(){
    string s="try hello world";

    //TrY HeLlO WoRlD
    int t='a'-'A';
    int size=s.size();
    for(int i=0;i<size;i++){
        if( (s[i] >= 'a' && s[i] <= 'z') && i % 2 == 0 ){
            s[i]-=t;
        }else if((s[i] >= 'A' && s[i] <= 'Z') && i % 2 == 1){
            s[i]+=t;
        }else
        }
    }
    cout << s;
    return 0;
}