#include<iostream>
#include<stack>

using namespace std;

int getPriority(int b){
    if( b == '(' ) return 3;
    else if( b == '+' || b == '-') return 1;
    else if( b == '*' || b == '/') return 2;
    else if( b == ')') return 0;
    else return -1;
}

// 1. 피연산자인 경우 출력버퍼에 넣어준다.
// 2. 여는 괄호 ( 를 만나면 스택에 PUSH
// 3. 닫는 괄호 ) 를 만나면 ( 를 만날때까지 POP하여 출력버퍼로
// 4. 연산자 + , - , * , / 를 만나면
// 4-1. 스택이 비었거나
//      top이 여는 괄호 ( 
//      이번 연산자가 top보다 높은 순위이면
//      스택에 PUSH
// 4-2. 위의 경우가 아니라면, 위의 경우를 만족할때까지 스택에 POP하여 출력버퍼에 추가해둔다.
// 5. 모든 순회가 끝나면 스택의 나머지 연산자들을 출력

int main(){
    int q;

    string d;
    cin>>d;

    stack<char> s;
    
    for(int i=0;i<d.size();i++){
        char newChar=d[i];
        // 1. 피연산자인 경우 출력버퍼에 넣어준다.
        if( newChar >= 'A' && newChar <= 'Z' ){
            cout << newChar;
        }
        // 2. 여는 괄호 ( 를 만나면 스택에 PUSH
        else if( newChar == '(' ){
            s.push( newChar );
        }
        // 3. 닫는 괄호 ) 를 만나면 ( 를 만날때까지 POP하여 출력버퍼로
        else if( newChar == ')' ){
            while( s.top() != '(' ){
                cout << s.top();
                s.pop();
            }
            // 닫는 괄호 '(' POP 단 출력하지 않음
            s.pop();
        }
        // 4. 연산자 + , - , * , / 를 만나면
        else if( newChar == '+' || newChar == '-' || newChar == '*' || newChar == '/'){
            while(true){
                // 4-1. 스택이 비었거나
                //      top이 여는 괄호 ( 
                //      이번 연산자가 top보다 높은 순위이면
                if( s.size() == 0 || s.top() == '(' || getPriority(s.top()) < getPriority(newChar) ){
                    //      스택에 PUSH
                    s.push( newChar );
                    break;
                }
                // 4-2. 위의 경우가 아니라면, 위의 경우를 만족할때까지 스택에 POP하여 출력버퍼에 추가해둔다.
                else{
                    cout << s.top();
                    s.pop();
                }
            }
        }
    }
    // 5. 모든 순회가 끝나면 스택의 나머지 연산자들을 출력
    while(s.size()!=0){
        cout << s.top();
        s.pop();
    }
    return 0;
}