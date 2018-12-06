#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
    vector<string> genres={"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays={500, 600, 150, 800, 2500};

    vector<string> key;

    map<string, vector<int> > m;
    for(int i=0;i<genres.size();i++){
        // if( m[genres[i]] == 0 ){
        //     m[genres[i]]=plays[i];
        //     key.push_back(genres[i]);
        // }else{
        //     m[genres[i]]+=plays[i];
        // }
    } 

    return 0;
}