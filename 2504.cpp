#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int getPoint(char c){
    // ( ) 이면 2점 아니면 3점 == { }
    return ( c == '(' || c == ')' ) ? 2 : 3; 
}

// 1. 데이터 리스트를 탐색하다가 ( ) { } 인 경우
//  1.1 뒤의 괄호를 체크한다 여는괄호 몇개 닫는 괄호 몇개인지
//  1.2 여는괄호에서 닫는괄호를 뺀 나머지로 계산 ( 몇개의 괄호가 열려 있는지 )


int main(){
    string input;
    cin>>input;

    vector< vector<int> > v;
    // cout << input[0] <<", ";
    v.push_back(vector<int>(2,0));
    if( input[0] == '(' ) v[0][0]++;
    else if( input[0] == ')') v[0][0]--;
    else if( input[0] == '[') v[0][1]++;
    else if( input[0] == ']') v[0][1]--;
    // cout << v[0][0] << ", " << v[0][1] << endl;

    // 0. result=0
    int result = 0;
    for( int i=1; i < input.size() ; i++ ){
        char post_c = input[i-1];
        char cur_c = input[i];

        // cout << cur_c << ", ";
        v.push_back(vector<int>(2,0));
        if( cur_c == '(' ){
            v[i][0]=v[i-1][0]+1;
            v[i][1]=v[i-1][1];
        } 
        else if( cur_c == ')'){
            v[i][0]=v[i-1][0]-1;
            v[i][1]=v[i-1][1];
        } 
        else if( cur_c == '['){
            v[i][1]=v[i-1][1]+1;
            v[i][0]=v[i-1][0];
        } 
        else if( cur_c == ']'){
            v[i][1]=v[i-1][1]-1;
            v[i][0]=v[i-1][0];
        } 
        // cout << v[i-1][0] << ", " << v[i-1][1] << " => ";
        // cout << v[i][0] << ", " << v[i][1] << endl;

        // 1. 데이터 리스트를 탐색하다가 ( ) { } 인 경우
        if( (post_c == '(' && cur_c == ')') || (post_c == '[' && cur_c == ']') ){
            // cout << "FIND" << i << endl;
            //  1.1 전의 괄호를 체크한다 여는괄호 몇개 닫는 괄호 몇개인지
            
            // cout << v[i][0] << ", " << v[i][1]<<endl;
            //  1.2 여는괄호에서 닫는괄호를 뺀 나머지로 계산 ( 몇개의 괄호가 열려 있는지 )
            int m_r=getPoint(post_c);
            for(int k=0;k<v[i][0];k++){
                m_r*=2;
            }
            for(int k=0;k<v[i][1];k++){
                m_r*=3;
            }
            // cout << "[" << m_r << "]" << endl;
            result += m_r;
        }
        
    }
    cout << result;
    
    
    return 0;
}