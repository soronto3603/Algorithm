#include<iostream>
#include<string>

using namespace std;

int main(){
    string sentence;
    cin>>sentence;
    string answer;
    if(sentence[0]>='a' && sentence[0]<='z'){
        char target=sentence[0];
        for(int i=1;i<sentence.size();i++){
            if(target==sentence[i]){
                sentence.erase(i,1);
            }
        }
        sentence.erase(0,1);
    }
    if(sentence[sentence.size()-1]>='a'&&sentence[sentence.size()]<='z'){
        char target=sentence[sentence.size()-1];
        for(int i=1;i<sentence.size();i++){
            if(target==sentence[i]){
                sentence.erase(i,1);
            }
        }
        sentence.erase(0,sentence.size()-1);
    }
}