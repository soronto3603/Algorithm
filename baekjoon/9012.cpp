#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int s=0;
        int result=1;
        string ps;
        cin>>ps;
        for(int j=0;j<ps.length();j++){
            if(ps[j]=='('){
                s++;
            }else if(ps[j]==')'){
                if(s!=0){
                    s--;
                }else{
                    result=0;
                    break;
                }
            }
        }
        if(s!=0){
            result=0;
        }
        if(result==0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}